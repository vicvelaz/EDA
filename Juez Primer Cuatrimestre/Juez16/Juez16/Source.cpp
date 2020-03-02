// Victor Velazquez Cabrera	
// E68



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// T(n)= 2T(n/2)+n/2+n+n = 

// función que resuelve el problema
int resolver(std::vector<int> &  v, int ini, int fin) {

	if (ini >= fin) return 0;

	else {
		int m = (ini + fin) / 2;

		int izq = resolver(v, ini, m); // O (log n)
		int der = resolver(v, m + 1, fin); // O (log n)

		int i = ini, j = m + 1, cont = 0;

		while (i <= m && j <= fin) {

			if (v[i] > v[j]) {
				cont += (m - i + 1);
				++j;
			}
			else ++i;
		}

		std::sort(v.begin() + ini, v.begin() + fin + 1); // O(n log(n))
		return izq + der + cont;
	}

}
/*int resolver(std::vector<int>  & v,int ini,int fin)
{
	if (fin - ini == 1) 
		return 0;
	else if (fin - ini == 2)
	{
		if (v[ini] > v[ini + 1])
		{
			std::swap(v[ini], v[ini + 1]);
			
			return 1;
		}
		else
			return 0;
	}
	else
	{
		int m = (fin + ini - 1) / 2;
		int invIz = resolver(v, ini, m + 1);
		int invDr = resolver(v, m + 1, fin);
		int inv = 0, i = ini,j=m+1;
		while (i <= m && j < fin)
		{
			if (v[i] < v[j])
				++i;
			else
			{
				inv += (m - i);
				++j;
			}
		}
		std::vector<int> aux(fin - ini);
		std::merge (v.begin(), v.end(), v.begin() + ini, v.end() + fin,aux.begin());
		std::copy(aux.begin(), aux.end(),v.begin());

		
	}
}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	int tam;
	std::cin >> tam;

	if (!std::cin)
		return false;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	std::cout << resolver(v, 0, tam-1) << '\n';


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