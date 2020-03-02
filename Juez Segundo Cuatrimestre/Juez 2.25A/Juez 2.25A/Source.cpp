//Victor Velazquez Cabrera
//E68
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


struct tSol {
	bool genealogico;
	int altura;
};

tSol resolver(bintree<int> const & t) {
	if (t.left().empty() && t.right().empty())
		return { true,1 };
	else if (t.left().empty())
		return { false,0 };
	else if (t.right().empty())
	{
		tSol izq = resolver(t.left());
		if ((t.root() - t.left().root() >= 18) && izq.genealogico)
			return { true,++izq.altura };
		else
			return { false,0};
	}
	else {
		tSol izq = resolver(t.left());
		tSol dcha = resolver(t.right());
		if (izq.genealogico && dcha.genealogico && t.root() - t.left().root() >= 18 && t.left().root() - t.right().root() >= 2)
			return{ true,1+std::max(izq.altura,dcha.altura) };
		else
			return{ false,0 };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> t = leerArbol(-1);
	if (t.empty())
		std::cout << "SI "<< 0<<'\n';
	else {
		tSol solucion =resolver(t);
		if (solucion.genealogico)
			std::cout << "SI " << solucion.altura << '\n';
		else
			std::cout << "NO" << '\n';
	}
	


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