#ifndef PELICULA
#define PELICULA
#include "Hora.h"
#include <string>
class Pelicula {
public:
	Pelicula() {};
	Pelicula(Hora h, std::string n) :hora(h), nombre(n) {};

	Hora get_hora() const {return hora; };
	std::string get_nombre() const {return nombre; };
	bool operator < (Pelicula const & pelicula)
	{
		if (hora < pelicula.hora)
			return true;
		else if ((hora == pelicula.hora) && (nombre < pelicula.nombre))
			return true;
		else
			return false;
	}
private:
	Hora hora;
	std::string nombre;
};

inline std::ostream & operator << (std::ostream & out, Pelicula const & pelicula) {
	std::cout << pelicula.get_hora() << " " << pelicula.get_nombre();
	return out;
};


#endif