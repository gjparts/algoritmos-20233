#include<iostream>
#include "Empleado.h"
using namespace std;

int main(){
	Empleado *e1 = new Empleado();
	cout << e1->nombre << endl;
	cout << e1->edad << endl;
	cout << e1->genero << endl;
	cout << e1->salario << endl;
	cout << e1->contrato << endl;
	cout << "*******************************" << endl;
	
	Empleado *e2 = new Empleado("Gerardo",41,10000);
	cout << e2->nombre << endl;
	cout << e2->edad << endl;
	cout << e2->genero << endl;
	cout << e2->salario << endl;
	cout << e2->contrato << endl;
	cout << "*******************************" << endl;
	
	Empleado *e3 = new Empleado("Josue",12,'M',10,'P');
	cout << e3->nombre << endl;
	cout << e3->edad << endl;
	cout << e3->genero << endl;
	cout << e3->salario << endl;
	cout << e3->contrato << endl;
	cout << "*******************************" << endl;
	
	
	return 456;
}
