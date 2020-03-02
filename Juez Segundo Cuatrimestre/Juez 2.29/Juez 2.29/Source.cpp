//Victor Velazquez Cabrera
//E68
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>


int maxCapsSeguidosSinRepetir(std::vector <int> const& v) { // Coste lineal en el numero de capitulos del vector. Las inserciones y consultas a count son constantes
	std::unordered_map <int, int> capsEmitidos;
	int max = 0, maxActual = 0, principioCicloNoRepetidos = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (capsEmitidos.count(v[i]) && capsEmitidos.at(v[i]) >= principioCicloNoRepetidos) { //Si encuentra un capitulo repetido y el capitulo repetido esta dentro del ciclo de no repetidos actual
			maxActual = i - capsEmitidos.at(v[i]); //El maximo actual es la diferencia de indices entre el actual y el indice del capitulo repetido al actual
			principioCicloNoRepetidos = capsEmitidos.at(v[i]) + 1; //El principio del ciclo de no repetidos avanzara en una posicion
			capsEmitidos.at(v[i]) = i; //Actualiza el indice de aparicion del capitulo al ultimo encontrado
		}
		else if (!capsEmitidos.count(v[i])) { //Si el capitulo no es repetido
			capsEmitidos.insert({ v[i], i }); //Lo inserta
			maxActual++; //Aumenta el contador actual
		} 
		else { //Si es un capitulo que ya ha aparecido pero no esta dentro del ciclo de no repetidos actual
			capsEmitidos.at(v[i]) = i; //Actualiza el indice de aparicion del capitulo al ultimo encontrado
			maxActual++; //Aumenta el contador actual
		}
		if (maxActual > max) //Si el maximo actual supera al maximo se actualiza el valor del maximo
			max = maxActual;
	}
	return max;
}

void resuelveCaso() {
	int numCapitulos, capitulo;
	std::vector <int> vCaps;
	std::cin >> numCapitulos;
	for (int i = 0; i < numCapitulos; ++i) {
		std::cin >> capitulo;
		vCaps.push_back(capitulo);
	}
	std::cout << maxCapsSeguidosSinRepetir(vCaps) << '\n';
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