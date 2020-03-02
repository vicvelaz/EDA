// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

struct tSolucion {
	bool okey=true;
	int numPares;
};

tSolucion resolver(std::vector<int> const & v,int ini,int fin) 
{
	tSolucion sol, sol1, sol2;
	if (fin - ini == 1) // 1 elemento
	{
		if (v[ini] % 2 == 0)
			++sol.numPares;
		return sol;
	}
	else if (fin - ini == 2) //2 elementos
	{
		if (v[ini] % 2 == 0)
			++sol.numPares;
		if (v[ini + 1] % 2 == 0)
			++sol.numPares;
		return sol;
	}
	else
	{
		int m = (fin + ini - 1) / 2;
		sol1 = resolver(v, ini, m + 1);
		sol2 = resolver(v, m + 1, fin);
		if ((sol1.numPares - sol2.numPares <= 2) && (sol2.numPares - sol1.numPares <= 2))
		{
			sol.numPares = sol1.numPares + sol2.numPares;
			if (!sol1.okey && !sol2.okey)
				sol.okey = false;
		}
		else
			sol.okey = false;
		return sol;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num==0)
		return false;
	std::vector<int> v(num);
	for (int i = 0; i < num; ++i)
		std::cin >> v[i];
	
	if (resolver(v, 0, num).okey)
		std::cout << "SI" << '\n';
	else
		std::cout << "NO" << '\n';

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