// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class listaExtendida :public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	int buscar(int const &veces, int const &num)
	{
		int cont = 0;
		int tam = this->size();
		Nodo *act = this->prim;
		for (int i = 1; i < tam+1; ++i)
		{
			if (act->elem == num)
			{
				cont++;
				if (cont == veces)
					return i;
			}
			act = act->sig;
		}
		return -1;
	}
	void imprimir()
	{
		Nodo *act = this->prim;
		while (act != nullptr)
		{
			std::cout << act->elem << " ";
			act = act->sig;
		}
		std::cout << std::endl;
	}
};