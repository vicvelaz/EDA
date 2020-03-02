// Victor Velázquez Cabrera		
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
char resolver(std::vector<char> const & v,char ini,char fin,int inicio, int final) {
	
	if (ini != v[inicio])
	{
		return ini;
	}
	else if (fin != v[final])
		return fin;
	else {
		if (final - inicio > 1) 
		{
			int m = (final + inicio) / 2;
			if (int(v[m]) != int(v[0] + m))
				return resolver(v, ini, v[m], inicio, m);
			else
				return resolver(v, v[0] + m + 1, fin, m + 1, final);
		}
		else
			return v[inicio] + 1;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	char ini, fin;

	std::cin >> ini >> fin;
	int n = int(fin) - int(ini);
	int inicio = 0, final = n - 1;
	std::vector<char> v(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> v[i];
	}

	std::cout<<resolver(v,ini,fin,inicio,final)<<"\n";
	


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


