// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
void resolver( bintree <int> const & t, int & navegables, int & caudal) {
	if (t.empty()) {
		caudal = 0;
		navegables = 0;
	}
	else {
		int caudalIzq, navegablesIzq, caudalDcha, navegablesDcha;
		
		if (t.left().empty() && t.right().empty()) {
			caudal = 1;
			navegables = 0;
		}
		else {
			resolver(t.left(), navegablesIzq, caudalIzq);
			resolver(t.right(), navegablesDcha, caudalDcha);
			caudal = std::max(caudalIzq + caudalDcha - t.root(), 0);
			if (caudal >= 3) navegables = navegablesIzq+ navegablesDcha + 1;
			else navegables = navegablesIzq + navegablesDcha;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> t = leerArbol(-1);
	int navegablesIzda = 0, navegablesDcha = 0;
	int caudalIzda = 0, caudalDcha = 0;
	resolver(t.left(), navegablesIzda, caudalIzda);
	resolver(t.right(), navegablesDcha, caudalDcha);
	std::cout << navegablesIzda + navegablesDcha << '\n';
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