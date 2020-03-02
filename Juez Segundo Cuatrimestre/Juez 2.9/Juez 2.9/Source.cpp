﻿// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include"invertirLista.h"


// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (!std::cin)
		return false;
	invertirLista<int> lista;

	while (num != 0)
	{
		lista.push(num);
		std::cin >> num;
	}

	lista.invertir();
	lista.imprimir();
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}