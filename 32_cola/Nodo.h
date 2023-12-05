#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;

class Nodo{
	private:
	public:
		string valor;
		Nodo *siguiente;
		Nodo(string valor){
			this->valor = valor;
			this->siguiente = NULL;
		}
};

#endif
