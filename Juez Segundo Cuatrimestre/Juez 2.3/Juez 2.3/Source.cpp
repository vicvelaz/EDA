// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Complejos.h"

// función que resuelve el problema
Complejos iteracion(Complejos & complejo, int &n,bool &pertenece)
{
	if (n == 0) 
		return Complejos (0,0);
	else if(pertenece)
	{
		Complejos num = iteracion(complejo, --n, pertenece);
		num = (num * num) + complejo;
		if (complejo.mod(num) > 2)
			pertenece = false;
		return num;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	float real, imaginaria;
	int n,i=0;
	std::cin >> real >> imaginaria >> n;
	Complejos complejo(real, imaginaria);
	bool pertenece = true;
	Complejos resultado = iteracion(complejo, n, pertenece);
	if (pertenece)
		std::cout << "SI" << '\n';
	else
		std::cout << "NO" << '\n';

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