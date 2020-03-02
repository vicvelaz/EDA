// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class queue_ext :public queue<T> {

	using Nodo = typename queue<T>::Nodo;
public:

	void eliminarCadaDos() {
		int tam = this->nelems;
		if (tam ==2) //Si tiene 2 elementos
		{
			this->prim->sig = nullptr; //elimina el puntero al segundo elemento
			this->ult = this->prim; //el puntero al ultimo elemento apunta al primer elemento
		}
		else if  (tam > 2)
		{
			Nodo *ant = this->prim;
			Nodo *siguiente = ant->sig->sig;
			bool continuar = true;
			while (continuar)
			{
				ant->sig->sig = nullptr;
				ant->sig = siguiente;
				if (siguiente->sig == nullptr)
				{
					this->ult = siguiente;
					continuar = false;
				}
				else if (siguiente->sig->sig == nullptr)
				{
					siguiente->sig = nullptr;
					this->ult = siguiente;
					continuar = false;
				}
				else {
					ant = siguiente;
					siguiente = siguiente->sig->sig;
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

