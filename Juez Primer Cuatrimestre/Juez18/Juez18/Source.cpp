// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>



// funcion que resuelve el problema con recursión simple:
// El coste de esta función es lineal: O(n) siendo n el 
// la posición sobre la cual se quiere calcular el numero de 
// Fibonacci --->
// T(n) = {
//			c1							n == 0
//			c1							n == 1
//			T(n-1) + c2					n > 1
// }
long long int resolverSimple(int num, long long int a, long long int b) {

	if (num == 0) return b;
	else if (num == 1) return a;

	else return resolverSimple(num - 1, a + b, a);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	if (!std::cin) return false;

	
	std::cout << resolverSimple(num, 1, 0) << "\n";

	

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