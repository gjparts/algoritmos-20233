#include<iostream>
#include "Nodo.h"
#include "ListaSimple.h"
using namespace std;

int main(){
	ListaSimple *l1 = new ListaSimple();
	cout << "longitud: " << l1->getLength() << endl;
	
	l1->push(5);
	l1->push(3);
	l1->push(8);
	cout << "longitud: " << l1->getLength() << endl;
	
	l1->print();
	
	l1->push(6);
	l1->push(100);
	l1->push(80);
	l1->push(45);
	l1->print();
	
	return 876;
}
