// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "copiarLista.h"





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam1,tam2,num,indice;
	std::cin >> tam1;
	if (!std::cin)
		return false;
	
	copiarLista<int> l;
	copiarLista<int>laux;

	
	
	for (int i = 0; i < tam1; ++i) //lee la primera cola
	{
		std::cin >> num;
		l.push(num);
	}
	std::cin >> tam2>>indice;

	for (int i = 0; i < tam2; ++i) //lee la segunda cola a añadir
	{
		std::cin >> num;
		laux.push(num);
	}
	l.copiar(laux,indice);
	l.imprimir();

	

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