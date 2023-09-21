#include<iostream>
#include<time.h>
using namespace std;

int main(){
	/*EJERCICIO: que hagan un programa que tenga un
	arreglo de enteros de 50 posiciones, llenenlo con
	numeros al azar entre 10 y 90
	y por ultimo lo imprima.*/
	srand(time(NULL));
	
	int arreglo[50];
	int tamano = end(arreglo)-begin(arreglo);
	for( int i = 0; i < tamano; i++ ){
		arreglo[i] = rand()%(90-10+1)+10;
		cout << "Posicion: " << i << ", Valor: " << arreglo[i] << endl;
	}
	
	return 456;
}
