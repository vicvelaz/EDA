#ifndef libros_h
#define libros_h

#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <map>
#include <vector>
#include <list>
using namespace std;

class libros {
	using libro = string;
	using ejemplares = int;
	using ventas = int;

private:
	unordered_map <libro, ejemplares> mapaLibros;
	map<int, list<libro>, greater<int>> mapaVentasALibros;
	unordered_map <libro, pair<int, list<libro>::iterator>> librosVendidos;

public:
	void nuevoLibro(ejemplares n, libro x) {
		auto itL = mapaLibros.find(x);
		if (itL == mapaLibros.end()) 
			mapaLibros.insert({ x, n });
		else itL->second += n;
	}

	void comprar(libro x) {
		auto itL = mapaLibros.find(x);
		if (itL == mapaLibros.end()) throw invalid_argument("Libro no existente");
		else {
			if (itL->second <= 0) throw out_of_range("No hay ejemplares");
			else {
				auto itV = librosVendidos.find(x);
				if (itV == librosVendidos.end()) {
					auto it = mapaVentasALibros[1].insert(mapaVentasALibros[1].begin(), x);
					librosVendidos.insert({ x, { 1, it } });
				}
				else {
					int ventasActual = itV->second.first;
					mapaVentasALibros[ventasActual].erase(itV->second.second);
					auto it = mapaVentasALibros[ventasActual + 1].insert(mapaVentasALibros[ventasActual + 1].begin(), x);
					itV->second = { ventasActual + 1, it };
				}
				itL->second--;
			}
		}
	}

	bool estaLibro(libro x) {
		return mapaLibros.count(x);
	}

	void elimLibro(libro x) {
		auto itL = mapaLibros.find(x);
		auto itV = librosVendidos.find(x);
		if (itL != mapaLibros.end()) mapaLibros.erase(itL);
		if (itV != librosVendidos.end()) {
			mapaVentasALibros[itV->second.first].erase(itV->second.second);
			librosVendidos.erase(itV);
		}

	}

	int numEjemplares(libro x) {
		auto itL = mapaLibros.find(x);
		if (itL == mapaLibros.end()) throw invalid_argument("Libro no existente");
		else return itL->second;
	}

	list <libro> top10() {
		list <libro> l;
		auto it = mapaVentasALibros.begin();
		int i = 0;
		while (it != mapaVentasALibros.end() && i < 10) {
			auto itInt = it->second.begin();
			while (itInt != it->second.end() && i < 10) {
				l.push_back(*itInt);
				++i;
				itInt++;
			}
			it++;
		}
		return l;
	}
};

#endif