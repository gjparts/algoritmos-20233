#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Nodo.h"
using namespace std;

class Pila{
	private:
		//atributos privados
		Nodo *top;
		int length;
	public:
		//constructor
		Pila(){
			//pila nueva, tiene cero Nodos, no tiene tope
			this->length = 0;
			this->top = NULL;
		}
		//metodos
		//obtener la longitud de la Pila
		int getLength(){
			return this->length;
		}
		//obtener el Nodo que esta en el tope de la pila (peek)
		Nodo *getTop(){
			return this->top;
		}
};

#endif
