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
		Nodo * nuevo = nullptr;
		for (int i = 0; i < tam; ++i) {
			nuevo = new Nodo(act->elem, act->sig);
			act->sig = nuevo;
			act = nuevo->sig;
		}
		this->ult = nuevo;
		this->nelems *= 2;

		
	};

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
