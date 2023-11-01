#include<iostream>
using namespace std;

//prototipos de funcion
void sumarCien(int numero);	//funcion que suma cien a cualquier entero enviado.
void sumarCienUsandoApuntador(int *numero);	//funcion que suma cien a
											//cualquier entero enviado usando puntero.

int main(){
	/*Apuntadores, punteros de memoria o pointers
	Permiten el paso de variables entre ambitos (scope) puesto
	que se refieren a la direccion de memoria de la variable
	y no a su valor.*/
	int x = 10;
	
	cout << "Valor de x antes de ejecutarle sumarCien: " << x << endl;
	sumarCien(x);
	cout << "Valor de x despues de ejecutarle sumarCien: " << x << endl;
	
	//sumarCienUsandoApuntador no recibe solo el valor, sino recibe la referencia
	sumarCienUsandoApuntador(&x);
	cout << "Valor de x despues de ejecutarle sumarCienUsandoApuntador: " << x << endl;
	
	cout << "La direccion de memoria (memory offset) de x es " << &x << endl;
	
	double z = 3.1416;
	cout << "La direccion de memoria (memory offset) de z es " << &z << endl;
	
	return 654;
}

//implementacion de funciones
void sumarCien(int numero){
	numero = numero + 100;
}

void sumarCienUsandoApuntador(int *numero){
	*numero = *numero + 100;
}

