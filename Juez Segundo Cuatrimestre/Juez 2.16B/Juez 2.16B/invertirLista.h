// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class invertirLista :public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	void invertir() {
		int tam = this->nelems;
		if (tam == 2) //Para colas de 2 elementos
		{
			Nodo *act = this->prim->sig;
			act->sig = this->prim;
			this->prim->sig = nullptr;
			this->prim = act;
			this->ult = act->sig;
		}
		else if (tam > 2) //Para colas de mas de 2 elementos
		{
			Nodo *ant = this->prim;
			Nodo *act = ant->sig;
			Nodo *siguiente = act->sig;
			this->prim = act;
			bool continuar = true;
			while (continuar)
			{
				if (siguiente->sig != nullptr) //Si quedan 2 por modificar
				{
					ant->sig = siguiente->sig;
					act->sig = ant;
					ant = siguiente;
					act = siguiente->sig;
					
					if( act->sig != nullptr) //Si minimo queda un elemento
						siguiente = act->sig;
					else //Si ya hemos llegado al final
					{
						act->sig = ant;
						this->ult = ant;
						ant->sig = nullptr;
						continuar = false;
					}
				}
				else //Si queda un solo elemento
				{
					ant->sig = siguiente;
					act->sig = ant;
					this->ult = ant;
					continuar = false;
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

