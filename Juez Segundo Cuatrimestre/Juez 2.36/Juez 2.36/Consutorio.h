//Victor Velazquez Cabrera
//E68


#ifndef Consultorio_h
#define Consultorio_h

#include <iostream>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <list>
#include "Fecha.h"
using namespace std;

class consultorio {
private:
	unordered_map <string, map<fecha, string>> mapaMedicos;
public:
	void nuevoMedico(string m) {
		map<fecha, string> consultas;
		auto itM = mapaMedicos.find(m);
		if (itM == mapaMedicos.end()) mapaMedicos.insert({ m, consultas });
	}
	void pideConsulta(string p, string m, fecha f) {
		auto itM = mapaMedicos.find(m);
		if (itM == mapaMedicos.end()) throw invalid_argument("Medico no existente");
		else {
			auto itA = itM->second.find(f);
			if (itA != itM->second.end()) throw invalid_argument("Fecha ocupada");
			else itM->second.insert(itA, { f, p });
		}
	}

	string siguientePaciente(string m) {
		auto itM = mapaMedicos.find(m);
		if (itM == mapaMedicos.end()) throw invalid_argument("Medico no existente");
		else {
			if (itM->second.empty()) throw invalid_argument("No hay pacientes");
			else return itM->second.begin()->second;
		}
	}

	void atiendeConsulta(string m) {
		auto itM = mapaMedicos.find(m);
		if (itM == mapaMedicos.end()) throw invalid_argument("Medico no existente");
		else {
			if (mapaMedicos[m].empty()) throw invalid_argument("No hay pacientes");
			else {
				fecha primeraConsulta = itM->second.begin()->first;
				itM->second.erase(primeraConsulta);
			}
		}
	}
	list<pair<fecha, string>> listaPacientes(string m, int d) {
		auto itM = mapaMedicos.find(m);
		if (itM == mapaMedicos.end()) throw invalid_argument("Medico no existente");
		else {
			list<pair<fecha, string>> lista;
			for (auto par : itM->second) {
				fecha actual = par.first;
				if (actual.getDia() == d) lista.push_back(par);
			}
			return lista;
		}
	}
};


#endif