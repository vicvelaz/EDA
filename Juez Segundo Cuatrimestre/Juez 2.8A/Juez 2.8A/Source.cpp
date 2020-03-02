// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "duplicarLista.h"


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	if (!std::cin)
		return false;
	duplicarLista<int> lista;

	while (num != 0)
	{
		lista.push(num);
		std::cin >> num;
	}


	lista.duplicar();
	std::cout << lista.size()<<std::endl;//muestra el tamaño una vez duplicado
	lista.imprimir();//muestra la cola duplicada
	std::cin >> num;
	while (num != 0)
	{
		lista.push(num);
		std::cin >> num;
	}
	int borrar;
	std::cin >> borrar;
	for (int i = 0; i < borrar; ++i)
	{
		lista.pop();
	
	}
	std::cout << lista.size() << std::endl;//muestra el tamaño despues de borrar n nodos
	lista.imprimir(); //muestra la cola 



	// escribir sol


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