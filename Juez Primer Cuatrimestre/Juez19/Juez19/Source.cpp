// Victor Velazquez Cabrera	
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;
// función que resuelve el problema
int combinatorio(tMatriz &matriz,int a,int b)
{
	if (b == 0)
		return 1;
	else if (a == b)
		return 1;
	else if (matriz[a][b] != -1)
		return matriz[a][b];
	else
	{
		//matriz[a][b] =combinatorio(matriz, a - 1, b - 1) + combinatorio(matriz, a - 1, b);

	return matriz[a][b] = combinatorio(matriz, a - 1, b - 1) + combinatorio(matriz, a - 1, b);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int a, b;
	std::cin >> a >> b;
	if (!std::cin)
		return false;
	
	tMatriz matriz(a+1, std::vector<int>(b+1,-1));
	
	
	std::cout << combinatorio(matriz,a,b) << '\n';
	// escribir sol
	/*for (int i = 0; i < a+1; ++i)
	{
		for (int j = 0; j < b+1; ++j)
			std::cout << matriz[i][j] << " ";
		std::cout << '\n';
	}*/
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

