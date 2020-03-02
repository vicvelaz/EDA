// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


// función que resuelve el problema
int resolver(std::vector<int> const & v,int ini,int fin) 
{
	if (fin - ini == 1)
		return v[ini];
	else if (fin - ini == 2)
	{
		if (v[ini] < v[ini + 1])
			return v[ini] + v[ini + 1];
		else
			return -1;
	}
	else
	{
		int m = (fin + ini - 1) / 2;
		int izq = resolver(v, ini, m + 1);
		int dcha = resolver(v, m + 1, fin);
		if ((izq == -1) || (dcha == -1))
			return -1;
		else if (izq < dcha)
			return izq + dcha;
		else
			return -1;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int filas, tam;
	bool ok = true;
	
	std::cin >> filas >> tam;
	
	if (!std::cin)
		return false;
	else
	{
		
		std::vector<int>v(tam);
		for (int i = 0; i < filas; ++i)
		{
			for (int j = 0; j < tam; ++j)
				std::cin >> v[j];
			if (ok)
			{
				if (resolver(v, 0, tam) == -1)
					ok = false;
			}
		}
		if (ok == true)
			std::cout << "SI" << '\n';
		else
			std::cout << "NO" << '\n';
	}
	


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