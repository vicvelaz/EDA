//Victor Velazquez Cabrera
//E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


// función que resuelve el problema
template<typename T>
int rutas(bintree<T> const & t,int & numRutas)
{
	if (t.empty())
		return 0;
	else if (t.left().empty() && t.right().empty())
	{
		if (t.root() != 0)
		{
			++numRutas;
			return 1;
		}
		else
			return 0;
	}
	else if (t.left().empty())
	{
		int dcha = rutas(t.right(), numRutas);
		if (dcha == 0 && t.root() == 0)
			return 0;
		else if (dcha == 0 && t.root() != 0)
		{
			++numRutas;
			return 1;
		}
		else
			return 1;
	}
	else if (t.right().empty())
	{
		int izq = rutas(t.left(), numRutas);
		if (izq == 0 && t.root() == 0)
			return 0;
		else if (izq == 0 && t.root() != 0)
		{
			++numRutas;
			return 1;
		}
		else
			return 1;
	}

	else
	{
		int izq = rutas(t.left(), numRutas);
		int dcha = rutas(t.right(), numRutas);
		if (izq + dcha == 0 && t.root() != 0)
		{
			++numRutas;
			return 1;
		}
		else if (izq + dcha != 0)
			return 1;
		else
			return 0;
	}
}

template<typename T>
int excursionistas(bintree<T> const & t)
{
	if (t.empty())
		return 0;
	else if (t.left().empty() && t.right().empty())
		return t.root();
	else if (t.left().empty())
		return t.root() + excursionistas(t.right());
	else if (t.right().empty())
		return t.root() + excursionistas(t.left());
	else
		return t.root() + std::max(excursionistas(t.left()), excursionistas(t.right()));
}

void resuelveCaso() {
	// leer los datos de la entrada

	bintree<int> t = leerArbol(-1);
	int numRutas = 0;
	rutas(t, numRutas);
	std::cout << numRutas <<" "<<excursionistas(t)<< '\n';
	// escribir sol


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