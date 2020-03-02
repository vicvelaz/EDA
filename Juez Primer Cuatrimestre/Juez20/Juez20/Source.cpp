// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
using tMatriz = std::vector<std::vector<int>>;
void sumasAux(std::vector<int> const &v, tMatriz & matriz, int act, int ult, int S, int &resul, int acum);

int sumasElems(std::vector<int> const &v, tMatriz & matriz, int n, int S) {
	int resul = 0;
	sumasAux(v,matriz, 0, n - 1, S, resul, 0);
	return resul;
}

void sumasAux(std::vector<int> const &v, tMatriz & matriz ,int act, int ult, int S, int &resul, int acum) {

	for (int i = act; i <= ult; ++i) {
		if (acum + v[i] <= S) { //puedo sumar el actual sin pasarme
			if (matriz[acum][v[i]] == -1)
			{
				matriz[acum][v[i]]=acum + v[i];
			}
			if (matriz[acum][v[i]] == S) {
				resul++;
			}
			else {
				sumasAux(v,matriz, i + 1, ult, S, resul, matriz[acum][v[i]]);
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta 
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, num;
	std::cin >> tam;
	if (!std::cin)
		return false;
	
	
	std::cin >> num;
	std::vector<int> v(tam);
	tMatriz matriz(tam*tam,std::vector<int>(tam*tam,-1));
	for (int i = 0; i < tam; ++i)
	{
		std::cin >> v[i];
	}

	
	std::cout << sumasElems(v,matriz,tam,num) << '\n';


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