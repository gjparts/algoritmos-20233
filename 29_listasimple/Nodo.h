#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;

class Nodo{
	private:
	public:
		//atributos publicos
		int value;  //valor del Nodo actual
		Nodo *next; //apuntador al siguiente objeto Nodo
		//constructor
		Nodo(int value){
			this->value = value;
			this->next = NULL; //Nodo siguiente hasta este momento
							   //sera NULL
		}
};

#endif
