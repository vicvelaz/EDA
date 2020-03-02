//Victor Velázquez Cabrera
//E68

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>

//Coste logaritmico

// función que resuelve el problema


int resolver(std::vector<int> const &v, int ini, int fin) {
	
	if (ini + 1 == fin)
		return v[ini];
	else if (ini + 2 == fin)
		return std::min(v[ini], v[ini + 1]);
	else {
		int m = (ini + fin - 1) / 2;

		if ((v[m] < v[m - 1]) && (v[m] < v[m + 1]))
			return v[m];
		else if(v[m]<v[m-1])
			return resolver(v, m + 1, fin);
		else
			return resolver(v, ini, m);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	std::cin >> n;
	

	if (!std::cin)
		return false;
	else {
		std::vector<int> v(n);


		for (int i = 0; i < n; ++i)
		{
			std::cin >> v[i];
		}

		std::cout << resolver(v, 0, n ) << '\n';
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