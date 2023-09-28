#include<iostream>
using namespace std;

int main(){
	//capturar un string
	string cadena1;
	cout << "Digitar cadena de texto: ";
	getline(cin,cadena1);
	cout << "La cadena capturada es: " << cadena1 << endl;
	
	/*EJERCICIO: hacer un programa que imprima un string capturado;
	pero con tres espacios entre cada letra:
	ejm.  HOLA
	resultado:
	H   O   L   A
	*/
	for( int i = 0; i < cadena1.length(); i++ ){
		cout << cadena1[i] << "   ";
	}
	
}
