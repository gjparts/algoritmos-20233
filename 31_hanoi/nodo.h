#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;

class Nodo
{
	private:
	public:
		//atributos
		string valor;	//valor almancenado en el Nodo
		Nodo *siguiente; //apuntador a Nodo siguiente
		//constructor de la clase
		Nodo(string valor){
			this->valor = valor;
			this->siguiente = NULL;
		}
};

#endif
