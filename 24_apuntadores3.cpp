#include<iostream>
#include<cmath>
using namespace std;

//prototipo de funcion
void arregloMitad( float *arreglo, int tamano);

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
	
	return 765;
}

/*hacer una funcion void que reciba un arreglo de numeros float como apuntador
y que divida todos sus elementos entre 2 alterando al arreglo original*/
void arregloMitad( float *arreglo, int tamano){
	for( int i = 0; i < tamano; i++ ){
		arreglo[i] = arreglo[i]/2;
	}
}
