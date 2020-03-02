//Victor Velazquez Cabrera

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

struct tSol {
	int dragones = 0;
	std::string hoja;
};

template <typename T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	

	tSol devuelveDragones()
	{
		return dragones(this->raiz);
	}

private:
	tSol dragones(Link l)
	{
		tSol sol;
		if (l->left == nullptr && l->right == nullptr)
			sol.hoja = l->elem;
		else if (l->left == nullptr)
			sol = dragones(l->right);
		else if (l->right == nullptr)
			sol = dragones(l->left);
		else
		{
			tSol sol1 = dragones(l->left);
			tSol sol2 = dragones(l->right);

			if (sol1.dragones <= sol2.dragones)
				sol = sol1;
			else
				sol = sol2;
		}
		if (l->elem == "Dragon")
			++sol.dragones;

		return sol;
	}
};

template <typename T>
bintree_ext<T> leerArbolPlus(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolPlus(vacio);
		auto dr = leerArbolPlus(vacio);
		return {iz,raiz,dr};
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree_ext<std::string>arbol = leerArbolPlus(std::string("..."));

	tSol sol = arbol.devuelveDragones();
	std::cout << sol.hoja << " " << sol.dragones << '\n';
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