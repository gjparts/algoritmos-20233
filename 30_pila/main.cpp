#include<iostream>
#include "Nodo.h"
#include "Pila.h"
using namespace std;

int main(){
	Pila *p1 = new Pila();
	p1->push("Caja de Madera");
	p1->push("Caja de Aluminio");
	p1->push("Caja de Hierro");
	p1->push("Caja de Plastico");
	p1->push("Balon");
	
	p1->print();
	cout << "El tope es: " << p1->getTop()->value << endl;
	
	cout << "*******************************" << endl << endl;
	p1->pop();
	p1->pop();
	p1->print();
	cout << "El tope es: " << p1->getTop()->value << endl;
	
	cout << "*******************************" << endl << endl;
	p1->pop();
	p1->pop();
	p1->pop();
	p1->pop();
	p1->pop();
	p1->pop();
	p1->pop();
	p1->pop();
	p1->print();
	
	return 123;
}
