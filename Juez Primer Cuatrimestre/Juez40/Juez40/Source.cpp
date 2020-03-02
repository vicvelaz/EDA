// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
/*void resolver(std::vector<int> const &v, int &numGanados, int &numVeces, int& ultimaracha,int tam) 
{
	int contGanados = 0;
	for (int i = 0; i < tam; ++i)
	{
		
		if (v[i] > 0)
		{
			++contGanados;
			if (contGanados > numGanados)
			{
				numGanados = contGanados;
				ultimaracha=0;
				numVeces = 1;
				if (i == tam-1)
				{
					ultimaracha = -1;
				}
			}
			else if (contGanados == numGanados)
			{
				ultimaracha = 0;
				++numVeces;
			}
			++ultimaracha;
		}
		else
		{
			if ((contGanados == numGanados)&&(contGanados!=0))
			{
				ultimaracha = 0;
			}
			else if (contGanados > numGanados)
			{
				numGanados = contGanados;
				ultimaracha = 0;
				numVeces = 1;
			}
			++ultimaracha;
			contGanados = 0;
		}
	}
	
}*/


void resolver(std::vector<int> const& v, int& numPartidosGanados, int& ini, int&numVeces) {
	numPartidosGanados = 0; ini = 0; numVeces = 0; int iniUlt = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > 0) {
			if (numPartidosGanados < i - iniUlt + 1) {
				numPartidosGanados = i - iniUlt + 1;
				ini = iniUlt;
				numVeces = 1;
			}
			else if (numPartidosGanados == i - iniUlt + 1) {
				++numVeces;
				ini = iniUlt;
			}
		}
		else iniUlt = i + 1;
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];
	int numPartidosGanados = 0, numVeces = 0, ini = 0;
	resolver(v, numPartidosGanados, ini, numVeces);

	std::cout << numPartidosGanados << " " << numVeces << " " << tam - (ini + numPartidosGanados) << '\n';


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