#include<iostream>
#include<cmath>
#include<time.h>
using namespace std;

//prototipo de funcion
void arregloMitad( float *arreglo, int tamano);
void arregloAlCuadrado( double *arreglo, int tamano );
void llenarArreglo( int *arreglo, int tamano );

int main(){
	//Uso de apuntadores en arreglos
	//Un arreglo es una coleccion de apuntadores a otros elementos
	//consideraciones:
	//a) no se puede calcular el tamaño de un arreglo desde un ambito externo
	//b) cada elemento del arreglo al ser un puntero no necesita colocarle
	//   el simbolo * en el ambito externo.
	//c) cuando se coloca un arreglo apuntado como parametro de una funcion
	//   no se le coloca los []
	//d) cuando se usa la funcion si el parametro es un arreglo, no necesita
	//	 enviar la direccion de memoria (&), ya que el propio arreglo hace referencia
	//	 a una direccion de memoria.
	float arr[] = {1,3,5,7,9};
	cout << "La direccion de memoria de arr es: " << arr << endl;
	arregloMitad(arr,end(arr)-begin(arr));
	for( int i = 0; i < end(arr)-begin(arr); i++ ){
		cout << arr[i] << endl;
	}
	
	double arreglox[] = {2.5, 3, 4.8, 9.4};
	cout << "antes de evelar al cuadrado: " << endl;
	for( int i = 0; i < end(arreglox)-begin(arreglox); i++ ){
		cout << arreglox[i] << endl;
	}
	arregloAlCuadrado(arreglox, end(arreglox)-begin(arreglox) );
	cout << "despues de evelar al cuadrado: " << endl;
	for( int i = 0; i < end(arreglox)-begin(arreglox); i++ ){
		cout << arreglox[i] << endl;
	}
	int arregloz[15];
	llenarArreglo(arregloz, end(arregloz)-begin(arregloz) );
	for( int i = 0; i < end(arregloz)-begin(arregloz); i++ ){
		cout << arregloz[i] << endl;
	}
	
	return 765;
}

/*hacer una funcion void que reciba un arreglo de numeros float como apuntador
y que divida todos sus elementos entre 2 alterando al arreglo original*/
void arregloMitad( float *arreglo, int tamano){
	for( int i = 0; i < tamano; i++ ){
		arreglo[i] = arreglo[i]/2;
	}
}
/*
Hacer una funcion void que le enviemos un arreglo apuntado
	de numeros double y que le altere todos sus elementos
	elevando cada uno de ellos al cuadrado.
	desde el main: imprimir el arreglo antes y despues
	de aplicarle la funcion*/
void arregloAlCuadrado( double *arreglo, int tamano ){
	for( int i = 0; i < tamano; i++ ){
		arreglo[i] = arreglo[i]*arreglo[i]; //arreglo[i] = pow(arreglo[i],2);
	}
}

/*hacer una funcion void que llene todos los elementos de
un arreglo apuntado de numeros enteros con numeros
al azar entre 1 y 99.*/
void llenarArreglo( int *arreglo, int tamano ){
	//generador de numeros al azar
	srand( time(NULL) );
	for( int i = 0; i < tamano; i++ ){
		arreglo[i] = rand()%(99-1+1)+1;
	}
}


