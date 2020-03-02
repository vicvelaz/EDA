#ifndef MEZCLARLISTA_H
#define MEZCLRLISTA
// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class mezclarLista : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void mezclarL(mezclarLista & l)
	{

		if (this->size() == 0)
		{
			this->prim = l.prim;
			this->ult = l.ult;
		}
		else if (l.size() == 0)
		{

		}
		else
		{
			Nodo *act1 = this->prim;
			Nodo *act2 = l.prim;
			Nodo *sig1 = act1->sig;
			Nodo *sig2 = act2->sig;
			if (act2 < act1)
			{
				this->prim = act2;
				act2->sig = act1;
				act1 = act2;
				sig1 = act1;
				act2 = sig2;
				sig2 = sig2->sig;
			}
			while (sig1 != nullptr&&sig2 != nullptr)
			{
				if (act1->elem < act2->elem)
				{
					act1 = sig1;
					sig1 = sig1->sig;
				}
				else
				{
					act2->sig = sig1;
					act1->sig = act2;
					act1 = sig1;
					 sig1 = sig1->sig;
					act2 = sig2;
					
					sig2 = sig2->sig;
				}
			}
			if (act2 != nullptr)
			{
				this->ult->sig = act2;
				this->ult = l.ult;
			}


			l.prim = nullptr;
		}

	}


	void imprimir() {
		Nodo *act = this->prim;
		while (act != nullptr)
		{
			std::cout << act->elem << " ";
			act = act->sig;
		}
		std::cout << '\n';
	}
};


#endif 