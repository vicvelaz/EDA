// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include<algorithm>



using nombre = std::string;
struct tDatos {
	std::vector<std::string> fechas;
	int contador = 0;
};

// función que resuelve el problema
void resolver(int num) {
	std::map<nombre, tDatos>mapa;
	int vecesMax = 0;

	for (int i = 0; i < num; ++i)
	{
		std::string titulo, fecha;
		int numPeliculas;
		
		std::cin >> fecha >> numPeliculas;
		std::cin.ignore();
		for (int j = 0; j < numPeliculas; ++j)
		{
			std::getline(std::cin, titulo);
				mapa[titulo].contador++;
			if (mapa[titulo].fechas.size() == 0) //se añade la fecha si no hay fechas
				mapa[titulo].fechas.push_back(fecha);
			else if(mapa[titulo].fechas[mapa[titulo].fechas.size()-1]!=fecha) //nos aseguramos que no se repiten fechas
				mapa[titulo].fechas.push_back(fecha);
			vecesMax = std::max(vecesMax, mapa[titulo].contador);
		}

	}

	std::cout << vecesMax << '\n';
	for (auto const&it : mapa)
	{
		if (it.second.contador == vecesMax)
		{
			std::cout << it.first << " ";
			for (auto const&it2 : it.second.fechas)
			{
				std::cout << it2 << " ";
			}
			std::cout << '\n';
		}
	}
	std::cout << "---\n";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	if (!std::cin)
		return false;

	 resolver(num);

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