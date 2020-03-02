// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector <std::vector <int >>;
// función que resuelve el problema



void asigna(tmatriz tiempo, int N, std::vector<bool> asignados, int &mejor, int acum, int i,std::vector<int> const & mejoresTiemposAcumulados) {
	for (int j = 0; j < N; ++j) {
		if (!asignados[j]) {

			asignados[j] = true;
			if (i == N - 1) {
				if (acum + tiempo[i][j] < mejor)
					mejor = acum + tiempo[i][j];
			}
			else if (acum + mejoresTiemposAcumulados[i] < mejor) {
				asigna(tiempo, N, asignados, mejor, acum + tiempo[i][j], i + 1,mejoresTiemposAcumulados);
			}
			asignados[j] = false;
		}
	}
}





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, mejor = 0,sumaTiempos=0;
	std::cin >> tam;
	if (tam == 0)
		return false;
	tmatriz matriz(tam, std::vector<int>(tam));
	std::vector<bool> okey(tam,false),ok(tam,false),ok2(tam,false);
	std::vector<int> mejoresTiempos(tam), mejoresTiemposAcumulados(tam);
	for (int i = 0; i < tam; ++i)
	{
		for (int j = 0; j < tam; ++j)

			std::cin >> matriz[i][j];
		okey[i] = false;
		mejor += matriz[i][i];
	}

	for (int i = 0; i < tam; ++i) //Busca los mejores tiempos de cada Ministro
	{
		int indice = 0;
		for (int j = 0; j < tam; ++j)
		{
			if ((mejoresTiempos[i] == 0 || mejoresTiempos[i] > matriz[i][j]) && (!ok[j]))
			{
				mejoresTiempos[i] = matriz[i][j];
				indice=j;
				//ok2[i] = true;
			}
		}
		ok[indice] = true;
	}
	for (int i = tam - 1; i >= 0; --i) //Realiza la acumulacion de los mejores precios de cada producto
	{
		sumaTiempos += mejoresTiempos[i];
		mejoresTiemposAcumulados[i] = sumaTiempos;
	}

	asigna(matriz, tam, okey, mejor, 0, 0,mejoresTiemposAcumulados); //

	std::cout << mejor << '\n';
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