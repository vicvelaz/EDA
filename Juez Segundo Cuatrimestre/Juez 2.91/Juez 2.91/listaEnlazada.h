#ifndef MEZCLARLISTA_H
#define MEZCLRLISTA
// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <fstream>
#include "deque_eda.h"
//#include "queue_eda.h"

template<typename T>
class engordarLista : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	void engordar(engordarLista & l) {
		int tam = l.size();
		Nodo * act=l.fantasma->sig;
		Nodo* siguiente = act->sig;

		for(int i=0;i<tam;++i)
		{
			//act = l.prim;
			if (i % 2 == 0)
			{
				act->sig = this->fantasma->sig;
				this->fantasma->sig = act;//sig
				//l.fantasma->sig = siguiente;
				/*l.prim = act->sig;
				act->sig = this->prim;
				this->prim = act;*/
			}
			else {
				this->fantasma->ant = act;

				act->sig = this->fantasma;
				//l.fantasma->sig = siguiente;
				/*l.prim = act->sig;
				if (this->ult == nullptr)
					this->ult = this->prim;
				else
					this->ult->sig = act;
				act->sig = nullptr;
				this->ult = act;*/
			}
			if (siguiente != l.fantasma)
			{
				act = siguiente;
				siguiente = siguiente->sig;
			}
			++this->nelems;
		}
		l.fantasma->sig->ant = nullptr;
	}
		


	void imprimir() {
		Nodo *act = this->fantasma->sig;
		while (act != this->fantasma)
		{
			std::cout << act->elem << " ";
			act = act->sig;
		}
		std::cout << '\n';
	}
};


#endif 