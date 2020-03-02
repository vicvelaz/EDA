// Victor Velázquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tSolucion {
	int minimo, maximo;
	bool okey = false;
};

tSolucion resolver(std::vector<int> const & v, int ini, int fin) {
	tSolucion tsol, tsol1, tsol2;
	if (fin - ini == 1)
	{
		tsol.maximo = v[ini];
		tsol.minimo = v[ini];
		tsol.okey = true;
	}
	else if (fin - ini == 2)
	{
		if (v[ini] <= v[ini + 1])
		{
			tsol.minimo = v[ini];
			tsol.maximo = v[ini + 1];
			tsol.okey = true;
		}
		else
		{
			tsol.minimo = v[ini+1];
			tsol.maximo = v[ini];
			
		}
	}
	else
	{
		int m = (ini + fin - 1) / 2;
		tsol1 = resolver(v, ini, m+1);
		tsol2 = resolver(v, m+1, fin);
		if (tsol1.minimo <= tsol2.minimo)
			tsol.minimo = tsol1.minimo;
		else
			tsol.minimo = tsol2.minimo;
		if (tsol1.maximo >= tsol2.maximo)
			tsol.maximo = tsol1.maximo;
		else
			tsol.maximo = tsol2.maximo;
		tsol.okey = (tsol1.okey) && (tsol2.okey) && (tsol1.minimo <= tsol2.minimo) && (tsol1.maximo <= tsol2.maximo);
	}
	return tsol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::vector<int>v;
	int num;
	std::cin >> num;
	if (num == 0)
		return false;
	else
	{
		while (num != 0)
		{
			v.push_back(num);
			std::cin >> num;
		}
		tSolucion sol = resolver(v, 0, v.size());
			if (sol.okey == true)
				std::cout << "SI" << '\n';
			else
				std::cout << "NO" << '\n';




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