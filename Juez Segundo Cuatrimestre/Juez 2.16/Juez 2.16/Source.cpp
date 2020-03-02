// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "condicionEliminar.h"
#include "Persona.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int personas, edadMinima, edadMaxima;
	std::cin >> personas >> edadMinima >> edadMaxima;
	if (personas == 0 && edadMinima == 0 && edadMaxima == 0)
		return false;
	list<persona> lista;
	int edad;
	std::string nombre;
	char aux;
	for (int i = 0; i < personas; ++i) {
		std::cin >> edad;
		std::getline(std::cin, nombre);
		lista.push_back(persona(edad, nombre));
	}
	condicionEliminar pred = condicionEliminar(edadMinima, edadMaxima);
	lista.remove_if(pred);
	for (persona p : lista) {
		std::cout << p;
	}
	std::cout << "---" << '\n';
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