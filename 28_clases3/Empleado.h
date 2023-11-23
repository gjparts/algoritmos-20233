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
			this->setSalario(0.00); //usar el set para respetar las reglas
			this->setContrato('T'); //usar el set para respetar las reglas
		}
		//constructor con 5 parametros
		Empleado(string nombre, int edad, char genero, double salario, char contrato){
			this->nombre = nombre;
			this->setEdad(edad);	//usar el set para respetar las reglas
			this->setGenero(genero); //usar el set para respetar las reglas
			this->setSalario(salario); //usar el set para respetar las reglas
			this->setContrato(contrato); //usar el set para respetar las reglas
		}
		//constructor con 3 parametros
		Empleado(string nombre, int edad, double salario){
			this->nombre = nombre;
			this->setEdad(edad);	//usar el set para respetar las reglas
			this->setGenero('X'); //usar el set para respetar las reglas
			this->setSalario(salario); //usar el set para respetar las reglas
			this->setContrato('T'); //usar el set para respetar las reglas
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
		void setSalario(double salario){
			if( salario >= 0 )
				this->salario = salario; //se acepta
			else
				throw invalid_argument("Salario debe ser >= 0");
		}
		double getSalario(){
			return this->salario;
		}
		void setContrato( char contrato ){
			if( contrato == 'T' || contrato == 'P' )
				this->contrato= contrato; //se acepta
			else
				throw invalid_argument("Contrato solo acepta: T P");
		}
		char getContrato(){
			return this->contrato;
		}
		//metodos
		//retorna true si edad >= 60 de lo contrario retorna false
		bool terceraEdad(){
			if( this->edad >= 60 )
				return true;
			else
				return false;
		}
		//retorna la descripcion del genero del Empleado
		string getGeneroDescripcion(){
			if( this->genero == 'M' )
				return "Masculino";
			if( this->genero == 'F' )
				return "Femenino";
			if( this->genero == 'X' )
				return "Otros";
			
			//si no se cumple ningun if:
			return "No determinado";
		}
		//imprime la ficha del empleado
		void imprimir(){
			cout << "********** PERFIL DE EMPLEADO **********" << endl;
			cout << "Nombre: " << this->nombre << endl;
			cout << "Edad: " << this->edad << endl;
			cout << "Genero: " << this->getGeneroDescripcion() << endl;
			cout << "Salario: " << this->salario << endl;
			cout << "Contrato: " << this->contrato << endl;
			cout << "Es de la tercera edad: " << ( this->terceraEdad() == true ? "Si" : "No" ) << endl;
		}
};

#endif
