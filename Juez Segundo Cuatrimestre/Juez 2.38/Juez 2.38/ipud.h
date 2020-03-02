#ifndef ipud_h
#define ipud_h

#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <map>
#include <vector>
#include <list>

using namespace std;

class ipud {
	using cancion = string;
	using duracion = int;

private:
	unordered_map <cancion, duracion> mapaC;
	list<cancion> listaRep;
	list<cancion> escuchadas;
	unordered_map < cancion, list<cancion>::iterator> mapaRep;
	unordered_map < cancion, list<cancion>::iterator> mapaEsc;
	int tiempoListaRepr = 0;

public:
	void addSong(cancion s, string autor, duracion d) {
		auto it = mapaC.find(s);
		if (it != mapaC.end()) throw domain_error("ERROR");
		else {
			mapaC.insert({ s, d });
		}
	}

	void addToPlaylist(cancion s) {
		auto itC = mapaC.find(s);
		auto itRep = mapaRep.find(s);
		if (itC == mapaC.end()) throw domain_error("ERROR");
		else if (itRep == mapaRep.end()) {
			tiempoListaRepr += itC->second;
			mapaRep.insert({ s, listaRep.insert(listaRep.end(), s) });
		}
	}

	cancion current() {
		if (listaRep.empty())throw domain_error("ERROR");
		else {
			return listaRep.front();
		}
	}

	void play() {
		if (!listaRep.empty()) {
			cancion borrar = listaRep.front();
			listaRep.pop_front();
			mapaRep.erase(borrar);
			auto itEsc = mapaEsc.find(borrar);
			if (itEsc != mapaEsc.end()) {
				escuchadas.erase(itEsc->second);
				mapaEsc.erase(itEsc);
			}
			escuchadas.push_front(borrar);
			mapaEsc.insert({ borrar, escuchadas.begin() });
			tiempoListaRepr -= mapaC[borrar];
			cout << "Sonando " << borrar;
		}
		else cout << "No hay canciones en la lista";
	}

	int totalTime() {
		return tiempoListaRepr;
	}


	list <cancion> recent(int N) {
		int i = 0;
		auto it = escuchadas.begin();
		list<cancion> l;
		while (i < N && it != escuchadas.end()) {
			l.push_back(*it);
			i++;
			it++;
		}
		return l;
	}

	void deleteSong(cancion s) {
		auto itC = mapaC.find(s);
		auto itRep = mapaRep.find(s);
		auto itEsc = mapaEsc.find(s);

		if (itC != mapaC.end()) {
			mapaC.erase(itC);
		}
		if (itRep != mapaRep.end()) {
			tiempoListaRepr -= itC->second;
			listaRep.erase(itRep->second);
			mapaRep.erase(itRep);
		}
		if (itEsc != mapaEsc.end()) {
			escuchadas.erase(itEsc->second);
			mapaEsc.erase(itEsc);
		}
	}
};

#endif