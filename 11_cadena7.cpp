#include<iostream>
using namespace std;

int main(){
	//arreglos de string
	string lista[] = {"pera","uva","manzana","melon"};
	//obtener un elemento
	cout << lista[1];
	cout << endl;
	//obtener un char de un elemento
	cout << lista[2][3];
	//obtener el tamaño de un string dentro de un arreglo
	cout << endl;
	cout << lista[3].length() << endl;
	
	//imprimir todos los elementos del arreglo
	cout << "*********************************" << endl;
	int tamano = end(lista)-begin(lista);
	for( int i = 0; i < tamano; i++ ){
		cout << lista[i] << endl;
	}
	
	//hacer un programa que imprima cada elemento del arreglo llamado lista
	//pero colocando un asterisco entre cada caracter de cada string.
	for( int i = 0; i < tamano; i++ ){
		for( int j = 0; j < lista[i].length(); j++ ){
			cout << lista[i][j] << "*";
		}
		cout << endl;
	}
}
