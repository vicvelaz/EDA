// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using tmatriz = vector<vector<int>>;
// función que resuelve el problema
void resolver(tmatriz const &donaciones, tmatriz const& vetos,vector<int> const&mejoresDonacionesAcum,vector<bool>&marcas,vector<int> &orden,int const & tam, int j,int actual,int & mejor)
{
	for (int i = 0; i < tam; ++i)
	{
		if (!marcas[j])
		{
			marcas[j] = true;
			actual += donaciones[i][j];
			if (vetos[i][orden[i]] == 1)
			{
				
				if(j<tam-1)


			}
			marcas[j] = false;
			actual -= donaciones[i][j];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tam;
	cin >> tam;
	tmatriz donaciones(tam, vector<int>(tam));
	for (int i = 0; i < tam; ++i) 
		for (int j = 0; j < tam; ++j)
			cin >> donaciones[i][j];
	tmatriz vetos(tam, vector<int>(tam));
	for (int i = 0; i < tam; ++i)
		for (int j = 0; j < tam; ++j)
			cin >> vetos[i][j];
	int mejor = 0;
	/*for (int i = 0; i < tam; ++i) //inicializar un caso posible como el mejor caso
		for (int j = 0; j < tam; ++j)
			if (i == j)
				mejor += donaciones[i][j];*/
	vector<int> mejoresDonaciones(tam);
	for (int i = 0; i < tam; ++i) { //Inicializa el vector con la mejor donacion 
		int aux = donaciones[i][0];
		for (int j = 1; j < tam; ++j)
			if (donaciones[i][j] > aux)
				aux = donaciones[i][j];
		mejoresDonaciones[i] = aux;
	}
	vector<int>mejoresDonacionesAcum(tam,0);
	for (int i = tam; i>-1; --i) //inicializa el vector con la acumulacion de mejores donaciones
	{
		for (int j = i; j < tam; ++j)
			mejoresDonacionesAcum[i] += mejoresDonaciones[j];
	}
	vector<bool>marcas(tam, false); //vector que guarda si el artista esta colocado o no
	vector<int> orden(tam, -1); //vector que ira guardando el orden de los artistas
	resolver(donaciones, vetos, mejoresDonacionesAcum, marcas,orden,tam, 0, 0, mejor);
	cout << mejor << endl;

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