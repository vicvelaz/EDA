// Victor Velázquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
//struct tSol {
//	long int numero;
//	long int pot;
//};


long int inverso(long int numero, long int pot)
{
	if (numero == 0)
		return pot;
	else
		return inverso(numero/ 10, pot * 10 + numero % 10);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	long int numero, pot = 0;
	std::cin >> numero;

	if (!std::cin)
		return false;
	

	std::cout << inverso(numero,pot) << '\n';


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