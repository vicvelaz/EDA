// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "carnet_puntos.h"

// función que resuelve el problema
void realizarOperacion(std::string operacion, carnet_puntos &carnet) {
	std::string dni;
	int puntos;
	if (operacion == "nuevo")
	{
		std::cin >> dni;
		try {
			carnet.nuevo(dni);
		}
		catch (std::domain_error ai) {
			std::cout << "ERROR: " << ai.what() << '\n';
		}
	}
	else if (operacion == "quitar")
	{
		std::cin >> dni >> puntos;
		try {
			carnet.quitar(dni, puntos);
		}
		catch (std::domain_error ai) {
			std::cout << "ERROR: " << ai.what() << '\n';
		}
	}
	else if (operacion == "consultar")
	{
		std::cin >> dni;
		try {
			std::cout << "Puntos de " << dni << ": " << carnet.consultar(dni) << '\n';
		}
		catch (std::domain_error ai) {
			std::cout << "ERROR: " << ai.what() << '\n';
		}
	}
	else if (operacion == "cuantos_con_puntos")
	{
		std::cin >> puntos;
		try {
			std::cout << "Con " << puntos << " puntos hay " << carnet.cuantos_con_puntos(puntos) << '\n';
		}
		catch (std::domain_error ai) {
			std::cout << "ERROR: " << ai.what() << '\n';
		}
	}
	else if (operacion == "recuperar")
	{
		std::cin >> dni >> puntos;
		try {
			carnet.recuperar(dni, puntos);
		}
		catch (std::domain_error ai) {
			std::cout << "ERROR: " << ai.what() << '\n';
		}
	}
	else if (operacion == "lista_por_puntos")
	{
		std::cin >> puntos;
		try {
			std::list<std::string> const&  l =carnet.lista_por_puntos(puntos);
			std::cout << "Tiene " << puntos << " puntos:";
			for (auto it : l)
			{
				std::cout << " " << it;
			}
			std::cout << '\n';
		}
		catch (std::domain_error ai) {
			std::cout << "ERROR: " << ai.what() << '\n';
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::string operacion;
	std::cin >> operacion;
	if (!std::cin)
		return false;
	carnet_puntos carnet;
	while (operacion != "FIN") {
		realizarOperacion(operacion, carnet);
		std::cin >> operacion;
	}
	std::cout << "---\n";
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