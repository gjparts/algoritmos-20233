#include<iostream>
using namespace std;

int main(){
	//arreglos bidimensionales
	//es un arreglo de arreglos
	
	//forma 1: sin inicializar
	int arreglo[4][3];
	//llenarlo a pie (no recomendado)
	arreglo[0][0] = 5; 	arreglo[0][1] = 7; 	arreglo[0][2] = 123;
	arreglo[1][0] = 4; 	arreglo[1][1] = 3; 	arreglo[1][2] = 12;
	arreglo[2][0] = 55; arreglo[2][1] = 12; arreglo[2][2] = 43;
	arreglo[3][0] = 22; arreglo[3][1] = 96; arreglo[3][2] = 20;
	
	//forma 2: usando llaves (prellenado)
	int arreglo2[][3] = {
		{ 1, 2, 3 },
		{ 10, 20, 30 },
		{ 100, 200, 300 },
		{ 1000, 2000, 3000 }
	};
	
	//tamaño del arreglo principal
	int filas = end(arreglo2)-begin(arreglo2);
	//tamaño de cada arreglo secundario
	int columnas = end(arreglo2[0])-begin(arreglo2[0]);
	
	cout << "Filas: " << filas << endl;
	cout << "Columnas: " << columnas << endl;
	
	//imprimir el arreglo de forma tabular
	for( int i = 0; i < filas; i++ )	//recorrer el arreglo principal
	{
		for( int j = 0; j < columnas; j++ ) //recorrer cada arreglo secundario
		{
			cout << arreglo2[i][j] << "\t";
		}
		cout << endl;	//imprimir a linea siguiente
	}
	
	return 23456;
}
