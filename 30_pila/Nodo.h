#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;

class Nodo{
	private:
	public:
		//atributos publicos
		string value;
		Nodo *next;
		//constructor
		Nodo(string value){
			this->value = value;
			this->next = NULL;
		}
};

#endif
