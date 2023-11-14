#include<iostream>
#include "Persona.h"
using namespace std;

int main(){
	//instanciar un nuevo objeto de clase Persona llamado p1
	//utilizando su constructor sin parametros
	Persona *p1 = new Persona();
	cout << "El nombre de p1 es " << p1->nombre << endl;
	cout << "La edad de p1 es " << p1->edad << endl;
	cout << "El genero de p1 es " << p1->genero << endl;
	cout << "El estado civil de p1 es " << p1->estadoCivil << endl;
	
	//cambiar el nombre y genero de p1
	p1->nombre = "Gerardo";
	p1->genero = 'M';
	cout << "*****************************************" << endl;
	cout << "El nombre de p1 es " << p1->nombre << endl;
	cout << "El genero de p1 es " << p1->genero << endl;
	
	//instanciar un objeto Persona con su constructor con 4 parametros
	cout << "*****************************************" << endl;
	Persona *p2 = new Persona("Josue",11,'M','S');
	cout << "El nombre de p2 es " << p2->nombre << endl;
	cout << "La edad de p2 es " << p2->edad << endl;
	cout << "El genero de p2 es " << p2->genero << endl;
	cout << "El estado civil de p2 es " << p2->estadoCivil << endl;
	
	return 123;
}
