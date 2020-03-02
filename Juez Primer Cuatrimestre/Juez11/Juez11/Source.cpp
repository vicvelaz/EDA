// Victor Velázquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
long int busquedaIz(std::vector <long int> const & v, int elem, long int ini, long int fin)
{
	if (ini >= fin)
		return ini; // vector vacio
	else if (ini + 1 == fin) 
		return ini; // vector 1 elemento
	else 
	{
		int mitad = (ini + fin - 1) / 2;
		if (v[mitad] < elem) 
			return busquedaIz(v, elem, mitad + 1, fin);
		else 
			return busquedaIz(v, elem, ini, mitad + 1);
	}
}

long int busquedaDcha(std::vector <long int> const & v, int elem, long int ini, long int fin) 
{
	if (ini >= fin) 
		return ini; // vector vacio
	else if (ini + 1 == fin)
		return ini; 
	else {
		int mitad = (ini + fin) / 2;
		if (elem < v[mitad])
			return busquedaDcha(v, elem, ini, mitad);
		else
			return busquedaDcha(v, elem, mitad, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int elem;
	long int numelem;
	std::cin >> numelem;
	if (!std::cin) 
		return false;
	std::cin >> elem;
	std::vector <long int> v(numelem);
	for (int i=0;i<numelem;++i) 
		std::cin >> v[i];
	long int posIz = busquedaIz(v, elem, 0, numelem);
	if (posIz == numelem || v[posIz] != elem)
		std::cout << "NO EXISTE \n";
	else
	{
		long int posDr = busquedaDcha(v, elem, 0, numelem);
		if (posIz == posDr)
			std::cout << posIz << '\n';
		else
			std::cout << posIz << ' ' << posDr << '\n';
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