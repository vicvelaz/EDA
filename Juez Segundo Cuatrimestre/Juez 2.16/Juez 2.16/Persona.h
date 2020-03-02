//Victor Velazquez Cabrera
//E68

#ifndef Persona_h
#define Persona_h
#include <iostream>
#include <string>
#include "lista_eda.h"

class persona {
private:
	std::string nombre;
	int edad;
public:
	persona() {}
	persona(int ed, std::string nom) : edad(ed), nombre(nom) {}
	std::string getNombre() {
		return nombre;
	}
	int getEdad() {
		return edad;
	}

};

inline std::ostream &operator << (std::ostream & out, persona persona1) {
	std::string cad = persona1.getNombre();
	out << cad.substr(1, cad.size()) << '\n';
	return out;
}

#endif