// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema


bool resolver(std::vector<int> const & v,int ini,int fin, int num) {
	if (fin - ini == 1)
		return true;
	else if (fin - ini == 2)
	{
		if ((v[ini] - v[ini + 1] >= num) || (v[ini + 1] - v[ini] >= num))
			return true;
		else
			return false;
	}
	else
	{
		int m = (ini + fin - 1) / 2;
		if ((v[ini] - v[fin - 1] >= num) || (v[fin - 1] - v[ini] >= num))
		{
			return (resolver(v, ini, m + 1, num) && resolver(v, m + 1, fin, num));
		}
		else
			return false;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int tam, num;
	std::cin >> tam;

	if (!std::cin)
		return false;
	std::vector<int>v(tam);
	std::cin >> num;
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];
	if (resolver(v, 0, tam, num))
		std::cout << "SI"<<'\n';
	else
		std::cout << "NO"<<'\n';

	


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