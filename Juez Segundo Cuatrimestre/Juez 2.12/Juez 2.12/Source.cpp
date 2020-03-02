// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <fstream>
#include "deque_eda.h"

template<typename T>
using Nodo = typename deque<T>::Nodo;


bool resuelveCaso() {

	// leer los datos de la entrada

	int n, numSaltos;

	std::cin >> n >> numSaltos;


	if (!std::cin)  // fin de la entrada
		return false;

	if (n == 0 && numSaltos == 0)
		return false;

	deque<int> deque;
	int i = 1;
	while (i <= n) {
		deque.push_back(i);
		i++;
	}


	while (deque.size() > 1) {
		int i = 0;
		while (i < numSaltos) {
			int elem = deque.front();
			deque.push_back(elem);
			deque.pop_front();
			i++;
		}
		deque.pop_front();
	}


	// escribir sol
	std::cout << deque.front() << std::endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}