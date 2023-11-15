#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<iostream>
using namespace std;

class Empleado{
	private:
	public:
		//atributos publicos
		string nombre;
		int edad;
		char genero;
		double salario;
		char contrato;
		//constructores
		//constructor sin parametros
		Empleado(){
			this->nombre = "No tiene";
			this->edad = 0;
			this->genero = 'X';
			this->salario = 0.00;
			this->contrato = 'T';
		}
		//constructor con 5 parametros
		Empleado(string nombre, int edad, char genero, double salario, char contrato){
			this->nombre = nombre;
			this->edad = edad;
			this->genero = genero;
			this->salario = salario;
			this->contrato = contrato;
		}
		//constructor con 3 parametros
		Empleado(string nombre, int edad, double salario){
			this->nombre = nombre;
			this->edad = edad;
			this->genero = 'X';
			this->salario = salario;
			this->contrato = 'T';
		}
};

#endif
