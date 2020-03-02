// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class modificarLista :public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	void modificar()
	{
		int tam = this->size();
		Nodo *anterior = this->prim;
		Nodo *act = anterior->sig;

		while (act != nullptr)
		{
			
			if (act->elem % anterior->elem == 0)
			{
				act = act->sig;
				anterior->sig = act;
				--this->nelems;
			}
			else
			{
				anterior = act;
				act = act->sig;
			}
		}

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