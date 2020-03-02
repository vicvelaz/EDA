// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const &v, int ini, int fin,int num)
{
	if (fin - ini == 1)//Array de tamaño 1
	{
		if (num == v[ini] - ini)
			return v[ini];
		else
			return -1;
	}
	else if (fin - ini == 2)
	{
		
		if (num == v[ini] - ini)
			return v[ini];
		else if (num == v[ini+1] - (ini+1))
			return v[ini+1];
		else
			return -1;
	}
	else
	{
		int m = (fin + ini - 1) / 2;
		if (num == v[m] - m)
			return v[m];
		else if (num < v[m] - m)
			return resolver(v, ini, m, num);
		else 
			return resolver(v,m+1,fin,num);
	}
	

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tam, num;
	int x = 0;
	
	std::cin >> tam >> num;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
	{
		std::cin >> v[i];
	}
	int resultado = resolver(v, 0, tam, num);
	if (resultado!=-1)
	{
		std::cout << resultado << '\n';
	}
	else
		std::cout << "NO" << '\n';


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