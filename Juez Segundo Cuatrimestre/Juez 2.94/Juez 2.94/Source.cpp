// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include"bintree_eda.h"
using namespace std;

// función que resuelve el problema
struct tSol {
	bool ok;
	int altura;
};
tSol resolver(bintree<char> const &arbol) {
	if (arbol.empty()) return { true,0 };
	else 
	{
		tSol izq = resolver(arbol.left());
		tSol dcha = resolver(arbol.right());
		if (izq.ok && dcha.ok &&izq.altura==dcha.altura)
			return { true,izq.altura +1};
		else
			return { false,izq.altura +1};
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char> arbol=leerArbol('.');
	tSol sol = resolver(arbol);
	
	if (sol.ok)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
	
		

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