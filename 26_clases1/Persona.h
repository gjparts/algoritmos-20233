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
};

#endif
