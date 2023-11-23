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
	
	cout << p1->getSalario() << endl;
	p1->setSalario(15000);
	cout << p1->getSalario() << endl;
	
	cout << p1->getContrato() << endl;
	p1->setContrato('P');
	cout << p1->getContrato() << endl;
	
	Empleado *p2 = new Empleado("Filomeno Colinas",78,'M',9000,'P');
	p2->imprimir();
	
	
	return 345;
}
