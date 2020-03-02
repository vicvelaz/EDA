// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

using pelicula = string;
using actor = string;
using tiempo = int;
using veces = int;
/*struct infoActor {
	string actor;
	int tiempo;
};*/
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPeliculas;
	cin >> numPeliculas;
	if (numPeliculas == 0)
		return false;
	string peli, nombreActor;
	int tiempoActor, numActores;
	unordered_map<pelicula, unordered_map<actor, tiempo>>peliculas;
	map<actor, tiempo> tiemposActor;
	unordered_map<pelicula, veces> peliculasParrilla;
	for (int i = 0; i < numPeliculas; ++i)
	{
		cin >> peli >> numActores;
		auto& it = peliculas[peli];
		for (int j = 0; j < numActores; ++j)
		{
			cin >> nombreActor >> tiempoActor;
			it[nombreActor] = tiempoActor;
			tiemposActor[nombreActor] = 0;
		}
	}
	int parrilla,maxEmitida=0,maxTiempoActor=0;
	string peliMaxEmitida;
	cin >> parrilla;
	for (int i = 0; i < parrilla; ++i)
	{
		cin >> peli;
		++peliculasParrilla[peli];
		for (auto &it1 : peliculas[peli])
		{
			tiemposActor[it1.first] += it1.second;
			if (tiemposActor[it1.first] > maxTiempoActor)
				maxTiempoActor = tiemposActor[it1.first];
		}
		if (peliculasParrilla[peli] >= maxEmitida)
		{
			maxEmitida = peliculasParrilla[peli];
			peliMaxEmitida = peli;
		}
	}
	
	cout << maxEmitida<<" "<<peliMaxEmitida<<endl;
	cout << maxTiempoActor;
	for (auto const &it2 : tiemposActor)
	{
		if (it2.second == maxTiempoActor)
			cout <<" "<< it2.first;
	}
	cout << endl;

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