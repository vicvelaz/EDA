// Victor Velazquez Cabrera
// E68

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "conjunto.h"





bool resuelveCaso() {
	char datos;
	int k;
	std::cin >> datos;
	if (!std::cin)
		return false;
	std::cin >> k;
	if (datos == 'N') {
		set <int> cjto = set<int>(3);
		int elem, pos;
		std::cin >> elem;
		while (elem != -1) {
			if (cjto.size() < k) cjto.insert(elem);
			else if (cjto.lowerElement() < elem && !cjto.contains(elem, pos)) { // En este caso me da iual la posicion. Es por reutilizar la funcion y no hacer otra que solo mire si esta
				cjto.eraseLowerElement();
				cjto.insert(elem);
			}
			std::cin >> elem;
		}
		std::cout << cjto;
	}
	else if (datos == 'P') {
		set <std::string> cjto = set<std::string>(3);
		std::string cadena;
		int pos;
		std::cin >> cadena;
		while (cadena != "FIN") {
			if (cjto.size() < k) cjto.insert(cadena);
			else if (cjto.lowerElement() < cadena && !cjto.contains(cadena, pos)) {
				cjto.eraseLowerElement();
				cjto.insert(cadena);
			}
			std::cin >> cadena;
		}
		std::cout << cjto;
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


	//Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}