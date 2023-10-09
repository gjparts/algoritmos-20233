#include<iostream>
using namespace std;

int main(){
	/*Hacer un programa que calcule e imprima el promedio de 3 numeros double.
	Validar que los valores digitados sean numeros si es asi entonces
	imprimir el promedio, de lo contrario imprimir un mensaje
	indicando que alguno de los valores proporcionados no es correcto.*/
	
	try{
		double a, b, c;
		string v1, v2, v3;
		//capturar los numeros; pero como cadena
		cout << "Digitar a: ";
		getline(cin,v1);
		cout << "Digitar b: ";
		getline(cin,v2);
		cout << "Digitar c: ";
		getline(cin,v3);
		//tratar de convertir las cadenas a numeros double
		//para detectar el error en caso de no ser numeros
		a = stod(v1);
		b = stod(v2);
		c = stod(v3);
		cout << "El promedio es: " << (a+b+c)/3.0 << endl;
	}catch(exception ex){
		cout << "Alguno de los valores proporcionados no es correcto" << endl;
	}
	
	return 321;
}
