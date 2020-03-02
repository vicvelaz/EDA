//Victor Velazquez Cabrera
//E68


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "libros.h"
#include <fstream>
using namespace std;

void realizaOperacion(string operacion, libros& libreria) {
	string libro;
	char aux;
	int ejemplares;
	if (operacion == "nuevoLibro") {
		cin >> ejemplares;
		getline(cin, libro);
		libreria.nuevoLibro(ejemplares, libro);
	}
	else if (operacion == "comprar") {
		getline(cin, libro);
		try {
			libreria.comprar(libro);
		}
		catch (invalid_argument ia) {
			cout << ia.what() << '\n';
			cout << "---\n";
		}
		catch (out_of_range o) {
			cout << o.what() << '\n';
			cout << "---\n";
		}
	}
	else if (operacion == "estaLibro") {
		getline(cin, libro);
		if (libreria.estaLibro(libro)) cout << "El libro " << libro << " esta en el sistema\n";
		else cout << "No existe el libro " << libro << " en el sistema\n";
		cout << "---\n";
	}
	else if (operacion == "elimLibro") {
		getline(cin, libro);
		libreria.elimLibro(libro);
	}
	else if (operacion == "numEjemplares") {
		getline(cin, libro);
		try {
			int ejem = libreria.numEjemplares(libro);
			cout << "Existen " << ejem << " ejemplares del libro " << libro << '\n';
			cout << "---\n";
		}
		catch (invalid_argument ia) {
			cout << "No existe el libro " << libro << " en el sistema\n";
			cout << "---\n";
		}
	}
	else if (operacion == "top10") {
		list<string> l = libreria.top10();
		for (auto it = l.begin(); it != l.end(); it++) {
			cout << *it << '\n';
		}
		cout << "---\n";
	}

}



bool resuelveCaso() {
	int operaciones;
	cin >> operaciones;
	if (!std::cin)
		return false;
	libros libreria;
	string operacion;
	for (int i = 0; i < operaciones; ++i) {
		cin >> operacion;
		realizaOperacion(operacion, libreria);
	}
	cout << "------\n";
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