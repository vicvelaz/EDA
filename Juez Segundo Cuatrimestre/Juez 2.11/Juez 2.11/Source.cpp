// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include"mezclarLista.h"

// función que resuelve el problema

void leer(queue<int> *cola)
{
	int num;
	bool exit = false;
	do {
		std::cin >> num;
		if (num != 0)
			cola->push(num);
		else
			exit = true;	
	} while (!exit);
}
queue<int> *mezclar(queue<int> *cola1, queue<int> *cola2)
{
	queue<int> *mezcla=new queue <int>;
	while (!cola1->empty() && !cola2->empty())
	{
		if (cola1->front() < cola2->front())
		{
			mezcla->push(cola1->front());
			cola1->pop();
		}
		else
		{
			mezcla->push(cola2->front());
			cola2->pop();
		}
	}
	if (cola1->empty())
		cola1 = cola2;
	int tam = cola1->size();
	for (int i = 0; i < tam; ++i)
	{
		mezcla->push(cola1->front());
		cola1->pop();
	}
	return mezcla;
}

void mostrar(queue<int> *cola)
{
	int tam = cola->size();
	for (int i = 0; i < tam; ++i)
	{
		std::cout << cola->front()<<' ';
		cola->pop();
	}
	std::cout << '\n';
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	/*queue <int> *cola1=new queue <int>, *cola2=new queue <int>;
	leer(cola1);
	leer(cola2);
	queue<int> *colaResultado=mezclar(cola1, cola2);
	
	mostrar(colaResultado);*/
	int num;
	mezclarLista<int> l;
	mezclarLista<int>l2;
	std::cin >> num;
	while (num != 0)
	{
		l.push(num);
		std::cin >> num;
	}
	std::cin >> num;
	while (num != 0)
	{
		l2.push(num);
		std::cin >> num;
	}

	l.mezclarL(l2);
	l.imprimir()
		;
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