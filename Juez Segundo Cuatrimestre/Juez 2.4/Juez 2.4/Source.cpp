// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Polinomios.h"



// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int coeficiente, exponente, n;
	std::cin >> coeficiente;
	if (!std::cin)
		return false;
	Polinomio monomios;
	
	std::cin >> exponente;
	while (coeficiente != 0 || exponente != 0)
	{
		monomios.setMonomio(coeficiente, exponente);
		std::cin >> coeficiente >> exponente;
	} 
	std::cin >> n;
	int num;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> num;
		std::cout << monomios.evaluar(num) << " ";
	}
	std::cout << '\n';

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