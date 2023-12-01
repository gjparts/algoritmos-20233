#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include<iostream>
#include<stdexcept>
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
		//push (create, agregar Nodo a la lista)
		/*Algoritmo:
		Si length = 0:
			primero y ultimo apuntan al nuevo Nodo
		si length > 0:
			el siguiente Nodo de ultimo es el nuevo Nodo
			ultimo Nodo pasa a ser el nuevo Nodo
		en ambos casos length suma 1
		*/
		push(int valor){
			//crear nuevo Nodo
			Nodo *nuevo = new Nodo(valor);
			
			//evaluar que sucede en cada escenario
			if( this->length == 0 ){
				this->first = nuevo;
			}
			else{
				this->last->next = nuevo;
			}
			
			this->last = nuevo; //ultimo Nodo pasa a ser el nuevo Nodo
			this->length++;	//sumar 1 al tamaño
		}
		//print (read) imprime una representacion grafica de la lista
		/*Algoritmo de recorrido de una Lista Simple:
		1) crear un Nodo temporal que apunte a first
		2) Si el Nodo temporal es diferente de NULL imprimimos su valor
		   y temporal ahora apunta al nodo siguiente de temporal
		3) Si el Nodo temporal es NULL entonces terminamos*/
		void print(){
			//crear Nodo temporal apuntado a first
			Nodo *tmp = this->first;
			while( tmp != NULL ){
				//tmp es diferente de NULL, imprimimos su value
				cout << tmp->value << "->";
				//avanzar al siguiente Nodo
				tmp = tmp->next;
			}
			//llegamos al final
			cout << "NULL" << endl;
		}
		//get (read) recupera un Nodo en determinada posicion
		//devuelve un objeto de clase Nodo
		Nodo *get(int posicion){
			//recorrer todos los Nodos hasta llegar a la posicion solicitada
			//validar que la posicion solicitada exista
			if( posicion < 0 || posicion >= this->length )
				throw invalid_argument("posicion no valida");
			else{
				//recorrer la lista hasta llegar a la posicion deseada
				Nodo *tmp = this->first;
				
				int actual = 0; //posicion donde nos encontramos
				while( tmp != NULL ){
					//si actual es la posicion deseada
					//retornamos ese Nodo y terminamos
					if( posicion == actual ){
						return tmp;
					}
					
					//pasar al siguiente Nodo
					tmp = tmp->next;
					//sumar 1 a la posicion actual
					actual++;
				}
			}
		}
		//set (update): altera o modifica el valor de un Nodo
		void set(int posicion, int nuevoValor){
			//recuperar el Nodo en la posicion enviada y cambiarle su valor
			this->get(posicion)->value = nuevoValor;
		}
		//pop (delete): eliminar un Nodo de la lista y lo retorna al usuario
		Nodo *pop(int posicion){
			//recuperar el Nodo a eliminar
			Nodo *eliminar = this->get(posicion);
			//pueden ocurrir dos escenarios:
			//1) esta eliminando el primer elemento (posicion 0)
			if( posicion == 0 ){
				//eliminar estaria apuntando a first
				//first pasa a ser el next de first
				this->first = this->first->next;
			}
			else{
				//2) esta eliminando un Nodo que no es el primero (posicion > 0)
				//apuntar al Nodo anterior al Nodo a eliminar
				Nodo *anterior = this->get(posicion-1);
				//el next de anterior pasa a ser el next de eliminar
				anterior->next = eliminar->next;
				//si el Nodo a eliminar es el ultimo (last) ahora
				//el last pasa a ser el Nodo anterior
				if( eliminar == this->last )
					this->last = anterior;
			}
			//apuntar el next de eliminar a NULL
			eliminar->next = NULL;
			//restar 1 a la longitud
			this->length--;
			//retornar el Nodo a eliminar al usuario
			return eliminar;
		}
};

#endif
