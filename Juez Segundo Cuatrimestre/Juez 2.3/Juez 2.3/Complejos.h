
#ifndef COMPLEJOS
#define COMPLEJOS
#include <stdexcept>
#include <math.h>
class Complejos {
public:

	Complejos() {};
	Complejos(float r, float i) :real(r), imaginaria(i) {
		
	}
	Complejos operator +(Complejos const & complejo) const
	{
		return Complejos(real + complejo.real, imaginaria + complejo.imaginaria);
	}
	Complejos operator *(Complejos const & complejo) const
	{
		Complejos multiplicacion;
		multiplicacion.real = real * complejo.real - imaginaria * complejo.imaginaria;
		multiplicacion.imaginaria = real * complejo.imaginaria + complejo.real*imaginaria;
		return multiplicacion;
	}
	float mod(Complejos const & complejo) const
	{
		float modulo = sqrt(complejo.real*complejo.real + complejo.imaginaria*complejo.imaginaria);
		return modulo;
	}
private:
	float real, imaginaria;

};


#endif