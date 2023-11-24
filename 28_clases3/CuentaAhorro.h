#ifndef CUENTAAHORRO_H
#define CUENTAAHORRO_H

#include<iostream>
#include<stdexcept>
using namespace std;

class CuentaAhorro{
	private:
		int edad;
		float saldo;
	public:
		string nombre;
		//constructor
		CuentaAhorro(string nombre, int edad){
			//saldo iniciara en cero
			this->saldo = 0.00;
			this->nombre = nombre;
			this->setEdad(edad);	//usar el set para validar la regla
		}
		//metodos
		void setEdad(int edad){
			if( edad >= 18 )
				this->edad = edad; //se acepta
			else
				throw invalid_argument("Edad debe ser >= 18");
		}
		int getEdad(){
			return this->edad;
		}
		void depositar(float monto){
			//validar que el monto no sea <= 0
			if( monto <= 0 )
				throw invalid_argument("monto a depositar debe ser > 0");
			else
				this->saldo += monto; //sumamos el monto a depositar
		}
		void retirar(float monto){
			//validar que el monto no sea <= 0
			if( monto <= 0 )
				throw invalid_argument("monto a retirar debe ser > 0");
			else{
				if( monto > this->saldo )
					throw invalid_argument("monto a retirar supera al saldo");
				else
					this->saldo -= monto; //restamos el monto a retirar
			}
		}
		float getSaldo(){
			return this->saldo;
		}
};

#endif





