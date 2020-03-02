// Victor Velazquez Cabrera
// E68


#ifndef autoescuela_h
#define autoescuela_h
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <map>
#include <vector>
#include <list>
using namespace std;

class autoescuela {
	using puntuacion = int;
	using alumno = string;
	using profesor = string;
private:
	unordered_map <alumno, pair<profesor, puntuacion>> mapaA;
public:
	void alta(alumno a, profesor p) {
		auto itA = mapaA.find(a);
		if (itA == mapaA.end()) {
			mapaA.insert({ a, { p, 0} });
		}
		else {
			itA->second.first = p;
		}
	}

	bool es_alumno(alumno a, profesor p) {
		auto itA = mapaA.find(a);
		if (itA != mapaA.end() && itA->second.first == p) return true;
		else return false;
	}

	int puntuaciones(alumno a) {
		auto itA = mapaA.find(a);
		if (itA == mapaA.end()) throw domain_error("El alumno " + a + " no esta matriculado");
		else {
			return itA->second.second;
		}
	}

	void actualizar(alumno a, puntuacion n) {
		auto itA = mapaA.find(a);
		if (itA == mapaA.end()) throw domain_error("El alumno " + a + " no esta matriculado");
		else {
			itA->second.second += n;
		}
	}

	list <alumno> examen(profesor p, puntuacion n) {
		list <alumno> v;
		for (auto par : mapaA) {
			if (par.second.second >= n && par.second.first == p) v.push_back(par.first);
		}
		v.sort();
		return v;
	}

	void aprobar(alumno a) {
		auto itA = mapaA.find(a);
		if (itA == mapaA.end()) throw domain_error("El alumno " + a + " no esta matriculado");
		else {
			mapaA.erase(itA);
		}
	}

};
#endif