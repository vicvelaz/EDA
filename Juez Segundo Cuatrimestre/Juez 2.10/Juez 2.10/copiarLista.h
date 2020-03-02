// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <fstream>
#include "queue_eda.h"

template<typename T>
 class copiarLista :public queue<T> {

	 using Nodo = typename queue<T>::Nodo;
 public:
	
	 void copiar(copiarLista & laux, int &pos)
	 {

		 if (pos == 0)
		 {
			 laux.ult->sig = this->prim;
			 this->prim = laux.prim;
		 }
		 else
		 {
			 Nodo * act = this->prim;

			 for (int i = 1; i < pos; ++i) {
				 act = act->sig;
			 }
			 laux.ult->sig = act->sig;
			 act->sig = laux.prim;

		 }
		 this->nelems += laux.nelems;
		 laux.prim = nullptr;
		 laux.ult = nullptr;
		 laux.nelems = 0;
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




