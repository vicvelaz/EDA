//Victor Velázquez Cabrera
//E68


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
 long long int eliminar ( long long int n) {
	if (n == 0)
		return 0;
	else if (n % 2 == 0)
		return eliminar(n / 10);
	else
	return eliminar(n / 10) * 10 + n % 10;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long long int n;
	std::cin >> n;
	if (!std::cin)
		return false;
	std::cout << eliminar(n) << '\n';
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