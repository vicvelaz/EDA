
//Victor Velazquez Cabrera
//E68
//
//  conjunto.h
//



#ifndef conjunto_h
#define conjunto_h
#include <iostream>
#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <string>


template <class T>
class set {
public:
	set(size_t tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T> & operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	void insert(T e);
	bool contains(T e, int &pos) const;
	void erase(T e);
	bool empty() const;
	size_t size() const;
	T lowerElement() const;
	void eraseLowerElement();
	T * getDatos() {
		return datos;
	}
private:
	const static size_t TAM_INICIAL = 8;
	size_t contador;
	size_t capacidad;
	T * datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);
};

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
	libera();
}

template <class T>
void set<T>::libera() {
	delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
	int pos = 0;
	if (!contains(e, pos)) { // Puesto que contains ahora es una busqueda binaria, inserta ordenado
		if (contador == capacidad)
			amplia();
		for (int i = contador; i > pos; --i) {
			datos[i] = datos[i - 1];
		}
		datos[pos] = e;
		++contador;
	}
}

template <class T>
T set<T>::lowerElement()const {
	if (contador > 0) return datos[0];
	//else throw domain_error("No hay elementos");
}
template <class T>
void set<T>::eraseLowerElement() {
	if (contador > 0) {
		for (int i = 0; i < contador - 1; ++i) {
			datos[i] = datos[i + 1];
		}
		--contador;
	}
}

template <class T>
bool set<T>::contains(T e, int & pos) const { // Ademas de si está el elemento devuelve por referencia la posicion donde esta si lo encuentra
	int ini = 0, fin = contador - 1, mitad;
	bool encontrado = false;
	while (!encontrado && ini <= fin) {
		mitad = (ini + fin) / 2;
		if (datos[mitad] == e) {
			encontrado = true;
			pos = mitad;
		}
		else if (datos[mitad] < e) ini = mitad + 1;
		else fin = mitad - 1;
	}
	pos = ini;
	return encontrado;
}

template <class T>
void set<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	if (i < contador) {
		datos[i] = datos[contador - 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta");
}


template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
size_t set<T>::size() const {
	return contador;
}
template <class T>
inline std::ostream & operator <<(std::ostream & out, set<T> conjunto) {
	T* punt = conjunto.getDatos();
	for (int i = 0; i < conjunto.size(); ++i) {
		out << punt[i] << " ";
	}
	out << '\n';
	return out;
}

#endif // conjunto_h