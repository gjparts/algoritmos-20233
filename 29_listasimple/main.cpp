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
	
	//probar get
	//lo siguiente imprime la direccion de memoria del elemento 2
	cout << l1->get(2) << endl;
	//lo siguiente imprime el valor del elemento 2
	cout << l1->get(2)->value << endl;
	//esto da error:
	//cout << l1->get(-8);
	
	//probar set
	//cambiar el valor del elemento en la posicion 4
	l1->set(4,22);
	l1->print();
	
	//probar pop
	l1->pop(0);
	l1->print();
	
	l1->pop(3);
	l1->print();
	
	//eliminar el ultimo
	l1->pop( l1->getLength()-1 );
	l1->print();
	
	//imprimir el valor del ultimo
	cout << "Valor del ultimo Nodo: " << l1->getLast()->value << endl;
	
	//probar find
	cout << "El valor 100 esta en la posicion: " << l1->find(100) << endl;
	cout << "El valor 80 esta en la posicion: " << l1->find(80) << endl;
	cout << "El valor 3 esta en la posicion: " << l1->find(3) << endl;
	
	return 876;
}
