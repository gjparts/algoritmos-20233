#ifndef PILA_H
#define PILA_H

#include<iostream>
#include "nodo.h"
using namespace std;

class Pila{
	private:
		//atributos privados de la Pila
		Nodo *tope;	//la cima de la Pila
		int longitud;	//numero de nodos en la Pila
	public:
		//constructor de la Pila
		Pila(){
			//una nueva Pila no tiene Nodos por lo tanto
			//el tope inicia apuntando a NULL
			this->tope = NULL;
			//longitud es CERO
			this->longitud = 0;
		}
		//metodos
		//READ: obtener la longitud (get)
		int getLongitud(){
			return this->longitud;
		}
		//READ: obtener el tope (get)
		Nodo *peek(){
			return this->tope;
		}
		//CREATE: agregar un nuevo Nodo a la pila (push o apilar)
		void push(string valor){
			//crear nuevo Nodo con el valor proporcionado
			Nodo *nuevo = new Nodo(valor);
			//el siguiente Nodo del nuevo Nodo es el Nodo que tiene el tope
			nuevo->siguiente = this->tope;
			//ahora el tope pasa a ser el nuevo Nodo
			this->tope = nuevo;
			//sumar 1 a la longitud de la estructura
			this->longitud++;
		}
		//READ: imprimir una representacion grafica de la Pila
		void imprimir(){
			//partimos desde el tope de la pila y bajamos Nodo por Nodo
			//hasta llegar al Nodo cuyo siguiente Nodo sea NULL
			//(ese es el Nodo que esta al fondo de la Pila)
			Nodo *tmp = this->tope;
			
			cout << "**********************************" << endl;
			cout << "tope =>";
			while( tmp != NULL ){
				cout << "\t" << tmp->valor << endl;
				
				tmp = tmp->siguiente;
			}
		}
		//READ/DELETE: desapilar (conocido como pop)
		//toma el elemento que esta en el tope, lo extrae de la Pila
		//y lo retorna al programador
		Nodo *pop(){
			//validar que la pila tenga elementos, si no tiene retornamos NULL
			if( this->longitud == 0 )
				return NULL;
			else{
				//hay elementos en la Pila: colocar el tope actual en un Nodo temporal
				Nodo *tmp = this->tope;
				//mover el tope al Nodo sigiente del tope actual
				this->tope = tmp->siguiente;    //this->tope = this->tope->siguiente;
				//apuntar el Nodo siguiente del Nodo temporal
				//hacia NULL para romper la relacion con la Pila
				tmp->siguiente = NULL;
				//restar 1 a la longitud
				this->longitud--;
				
				//retornar el nodo desapilado (tmp) para que el programador
				//haga con el lo que guste
				return tmp;
			}
		}
};

#endif
