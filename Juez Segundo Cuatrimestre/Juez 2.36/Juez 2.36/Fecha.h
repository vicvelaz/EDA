//Victor Velazquez Cabrera
//E68


#ifndef Fecha_h
#define Fecha_h

#include <iostream>
#include <iomanip>
using namespace std;

class fecha {
private:
	int dia;
	int horas;
	int minutos;

public:
	fecha() {}
	fecha(int dia, int horas, int minutos) {
		this->dia = dia;
		this->horas = horas;
		this->minutos = minutos;

	}
	int getHoras() {
		return horas;
	}
	int getMinutos() {
		return minutos;
	}
	int getDia() {
		return dia;
	}

	bool operator<(fecha const& f)const {
		return ((this->dia < f.dia) || (this->dia == f.dia && this->horas < f.horas) || (this->dia == f.dia && this->horas == f.horas && this->minutos < f.minutos));
	}

	bool operator ==(fecha const& f) {
		return ((this->dia == f.dia) && (this->horas == f.horas) && (this->minutos == f.minutos));
	}

};

inline ostream &operator << (ostream & out, fecha &f) {
	out << setfill('0') << setw(2) << f.getHoras() << ":" << setfill('0') << setw(2) << f.getMinutos();
	return out;
}


#endif