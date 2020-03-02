// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include"bintree_eda.h"


// función que resuelve el problema
template<typename T>
int resolver(bintree<T> const & t, int &maximo,int &actual)
{
	if (t.empty())
		return 0;
	else if (t.left().empty() && t.right().empty()) {
		actual = 1;
		return actual;
	}
	else if (t.left().empty())
	{
		actual = 1 + resolver(t.right(), maximo,actual);
		return actual;
	}
	else if (t.right().empty())
	{
		actual = 1 + resolver(t.left(), maximo,actual);
		return actual;
	}
	else
	{
		int izq = resolver(t.left(), maximo, actual);
		int dcha = resolver(t.right(), maximo, actual);
		int aux = 1+izq+dcha;
		if (aux > maximo)
			maximo = aux;
		return 1 + std::max(izq, dcha);
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> t = leerArbol('.');
	int maximo = 0,actual=0;
	resolver(t, maximo,actual);
	if (actual > maximo)
		maximo = actual;
	std::cout << maximo << '\n';


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