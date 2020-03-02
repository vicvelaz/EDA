// Victor Velázquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Hora.h"
#include "Pelicula.h"
#include <algorithm>




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int num;
	std::cin >> num;

	if (num==0)
		return false;

	Hora h1, h2;
	std::string nombre;
	std::vector<Pelicula> v(num);

	for (int i = 0; i < num; ++i)
	{
		std::cin >> h1 >> h2;
		std::getline(std::cin, nombre);
		Pelicula pelicula(h1 + h2, nombre);
		v[i] = pelicula;
	}
	std::sort(v.begin(), v.end());
	for (Pelicula p : v)
		std::cout << p << '\n';
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