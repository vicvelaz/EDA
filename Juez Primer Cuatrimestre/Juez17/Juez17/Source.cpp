// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const & v1,std::vector<int>const & v2,int ini, int fin) 
{
	if (fin - ini == 1)
		return v1[ini];
	else if (fin - ini == 2)
	{
		if (v2[ini] == v1[ini])
			return v1[ini+1];
		else
			return v1[ini];
	}
	else
	{
		int m = (fin + ini - 1) / 2;
		if (v1[m] != v2[m])
		{
			if (v1[m - 1] == v2[m - 1])
				return v1[m];
			else
				return resolver(v1, v2, ini, m+1);
		}
		else
		{
			if (v1[m + 1] != v2[m + 1])
				return v1[m + 1];
			else
				return resolver(v1, v2, m, fin);
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tam;
	std::cin >> tam;
	std::vector<int> v1(tam),v2(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v1[i];
	for (int i = 0; i < tam - 1; ++i)
		std::cin >> v2[i];

	std::cout << resolver(v1, v2, 0, tam) << '\n';


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