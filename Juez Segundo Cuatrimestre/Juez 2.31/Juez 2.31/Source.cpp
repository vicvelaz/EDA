//Victor Velazquez Cabrera
//E68

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctype.h>
#include <sstream>
#include <fstream>

using namespace std;
void pasaAMinuscula (string & palabra) {
	for (int i = 0; i < palabra.size(); ++i) {
		if (isupper(palabra[i])) {
			palabra[i] = tolower(palabra[i]);
		}
	}
}


bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)
		return false;
	char aux;
	cin.get(aux);
	string linea, palabra;
	map <string, vector<int>> palabrasTexto;
	stringstream ss;
	for (int i = 0; i < N; ++i) { // Coste lineal en el numero de palabras del texto
		getline(cin, linea);
		ss.clear();
		ss << linea;
		while (ss >> palabra) {
			if (palabra.size() > 2) {
				pasaAMinuscula(palabra);
				if (palabrasTexto.count(palabra)) {
					if (palabrasTexto.at(palabra).back() != i + 1) {
						palabrasTexto.at(palabra).push_back(i + 1);
					}
				}
				else palabrasTexto.insert({ palabra, { i + 1 } });
			}
		}
	}

	for (auto it : palabrasTexto) {
		cout << it.first ;
		for (int i = 0; i < it.second.size(); ++i) 
			cout <<  " " << it.second[i];
		cout << '\n';
	}
	cout << "----\n";
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