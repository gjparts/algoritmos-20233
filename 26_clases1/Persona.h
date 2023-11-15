#ifndef PERSONA_H
#define PERSONA_H

#include<iostream>
using namespace std;

class Persona{
	private:
	public:
		//atributos publicos
		string nombre;
		int edad;
		char genero;
		char estadoCivil;
		//constructores
		//constructor sin parametros
		Persona(){
			//inicializar atributos de esta clase
			this->nombre = "No tiene";
			this->edad = 0;
			this->genero = 'X';
			this->estadoCivil = 'S';
		}
		//constructor con 4 parametros
		Persona(string nombre, int edad, char genero, char estadoCivil){
			this->nombre = nombre;			
			this->edad = edad;
			this->genero = genero;
			this->estadoCivil = estadoCivil;
		}
		//constructor con 2 parametros
		Persona(string nombre, int edad){
			this->nombre = nombre;
			this->edad = edad;
			this->genero = 'X';
			this->estadoCivil = 'S';
		}	
};

#endif
