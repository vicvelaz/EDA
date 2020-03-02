// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <algorithm>
using namespace std;
// función que resuelve el problema
struct tSol {
	int altura;
	int maximo;
};
tSol camino(bintree<int> const & arbol) {
	 if (arbol.empty()) return { 0,0 };
	else {
		tSol izq = camino(arbol.left());
		tSol dcha = camino(arbol.right());
		if (arbol.root() % 2 == 0)
			return { 1 + max(izq.altura,dcha.altura),max(1 + izq.altura + dcha.altura,max(izq.maximo,dcha.maximo)) };
		else
			return{ 0,max(izq.maximo,dcha.maximo) };
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
		tSol solucion = camino(arbol);
		cout << max(solucion.altura, solucion.maximo) << endl;
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