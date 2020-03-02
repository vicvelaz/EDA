// Victor Velázquez Cabrera
// E68

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int busquedaIzda(std::vector <int> const & v, int elem, int ini, int fin) 
{
	if (fin - ini == 1)
	{
		return ini;
	}
	else if (fin - ini == 2)
	{
		if (v[ini] == elem)
			return ini;
		else
			return ini + 1;
	}
	else
	{
		int m = (ini + fin - 1) / 2;
		if (v[m] == elem)
			return busquedaIzda(v, elem, ini, m+1);
		else
			return busquedaIzda(v, elem, m + 1, fin);
	}
}


int busquedaDcha(std::vector <int > const & v, int elem, int ini, int fin) 
{
	if (fin - ini == 1)
	{
		return ini;
	}
	else if (fin - ini == 2)
	{
		if (v[ini+1] == elem)
			return ini+1;
		else
			return ini ;
	}
	else
	{
		int m = (ini + fin - 1) / 2;
		if (v[m] == elem)
			return busquedaDcha(v, elem, m, fin);
		else
			return busquedaDcha(v, elem, ini, m);
	}
}


int resolver(std::vector<int> const & v,int ini,int fin,int num) {
	if (fin - ini == 0)
		return 0;
	else if (fin - ini == 1)
	{
		++num;
		return num;
	}
	else if (fin - ini == 2)
	{
		if (v[ini] == v[ini + 1])
			++num;
		else
			num += 2;
		return num;

	}

	else 
	{
		int m = (fin + ini - 1) / 2;
		
		int posIzda = busquedaIzda(v,v[m],ini,m+1);
		int posDcha = busquedaDcha(v,v[m],m,fin);
		
		return resolver(v, ini, posIzda, num) + resolver(v, posDcha + 1, fin, num)+1;
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	int tam;
	std::cin >> tam;
	if (tam==0)
		return false;
	std::vector<int> v(tam);
	
	for(int i=0;i<tam;++i)
		std::cin >> v[i];
	int num = 0;
	std::cout << resolver(v,0,tam,num) << '\n';

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