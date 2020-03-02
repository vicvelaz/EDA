// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include"bintree_eda.h"
// función que resuelve el problema
void zurdo(bintree <char> const& arbol, bool &esZurdo, int & descendientes) {
	if (arbol.empty()) {
		esZurdo = true;
		descendientes = 0;
	}
	else if (arbol.left().empty() && arbol.right().empty()) {
		esZurdo = true;
		descendientes = 1;
	}
	else {
		bool esZurdoI, esZurdoD;
		int descendientesI, descendientesD;
		zurdo(arbol.left(), esZurdoI, descendientesI);
		zurdo(arbol.right(), esZurdoD, descendientesD);
		esZurdo = esZurdoI && esZurdoD && (descendientesI > (descendientesD + descendientesI) / 2);
		descendientes = descendientesI + descendientesD + 1;
	}
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	bool esZurdo;
	int descendientes;
	zurdo(arbol, esZurdo, descendientes);
	if (esZurdo) std::cout << "SI\n";
	else std::cout << "NO\n";


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