// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector <std::vector <int >>;

// función que resuelve el problema
void resolver(tmatriz const & matriz, std::vector<int> const &edadRecomendada, std::vector<int> &ninoJuguetes, std::vector<bool> & marcas,std::vector<int>const & edadNino,
	int const &minJuguetes,int& maximo,int &acum,int j) {
	bool okey=true;
	for (int i = 0; i < edadNino.size(); ++i)
	{
		if (!marcas[j])
		{
			if (edadNino[i] >= edadRecomendada[j])
			{
				marcas[j] = true; 
				acum += matriz[i][j];
				++ninoJuguetes[i];
				if (j == edadRecomendada.size() - 1)
				{
					for (int k = 0; k < ninoJuguetes.size(); ++k)
					{
						if (minJuguetes > ninoJuguetes[k])
							okey = false;
					}
					if (okey && acum > maximo)
					{
						maximo = acum;
					}
					okey = true;
				}
				else 
					resolver(matriz, edadRecomendada, ninoJuguetes, marcas, edadNino, minJuguetes, maximo, acum, j + 1);
				
				marcas[j] = false;
				acum -= matriz[i][j];
				--ninoJuguetes[i];
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int juguetes, ninos, minJuguetes;
	std::cin >> juguetes >> ninos >> minJuguetes;
	if (juguetes==0&&ninos==0&&minJuguetes==0)
		return false;
	int maximo=0, acum = 0;
	std::vector<int> edadRecomendada(juguetes);
	for (auto & e : edadRecomendada)
		std::cin >> e;
	std::vector<int> edadNinos(ninos);
	for (auto & n : edadNinos)
		std::cin >> n;
	tmatriz satisfaccion(ninos, std::vector<int>(juguetes));
	for (int i = 0; i < ninos; ++i)
		for (int j = 0; j < juguetes; ++j)
			std::cin >> satisfaccion[i][j];
	std::vector<bool> marcas(juguetes, false);
	std::vector<int> ninoJuguetes(ninos, 0);

	resolver(satisfaccion, edadRecomendada, ninoJuguetes, marcas, edadNinos, minJuguetes, maximo, acum, 0);
	std::cout << maximo << '\n';
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