#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include "bintree_eda.h"

template <class T>
class extiendeArbol : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	extiendeArbol() : bintree<T>() {};
	extiendeArbol(extiendeArbol<T> const& l, T const& e, extiendeArbol<T> const& r) : bintree<T>(l, e, r) {}

	std::vector <T> devuelveFrontera()
	{
		std::stack <Link> pila;
		std::vector <T> v;
		frontera(v, this->raiz, pila);
		return v;
	}

private:
	void frontera(std::vector <T> &v, Link const& raiz, std::stack <Link> & pila)
	{
		if (raiz != nullptr)
		{
			if (raiz->left == nullptr && raiz->right == nullptr)
			{
				v.push_back(raiz->elem);
				if (!pila.empty())
				{
					Link sig = pila.top();
					pila.pop();
					frontera(v, sig, pila);
				}
			}
			else if (raiz->left != nullptr && raiz->right != nullptr)
			{
				pila.push(raiz->right);
				return frontera(v, raiz->left, pila);
			}
			else if (raiz->left == nullptr && raiz->right != nullptr)
				return frontera(v, raiz->right, pila);
			else
				return frontera(v, raiz->left, pila);
		}
	}
};

template <typename T>
inline extiendeArbol<T> leerArbol_ext(T vacio)
{
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) // es un árbol vacío
		return{};

	else
	{ // leer recursivamente los hijos
		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return{ iz, raiz, dr };
	}
}

void resuelveCaso()
{
	extiendeArbol<int> arbol;
	arbol = leerArbol_ext(-1);
	std::vector <int> v = arbol.devuelveFrontera();

	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}

	std::cout << '\n';
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}