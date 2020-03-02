//Victor Velazquez Cabrera
//E68

#ifndef CondicionEliminar_H
#define CondicionEliminar_H
#include "Persona.h"
class condicionEliminar {
private:
	int minIntervalo, maxIntervalo;
public:
	condicionEliminar(int min, int max) : minIntervalo(min), maxIntervalo(max) {}
	bool operator()(persona p) {
		return (minIntervalo > p.getEdad() || p.getEdad() > maxIntervalo);
	}
};
#endif