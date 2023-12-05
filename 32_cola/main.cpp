#include<iostream>
#include "Nodo.h"
#include "Cola.h"
using namespace std;

int main(){
	Cola *c1 = new Cola();
	c1->encolar("Hugo");
	c1->encolar("Paco");
	c1->encolar("Luis");
	c1->encolar("Pedro");
	c1->encolar("Pablo");
	c1->encolar("Paco");
	c1->encolar("Raul");
	c1->encolar("Mario");
	c1->encolar("Mario Verde");
	
	cout << "Nodos en Cola: " << c1->getLongitud() << endl;
	cout << "El Turno lo tiene: " << c1->getTurno()->valor << endl;
	cout << "Al final esta: " << c1->getUltimo()->valor << endl;
	c1->imprimir();
	
	//desecolar un Nodo y luego imprimir la Cola
	c1->desencolar();
	c1->imprimir();
	
	//desencolar varios Nodos e imprimir
	c1->desencolar();
	c1->desencolar();
	c1->desencolar();
	c1->desencolar();
	c1->imprimir();
	
	//encolar otro mas
	c1->encolar("Fenestacio");
	c1->imprimir();
	
	//desencolar Nodo e imprimir su valor sin usar variable
	cout << "Atender a: " << c1->desencolar()->valor << endl;
	c1->imprimir();
	
	//desencolar Nodo, ponerlo en variable e imprimir su valor
	Nodo *tmp = c1->desencolar();
	if( tmp != NULL )
		cout << "Atender a: " << tmp->valor << endl;
	
	//repetir el proceso reutilizando la variable
	tmp = c1->desencolar();
	if( tmp != NULL )
		cout << "Atender a: " << tmp->valor << endl;
	
	tmp = c1->desencolar();
	if( tmp != NULL )
		cout << "Atender a: " << tmp->valor << endl;
		
	tmp = c1->desencolar();
	if( tmp != NULL )
		cout << "Atender a: " << tmp->valor << endl;
	
	tmp = c1->desencolar();
	if( tmp != NULL )
		cout << "Atender a: " << tmp->valor << endl;
	
	tmp = c1->desencolar();
	if( tmp != NULL )
		cout << "Atender a: " << tmp->valor << endl;
	
	tmp = c1->desencolar();
	if( tmp != NULL )
		cout << "Atender a: " << tmp->valor << endl;
		
	c1->encolar("Ramon");
	c1->imprimir();
	
	return 678;
}







