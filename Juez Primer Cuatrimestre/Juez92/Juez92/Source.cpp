// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
int resolver(std::vector<int>const & v,int ini,int fin) {
	if (ini + 1 == fin) {
		if (v[ini] == 0)return v.size() - ini;
		else
			return v.size()-fin;
	}
	else if (ini + 2 == fin) {
		if (v[ini + 1] == 1) return v.size() - fin;
		else if (v[ini] == 1 && v[ini + 1] == 0) return v.size() - (ini + 1);
		else return  v.size() - ini;
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (v[m] == 1) //Preguntar si es mejor hacer mas ifs o que se haga la llamada recursiva
			return resolver(v, m + 1, fin);
		else return resolver(v, ini, m);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tam;
	std::cin >> tam;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];
	if(tam==0)
		std::cout << 0 << '\n';
	else
		std::cout << resolver(v,0,tam) << '\n';
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