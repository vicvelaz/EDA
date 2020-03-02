//Victor Velazquez Cabrera
//E68

#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;


bool menor(pair<string, int> p1, pair<string, int> p2) {
	return ((p1.second > p2.second) || (p2.second == p1.second && p1.first < p2.first));
}



bool resuelveCaso() {
	string deporte;
	getline(cin, deporte);
	if (!std::cin)
		return false;
	unordered_map <string, pair<string, bool>> idsApuntados; // El bool lo llevo para saber si es valido. (No se ha apuntado a mas de un deporte)
	unordered_map <string, int> deportesAparecieron;
	string cadena;
	cadena = deporte;
	while (cadena != "_FIN_") {
		if (islower(cadena[0]) || isdigit(cadena[0])) {
			if (idsApuntados.count(cadena)) {
				if (idsApuntados.at(cadena).first != deporte) {
					idsApuntados.at(cadena).second = false;
				}
			}
			else {
				idsApuntados.insert({ cadena, { deporte, true } });
			}
		}
		else if (isupper(cadena[0])) {
			deporte = cadena;
			deportesAparecieron.insert({ deporte, 0 }); // Entiendo que nunca voy a encontrar un deporte repetido. Por ahora valor 0, luego contare los apuntados correctos.
		}
		getline(cin, cadena);
	}

	for (auto pares : idsApuntados) {
		if (pares.second.second) {
			deportesAparecieron.at(pares.second.first)++;
		}
	}
	vector <pair<string, int>> v1;
	for (auto pares : deportesAparecieron) {
		v1.push_back(pares);
	}
	sort(v1.begin(), v1.end(), menor);
	for (int i = 0; i < v1.size(); ++i) {
		cout << v1[i].first << " " << v1[i].second << '\n';
	}
	cout << "***\n";
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