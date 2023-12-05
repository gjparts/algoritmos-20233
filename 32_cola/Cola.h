#ifndef COLA_H
#define COLA_H

#include<iostream>
#include "Nodo.h"
using namespace std;

class Cola{
	private:
		Nodo *turno;
		Nodo *ultimo;
		int longitud;
	public:
		//constructor
		Cola(){
			this->turno = NULL;
			this->ultimo = NULL;
			this->longitud = 0;
		}
		//metodos
		Nodo *getTurno(){
			return this->turno;
		}
		Nodo *getUltimo(){
			return this->ultimo;
		}
		int getLongitud(){
			return this->longitud;
		}
		//encolar (enqueue)
		void encolar(string valor){
			//crear nuevo Nodo
			Nodo *nuevo = new Nodo(valor);
			if( this->longitud == 0 ){
				//escenario 1: no hay Nodos en Cola
				this->turno = nuevo;
				this->ultimo = nuevo;
			}
			else{
				//escenario 2: ya hay Nodos en Cola
				this->ultimo->siguiente = nuevo;
				this->ultimo = nuevo;
			}
			this->longitud++;	//aumentar en 1 la longitud de la Cola
		}
		//imprimir
		void imprimir(){
			if( this->longitud == 0 )
				cout << "Cola Vacia" << endl;
			else{
				//comenzar a recorrer desde el que tiene el turno
				Nodo *tmp = this->turno;
				cout << "(TURNO) ";
				while( tmp != NULL ){
					cout << tmp->valor << "->";
					
					tmp = tmp->siguiente;
				}
				cout << " (ULTIMO)" << endl;
			}
		}
		//desencolar (dequeue)
		Nodo *desencolar(){
			if( this->longitud == 0 )
				return NULL;
			else{
				//apuntar Nodo a extraer hacia Nodo con el turno
				Nodo *extraer = this->turno;
				//el turno pasa al siguiente de quien tenia el turno
				this->turno = this->turno->siguiente;
				//Nodo a extraer su siguiente Nodo apunta a NULL
				//para desasociarlo de la Cola
				extraer->siguiente = NULL;
				//reducir tamaño de la Cola en 1
				this->longitud--;
				//retornar el Nodo a extraer
				return extraer;
			}
		}
};

#endif






