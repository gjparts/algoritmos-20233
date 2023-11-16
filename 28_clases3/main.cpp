#include<iostream>
#include "Empleado.h"
using namespace std;

int main(){
	Empleado *p1 = new Empleado("Gerardo",41,1000);
	cout << p1->nombre << endl;
	//cout << p1->edad << endl;
	/*try{
		p1->setEdad(-12);
	}catch(exception ex){
		cout << "error en la edad" <<endl;
	}*/
	//p1->setEdad(-12);
	cout << p1->getEdad() << endl;
	p1->setEdad(45);
	cout << p1->getEdad() << endl;
	
	p1->setGenero('M');
	cout << p1->getGenero() << endl;
	
	return 345;
}
