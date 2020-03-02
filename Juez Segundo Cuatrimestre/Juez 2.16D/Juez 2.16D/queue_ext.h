// Victor Velazquez Cabrera
// E68

#ifndef queue_ext_h
#define queue_ext_h

#include <iostream>
#include <fstream>
#include "queue_eda.h"
#include"Hora.h"

template<typename T>
class queue_ext :public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	void eliminarDecrecientes() {
		int tam = this->nelems;
		Nodo *act = this->prim;
		for (int i = 0; i < tam; ++i)
		{
			if (act->sig==nullptr){ }
			else if	((act->elem < act->sig->elem)|| (act->elem == act->sig->elem))
				act = act->sig;
			else
			{
				if (act->sig->sig == nullptr)
				{
					act->sig = nullptr;
				}
				else
				{
					act->sig = act->sig->sig;
					
				}
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


#endif