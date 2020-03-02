// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class invertirLista :public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	void invertir(){
		int tam = this->nelems;
		if (tam >1 )
		{
			Nodo *anterior = this->prim;
			Nodo *act = anterior->sig;
			Nodo *siguiente = act->sig;


			for (int i = 1; i < tam; ++i)
			{
				
				if (i == 1)
				{
					this->prim->sig = nullptr;
					act->sig = anterior;

				}
				else {
					anterior = act;
					act = siguiente;
					siguiente = siguiente->sig;
					act->sig = anterior;
					

				}


			}
			this->prim = act;
			this->prim = this->ult;
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

