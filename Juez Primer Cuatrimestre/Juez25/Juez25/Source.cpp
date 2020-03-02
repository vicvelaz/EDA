// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void tirasLuces(int consMax, int longMax, int colores, std::vector<int> consumos, std::vector<int> tira, int consAct, int longAct, std::vector<int> cant, int &tieneSol)
{
	for (int i = 0; i < colores; ++i)
	{
		if (cant[i] <= longAct - cant[i] && consAct + consumos[i] <= consMax && (longAct < 2 || tira[longAct - 2] != i || tira[longAct - 1] != i)) // Si se puede añadir
		{
			tira[longAct] = i;
			++cant[i];

			if (longAct + 1 == longMax)
				++tieneSol;

			else
				tirasLuces(consMax, longMax, colores, consumos, tira, consAct + consumos[i], longAct + 1, cant, tieneSol);

			--cant[i];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int consMax;
	int longMax;
	int colores;
	int tieneSol = 0;

	std::cin >> longMax;
	std::cin >> colores;
	std::cin >> consMax;

	if (!std::cin)
		return false;

	else
	{
		std::vector<int> consumos(colores);
		std::vector<int> tira(longMax);
		std::vector<int> cant(colores); // Cantidades de cada tipo de colores

		for (int i = 0; i < colores; ++i)
		{
			std::cin >> consumos[i];
			cant[i] = 0;
		}
		for (int i = 0; i < longMax; ++i)
		{
			tira[i] = 0;
		}

		tirasLuces(consMax, longMax, colores, consumos, tira, 0, 0, cant, tieneSol);

		std::cout << tieneSol << '\n';

		return true;
	}
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