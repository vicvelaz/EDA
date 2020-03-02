// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include"deque_eda.h"

void resolver(bintree<char>const& t,deque<int> &lista) {
	if(t.empty()){}
	else if (t.left().empty() && t.right().empty())
	{
		
	}
	else if (t.right().empty())
	{
		lista.push_back(0);//Cambio de nivel
		lista.push_back(1);//izquierda
	}
	else if (t.left().empty())
	{
		lista.push_back(0);//Cambio de nivel
		lista.push_back(-1);//derecha
	}
	else
	{
		lista.push_back(0);//Cambio de nivel
		lista.push_back(1);//izquierda
		resolver(t.left(), lista);
		lista.push_back(-1);//derecha
		resolver(t.right(),lista);
	}

}
bool comprobarSimetria(deque<int> &izquierda, deque<int> &derecha) {
	if (izquierda.size() != derecha.size())
		return false;
	else {
		int tam = izquierda.size();
		int i = 0;
		bool okey = true;
		while (i < tam && !okey)
		{
			int izq = izquierda.front();
			int dcha = derecha.front();
			if (izq == -dcha)
			{
				izquierda.pop_front();
				derecha.pop_front();
			}
			else
				okey = false;
			return okey;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
	
	bintree<char> t = leerArbol('.');
	deque<int> izquierda;
	deque<int>derecha;
	resolver(t.left(), izquierda);
	resolver(t.right(), derecha);
	izquierda.imprimir();
	int simetrica = comprobarSimetria(izquierda, derecha);
	if (simetrica)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

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