// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tSol {
	bool binario;
	int minimo;
	int maximo;
};

tSol resolver(bintree<int> const &t) {
	tSol sol;
	int raizAct = t.root();
	if (t.left().empty() && t.right().empty())
	{
		sol.binario = true;
		sol.maximo = raizAct;
		sol.minimo = raizAct;
	}
	else if (t.left().empty())
	{
		tSol dcha = resolver(t.right());
		if (dcha.binario)
		{
			if (dcha.minimo <= raizAct)
				sol.binario = false;
			else
			{
				sol.binario = true;
				sol.minimo = raizAct;
				sol.maximo = dcha.maximo;
			}
		}
		else
			sol.binario = false;
	}
	else if (t.right().empty())
	{
		tSol izda = resolver(t.left());
		if (izda.binario)
		{
			if (izda.maximo >= raizAct)
				sol.binario = false;
			else
			{
				sol.binario = true;
				sol.minimo = izda.minimo;
				sol.maximo = raizAct;
			}
		}
		else
			sol.binario = false;
	}
	else {
		tSol dcha = resolver(t.right());
		tSol izda = resolver(t.left());
		
		if ((izda.binario&&dcha.binario) && (raizAct > izda.maximo) && (raizAct < dcha.minimo))
		{
			sol.binario = true;
			sol.maximo = dcha.maximo;
			sol.minimo = izda.minimo;
		}
		else
			sol.binario = false;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	
	bintree<int>t = leerArbol(-1);
	if(t.empty())
		std::cout << "SI" << '\n';

	else {

	tSol sol = resolver(t);
	if (sol.binario)
		std::cout << "SI" << '\n';
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