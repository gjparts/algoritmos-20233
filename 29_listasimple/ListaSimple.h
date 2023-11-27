#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include<iostream>
#include "Nodo.h"
using namespace std;

class ListaSimple{
	private:
		Nodo *first;
		Nodo *last;
		int length;
	public:
		//constructor
		ListaSimple(){
			//lista nueva, fist y last apuntan a NULL
			//length sera cero
			this->first = NULL;
			this->last = NULL;
			this->length = 0;
		}
		//metodos publicos
		int getLength(){
			return this->length;
		}
		Nodo *getFirst(){    //metodos que devuelven objetos deben llevar puntero
			return this->first;
		}
		Nodo *getLast(){
			return this->last;
		}
};

#endif
