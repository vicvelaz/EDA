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
	const int MAX_PUNTOS = 15;
	struct info {
		std::list<dni> DNIs;
		contador cont;
	};
private:
	std::map<dni, puntos> carnet;
	std::unordered_map<puntos, info> numPuntos;

public:
	void nuevo(std::string dni)
	{
		auto itN = carnet.find(dni);
		if (itN != carnet.end()) throw std::domain_error("Conductor duplicado");
		else {
			carnet.insert({ dni,MAX_PUNTOS });
			++numPuntos[MAX_PUNTOS].cont;
			numPuntos[MAX_PUNTOS].DNIs.push_front(dni);
		}
	}
	void quitar(std::string dni, int puntos)
	{
		auto itQ = carnet.find(dni);
		if (itQ == carnet.end()) throw std::domain_error("Conductor inexistente");
		else if (carnet[dni] > 0) {
			auto itQ1 = numPuntos[itQ->second];
			--numPuntos[carnet[dni]].cont;
			numPuntos[carnet[dni]].DNIs.remove(dni);
			carnet[dni] -= puntos;
			if (carnet[dni] < 0)
				carnet[dni] = 0;

			++numPuntos[carnet[dni]].cont;
			numPuntos[carnet[dni]].DNIs.push_front(dni);
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
		return numPuntos[puntos].cont;
	}
	void recuperar(std::string dni, int puntos)
	{
		auto itR = carnet.find(dni);
		if (itR == carnet.end()) throw std::domain_error("Conductor inexistente");
		else if(itR->second==MAX_PUNTOS){}
		else {
			auto itR2 = numPuntos.find(itR->second);
			--numPuntos[carnet[dni]].cont;//--itR2->second.cont;
			numPuntos[carnet[dni]].DNIs.remove(dni);//itR2->second.DNIs.remove(dni);
			carnet[dni] += puntos;//itR->second += puntos;
			if (itR->second > MAX_PUNTOS)
				carnet[dni] = MAX_PUNTOS;//
			++numPuntos[carnet[dni]].cont;//++itR2->second.cont;
			numPuntos[carnet[dni]].DNIs.push_front(dni);//itR2->second.DNIs.push_front(dni);
		}
	}
	std::list<dni> lista_por_puntos(int puntos)
	{
		if (puntos < 0 || puntos >MAX_PUNTOS)throw std::domain_error("Puntos no validos");
		//std::list <dni> const &l=numPuntos[puntos].DNIs;
		std::list <dni> l;
		for (auto &it : numPuntos[puntos].DNIs)
			l.push_back(it);
		return l;
	}

};
#endif