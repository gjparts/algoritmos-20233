#include<iostream>
using namespace std;

int main(){
	//Arreglos (estructuras de datos estaticas, secuenciales, homogeneas)
	//los arreglos se numeran desde 0 hasta N-1 (zero indexing)
	
	//no es posible tener 1 millon de posiciones
	//secuenciales para almacenar enteros.
	//int arreglo1[1000000];
	
	//declaracion de arreglos
	//forma 1: declarar un arreglo sin inicializar
	int arreglo1[5];
	arreglo1[0] = 45;
	arreglo1[1] = 5;
	arreglo1[2] = 100;
	arreglo1[3] = 1111;
	arreglo1[4] = 85;
	
	//que valores hay en cada posicion del arreglo?
	for( int i = 0; i < 5; i++ ){
		cout << arreglo1[i] << endl;
	}
	
	//forma 2: declarar un arreglo prellenado
	int arreglo2[] = { 1, 3, 8, 99, 2, 56, 84, 98, 79, 113 };
	cout << "********************************" << endl;
	for( int i = 0; i < 10; i++ ){
		cout << arreglo2[i] << endl;
	}
	
	/*obtener el tamaño de un arreglo, es necesaria la version 11
	del namespace standard, colocar parametro -std=c++11*/
	int tamano = end(arreglo2)-begin(arreglo2);
	cout << "Tamano del arreglo2: " << tamano << endl;
	cout << "arreglo2 comienza en: " << begin(arreglo2) << endl;
	cout << "arreglo2 termina en: " << end(arreglo2) << endl;
	
	//imprimir arreglo 2 usando el tamaño que calculamos
	cout << "********************************" << endl;
	for( int i = 0; i < tamano; i++ ){
		cout << arreglo2[i] << endl;
	}
	
	return 321;
}






