#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<iostream>
#include<stdexcept>
using namespace std;

class Empleado{
	private:
		//atributos privados
		int edad;
		char genero;
		double salario;
		char contrato;
	public:
		//atributos publicos
		string nombre;
		
		//constructores
		//constructor sin parametros
		Empleado(){
			this->nombre = "No tiene";
			this->setEdad(0);	//usar el set para respetar las reglas
			this->setGenero('X'); //usar el set para respetar las reglas
			this->salario = 0.00;
			this->contrato = 'T';
		}
		//constructor con 5 parametros
		Empleado(string nombre, int edad, char genero, double salario, char contrato){
			this->nombre = nombre;
			this->setEdad(edad);	//usar el set para respetar las reglas
			this->setGenero(genero); //usar el set para respetar las reglas
			this->salario = salario;
			this->contrato = contrato;
		}
		//constructor con 3 parametros
		Empleado(string nombre, int edad, double salario){
			this->nombre = nombre;
			this->setEdad(edad);	//usar el set para respetar las reglas
			this->setGenero('X'); //usar el set para respetar las reglas
			this->salario = salario;
			this->contrato = 'T';
		}
		//metodos: son funciones que estan dentro de una clase
		//metodo get: permite obtener el valor dentro de un atributo (normalmente privado)
		//metodo set: permite establecer el valor de un atributo (normalmente privado)
		void setEdad(int edad){
			if( edad >= 0 )
				this->edad = edad; //se acepta
			else
				throw invalid_argument("Edad debe ser >= 0");
		}
		int getEdad(){
			return this->edad;
		}
		void setGenero(char genero){
			if( genero == 'M' || genero == 'F' || genero == 'X' )
				this->genero = genero; //se acepta
			else
				throw invalid_argument("Genero solo acepta: M F X");
		}
		char getGenero(){
			return this->genero;
		}
};

#endif
