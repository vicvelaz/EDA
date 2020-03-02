// Victor Velázquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(std::vector<int> const &v,int ini,int fin) {
	if (fin - ini == 1)
		return v[ini];
	else if (fin - ini == 2)
	{
		if (v[ini] > v[fin-1])
			return v[fin-1];
		else
			return v[ini];
	}
	else 
	{
		
		int m = (fin + ini - 1) / 2;  
		if (v[m] < v[m + 1])
			return v[m];
		
		else if (v[m]<v[ini])
				return resolver(v, m, fin);
			else 
				return resolver(v, ini, m);
		
		
	}
	

}

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

	std::cout<<resolver(v,0,tam)<<'\n';

	


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