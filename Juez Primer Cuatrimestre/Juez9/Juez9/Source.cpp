﻿// Victor Velázquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const & v, int ini, int fin)
{
	if (v[ini] % 2 != 0)
		return v[ini];
	else if (v[fin - 1] % 2 != 0)
		return v[fin - 1];
	else
	{
		int m = (fin + ini - 1) / 2;
		if (v[m] - 2 * m == v[0])
			return resolver(v, m + 1, fin);
		else
			return resolver(v, ini, m);
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int tam;

	std::cin >> tam;
	if (tam == 0)
		return false;
	std::vector<int>v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];
	std::cout << resolver(v, 0, tam) << '\n';



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