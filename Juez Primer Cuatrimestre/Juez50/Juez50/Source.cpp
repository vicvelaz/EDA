// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
std::vector<int> resolver(std::vector<int> const & v,int const & l) {
	int tam = v.size();
	std::vector<int> sol;
	int contador = 1;
	int indice = 0;
	for (int i = 1; i < tam-1; ++i)
	{
		if (v[i-1] - v[i] <= 1 && v[i] - v[i - 1] <=1)
		{
			++contador;
		}
		else {
			if (contador >= l)
				sol.push_back(indice);
			contador = 1;
			indice = i;
		}
	}
	if (contador >= l)
		sol.push_back(indice);
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, l;
	std::cin >> tam >> l;
	if (tam==0&&l==0)
		return false;

	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	std::vector<int> solucion = resolver(v, l);
	std::cout << solucion.size();
	for (auto s : solucion)
		std::cout << " " << s;
	std::cout << '\n';

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