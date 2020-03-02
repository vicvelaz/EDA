// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <fstream>
#include <vector>
#include "queue_eda.h"

template<typename T>
class duplicarLista :public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	void duplicar()
	{
		int tam = this->nelems;
		
		Nodo * act = this->prim;
		
		for (int i = 0; i < tam; ++i) {
			Nodo *nuevo = new Nodo(act->elem, act->sig);
			nuevo->sig = act->sig;
			nuevo->elem = act->elem;
			act->sig = nuevo;
			act = nuevo->sig;
		}
		this->nelems *= 2;
};
	void imprimir()
	{
		Nodo *act = this->prim;
		while (act != nullptr)
		{
			std::cout << act->elem <<" ";
			act = act->sig;
		}
		std::cout << std::endl;
	}
};



