#include<iostream>
#include<time.h>
using namespace std;

int main(){
	/*Crear un arreglo bidimensional de 8x5 de numeros
	enteros, llenar cada elemento de dicho arreglo
	con un numero al azar entre 13 y 211.
	Imprimir el arreglo en forma tabular.*/
	
	//generar set de numeros al azar basado en la hora del sistema
	srand( time(NULL) );
	
	int arreglo[8][5];
	int filas = end(arreglo)-begin(arreglo);
	int columnas = end(arreglo[0])-begin(arreglo[0]);
	
	//recorrer el arreglo principal
	for( int i = 0; i < filas; i++ ){
		//recorrer cada arreglo secundario
		for( int j = 0; j < columnas; j++ ){
			//poner numero al azar a cada coordenada
			arreglo[i][j] = rand()%(211-13+1)+13;
			//imprimir el numero generado
			cout << arreglo[i][j] << "\t";
		}
		cout << endl;
	}
	
	return 567;
}
