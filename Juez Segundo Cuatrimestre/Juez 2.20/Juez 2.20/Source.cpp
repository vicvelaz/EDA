//Victor Velazquez Cabrera
//E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <vector>

template <typename T>
int resolver(bintree<T> const & t, std::vector<int> & resultado)
{
	if (t.empty()) return 0;
	else
	{
		if (resolver(t.left(), resultado) + resolver(t.right(), resultado) == 0)
			resultado.push_back(t.root());
		return 1;
	}
}
// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	bintree <int> t = leerArbol(-1);
	std::vector<int>resultado;
	int sol = resolver(t, resultado);
	int tam = resultado.size();
	for (int i = 0; i <tam; ++i)
		std::cout << resultado[i] << " ";
	std::cout << std::endl;
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