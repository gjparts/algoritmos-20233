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
		//push (apilar)
		void push(string valor){
			//crear un nuevo Nodo
			Nodo *nuevo = new Nodo(valor);
			//siguiente Nodo del nuevo Nodo apuntarlo al Nodo Tope
			nuevo->next = this->top;
			//ahora el tope pasa a ser el nuevo Nodo
			this->top = nuevo;
			//sumar 1 a la longitud
			this->length++;
		}
		//print (read)
		void print(){
			//comenzamos desde el tope
			Nodo *tmp = this->top;
			
			while( tmp != NULL ){
				cout << tmp->value << endl;
				
				tmp = tmp->next;
			}
			cout << "////////////////////////////////////" << endl;
		}
		//pop (desapilar)
		Nodo *pop(){
			//si la longitud de la pila es CERO, retornamos NULL (no sigue)
			if( this->length == 0 ) return NULL;
			
			//apuntar el Nodo a extraer hacia el Tope
			Nodo *extraer = this->top;
			//el nuevo Tope es el siguiente Nodo del Tope
			this->top = this->top->next;
			//romper la relacion del Nodo a extraer con la Pila
			extraer->next = NULL;
			//restar 1 a la longitud
			this->length--;
			//retornar el Nodo extraido
			return extraer;
		}
};

#endif
