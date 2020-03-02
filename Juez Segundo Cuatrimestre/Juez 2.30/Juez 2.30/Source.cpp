//Victor Velazquez Cabrera
//E68
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>


void variacionesEnDiccionario(std::map <std::string, int> const& dic1, std::map <std::string, int> const& dic2, std::vector <std::string> & nuevos, std::vector <std::string> & quitados, std::vector <std::string> & modificados) {

	auto it1 = dic1.begin();
	auto it2 = dic2.begin();
	while (it1 != dic1.end() || it2 != dic2.end()) {
		if (it1 == dic1.end()) {
			nuevos.push_back(it2->first);
			it2++;
		}
		else if (it2 == dic2.end()) {
			quitados.push_back(it1->first);
			it1++;
		}
		else {
			if (it1->first == it2->first && it1->second != it2->second) {
				modificados.push_back(it1->first);
				it1++;
				it2++;
			}
			else if (it1->first > it2->first) {
				nuevos.push_back(it2->first);
				it2++;
			}
			else if (it1->first < it2->first) {
				quitados.push_back(it1->first);
				it1++;
			}
			else {
				it1++;
				it2++;
			}
		}
	}
}



void resuelveCaso() {
	std::string linea1, linea2;
	std::getline(std::cin, linea1);
	std::stringstream ss;
	ss << linea1;
	std::string clave;
	int valor;
	std::map <std::string, int> dic1, dic2;
	while (ss >> clave >> valor) {
		dic1.insert({ clave, valor });
	}
	std::getline(std::cin, linea2);
	ss.clear();
	ss << linea2;
	while (ss >> clave >> valor) {
		dic2.insert({ clave, valor });
	}

	std::vector <std::string> nuevos;
	std::vector <std::string> quitados;
	std::vector <std::string> modificados;
	variacionesEnDiccionario(dic1, dic2, nuevos, quitados, modificados);
	
	if (nuevos.size() == 0 && quitados.size() == 0 && modificados.size() == 0)
		std::cout << "Sin cambios\n";

	else {
		if (nuevos.size() > 0) {
			std::cout << "+ ";
			for (int i = 0; i < nuevos.size(); ++i) {
				std::cout << nuevos[i];
				if (i < nuevos.size())
					std::cout << " ";
			}
			std::cout << '\n';
		}

		if (quitados.size() > 0) {
			std::cout << "- ";
			for (int i = 0; i < quitados.size(); ++i) {
				std::cout << quitados[i];
				if (i < quitados.size()) 
					std::cout << " ";
			}
			std::cout << '\n';
		}

		if (modificados.size() > 0) {
			std::cout << "* ";
			for (int i = 0; i < modificados.size(); ++i) {
				std::cout << modificados[i];
				if (i < modificados.size()) 
					std::cout << " ";
			}
			std::cout << '\n';
		}
	}
	std::cout << "----\n";
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
	std::cin.ignore();
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}