// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"
#include <algorithm>

// función que resuelve el problema
template<typename T>
T resolver(bintree<T>const & t)
{

	if (t.left().empty() && t.right().empty())
		return t.root();
	else if (t.left().empty())
		return std::min(t.root(), resolver(t.right()));
	else if (t.right().empty())
		return std::min(t.root(), resolver(t.left()));
	else
		return std::min(t.root(), std::min(resolver(t.left()), resolver(t.right())));
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
//template <typename T>
bool resuelveCaso() {
	// leer los datos de la entrada
	char opcion;
	std::cin >> opcion;

	if (!std::cin)
		return false;
	
	//bintree <T> t;
	if (opcion == 'N')
	{
		bintree <int>t = leerArbol(-1);
		std::cout << resolver(t) << '\n';
	}
	else
	{
		bintree<std::string> t1 = leerArbol(std::string("#"));
		std::cout << resolver(t1) << '\n';
	}
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