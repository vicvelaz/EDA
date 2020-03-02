// Victor Velazquez Cabrera
// E68


#ifndef CARNET_PUNTOS_H
#define CARNET_PUNTOS_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <map>
#include <vector>
#include <list>

class carnet_puntos {
	using dni = std::string;
	using puntos = int;
	using contador = int;
private:
	std::unordered_map<dni, puntos> carnet;
	std::unordered_map<puntos, contador> numPuntos;
	const int MAX_PUNTOS = 15;
public:
	void nuevo(std::string dni)
	{
		auto itN = carnet.find(dni);
		if (itN!=carnet.end()) throw std::domain_error("Conductor duplicado");
		else {
			carnet.insert({ dni,MAX_PUNTOS });
			++numPuntos[MAX_PUNTOS];
		}
	}
	void quitar(std::string dni, int puntos)
	{
		auto itQ = carnet.find(dni);
		if (itQ == carnet.end()) throw std::domain_error("Conductor inexistente");
		else {
			--numPuntos[carnet[dni]];
			carnet[dni] -= puntos;
			if (carnet[dni] < 0) 
				carnet[dni] = 0;
			++numPuntos[carnet[dni]];
		}
	}
	int consultar(std::string dni)
	{
		auto itC = carnet.find(dni);
		if (itC == carnet.end()) throw std::domain_error("Conductor inexistente");
		else 
			return carnet[dni];
	}
	int cuantos_con_puntos(int puntos)
	{
		if (puntos < 0 || puntos >MAX_PUNTOS)throw std::domain_error("Puntos no validos");
		return numPuntos[puntos];
	}
	
};
#endif