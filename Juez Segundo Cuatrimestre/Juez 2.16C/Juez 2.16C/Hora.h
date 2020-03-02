// Victor Velazquez Cabrera
// E68

#ifndef HORA
#define HORA
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iomanip>

class Hora {
public:
	Hora() {};
	Hora(int h, int m, int s) : horas(h), minutos(m), segundos(s) {
		if (h < 0 || h>23) throw std::invalid_argument("ERROR");
		else if (m < 0 || m>59) throw std::invalid_argument("ERROR");
		else if (s < 0 || s>59) throw std::invalid_argument("ERROR");
	};
	int get_hora() const { return horas; };
	int get_minutos() const { return minutos; };
	int get_segundos()const { return segundos; };

	int horaSalida(std::vector<Hora> const &h1)
	{
		int i = 0;
		bool encontrado = false;
		while (i < h1.size() && !encontrado)
		{
			if (h1[i] < *this)
				++i;
			else
				encontrado = true;
		}
		if (i >= h1.size()) throw std::range_error("NO");
		return i;
	}
	bool operator < (Hora const & hora) const
	{
		if (horas < hora.horas) return true;
		else if (horas > hora.horas) return false;
		else if (minutos < hora.minutos)return true;
		else if (minutos > hora.minutos) return false;
		else if (segundos < hora.segundos) return true;
		else return false;
	}
	bool operator == (Hora const & hora) const
	{
		if ((horas == hora.horas) && (minutos == hora.minutos) && (segundos == hora.segundos))
			return true;
		else
			return false;
	}
	Hora operator + (Hora const & hora) const
	{
		Hora suma(0, 0, 0);
		if (segundos + hora.segundos < 60)
			suma.segundos = segundos + hora.segundos;
		else //if (segundos + hora.segundos >= 60)
		{
			++suma.minutos;
			suma.segundos = segundos + hora.segundos - 60;
		}
		if (minutos + hora.minutos + suma.minutos < 60)
			suma.minutos += minutos + hora.minutos;
		else //if (minutos + hora.minutos+suma.minutos >= 60)
		{
			++suma.horas;
			suma.minutos += minutos + hora.minutos - 60;
		}
		suma.horas += horas + hora.horas;
		return suma;
	}


private:
	int horas, minutos, segundos;
};
inline std::ostream & operator << (std::ostream & out, Hora const & hora) {
	std::cout << std::setfill('0') << std::setw(2) << hora.get_hora() << ":"
		<< std::setfill('0') << std::setw(2) << hora.get_minutos() << ":"
		<< std::setfill('0') << std::setw(2) << hora.get_segundos();
	return out;
};
inline std::istream & operator >> (std::istream & in, Hora & hora) { //istream para que pueda ser diferentes a ficheros
	int horas, minutos, segundos;
	char puntos;
	std::cin >> horas >> puntos >> minutos >> puntos >> segundos;
	hora = Hora(horas, minutos, segundos);
	return in;
};

#endif