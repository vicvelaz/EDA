// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using equipo = std::string;
using nombreProblema = std::string;
struct infoProblema {
	bool resuelto = false;
	int penalizacion = 0;
};
struct infoEquipo {
	std::unordered_map<nombreProblema, infoProblema> problema;
	int tiempo = 0, resueltos = 0;
};
struct mostrarInfo {
	std::string nombre;
	int tiempo, resueltos;
};

bool orden(mostrarInfo p1, mostrarInfo p2) {
	return (p1.resueltos > p2.resueltos) || (p1.resueltos > p2.resueltos && p1.tiempo < p2.tiempo);
}


void resuelveCaso() {
	std::map<equipo, infoEquipo> mapa;
	std::string nombre, nombreProblema, veredicto; int minutos;
	std::cin >> nombre;
	while (nombre != "FIN")
	{
		std::cin >> nombreProblema >> minutos >> veredicto;
		mapa[nombre];
		if (!mapa[nombre].problema.count(nombreProblema)) //si no esta el problema en ese equipo se añade
		{
			mapa[nombre].problema[nombreProblema];
		}

		if (mapa[nombre].problema.at(nombreProblema).resuelto == false) //si no ha resuelto aun el problema
		{
			if (veredicto == "AC")
			{
				mapa[nombre].problema.at(nombreProblema).resuelto = true;
				mapa[nombre].tiempo += minutos;

				++mapa[nombre].resueltos;
			}
			else {
				++mapa[nombre].problema[nombreProblema].penalizacion;
			}
		}
		std::cin >> nombre;
	}
	for (auto &it : mapa)
	{
		for(auto & it1:it.second.problema)
			if(it1.second.resuelto)
				it.second.tiempo += 20 * it1.second.penalizacion;

		//std::cout << it.first << " " << it.second.resueltos << " " << it.second.tiempo << '\n';
	}
	std::vector< mostrarInfo> v1(mapa.size());
	int i = 0;
	for (auto it2:mapa)
	{
		v1[i].nombre = it2.first;
		v1[i].resueltos = it2.second.resueltos;
		v1[i].tiempo = it2.second.tiempo;
		++i;
	}
	sort(v1.begin(), v1.end(), orden);
	//std::cout << '\n';
	for (int i = 0; i < v1.size(); ++i)
		std::cout << v1[i].nombre << " " << v1[i].resueltos << " " << v1[i].tiempo << '\n';
	/*for (auto it : mapa)
	{
		std::cout << it.first << " " << it.second.resueltos << " " << it.second.tiempo << '\n';
	}*/
	std::cout << "----" << '\n';
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