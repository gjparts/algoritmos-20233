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
	
	//objeto no inicializado
	//Persona *p3;
	//cout << p3->nombre << endl;
	/*Initialization takes time, and C++ (like C) has a
	philosophy of not paying for unused features, so initialization
	is up to the developer.
	Static variables are an exception, and static pointers
	are initialized to nullptr by default. Compile-time
	initialization doesn't cost anything as
	the executable loader is reading in a predefined data
	segment anyway.
	In debug builds, the compiler may initialize
	non-static pointer variables and even memory
	blocks to a known garbage pattern.*/
	
	Persona *p4 = new Persona();
	cout << "El nombre de p4 es " << p4->nombre << endl;
	
	Persona *p5 = new Persona("Viena",15);
	cout << "*****************************************" << endl;
	cout << "El nombre de p5 es " << p5->nombre << endl;
	cout << "La edad de p5 es " << p5->edad << endl;
	cout << "El genero de p5 es " << p5->genero << endl;
	cout << "El estado civil de p5 es " << p5->estadoCivil << endl;
	
	p5->genero = 'F';
	cout << "El genero de p5 es " << p5->genero << endl;
	
	return 123;
}
