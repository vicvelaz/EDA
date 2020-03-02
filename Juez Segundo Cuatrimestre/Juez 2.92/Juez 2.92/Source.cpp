// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
//#include"queue_ext.h"
#include<unordered_map>
#include<vector>
using namespace std;
// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
/*void resuelveCaso(listaExtendida<int>  &l) {
	int veces, num;
	cin >> veces >> num;
	int resultado = l.buscar(veces, num);
	if (resultado != -1)
		cout << resultado << endl;
	else
		cout << "NO HAY" << endl;
}*/
void resuelvecaso(unordered_map<int, vector<int>> const & mapa)
{
	int veces, num;
	cin >> veces >> num;
	if (veces > mapa.at(num).size())
		cout << "NO HAY" << endl;
	else
	{
		vector<int> it = mapa.at(num);
		cout << it[veces-1]<<endl;

	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos,tam,num;
	std::cin >> tam>>numCasos;
	//listaExtendida<int>l;
	unordered_map <int, vector<int>> mapa;
	for (int i = 0; i < tam; ++i)
	{
		cin >> num;
		mapa[num].push_back(i+1);
	}
	for (int i = 0; i < numCasos; ++i)
	{
		resuelvecaso(mapa);
		//resuelveCaso(l);
	}

	cout << "---"<<endl; //
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}