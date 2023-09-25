#include<iostream>
using namespace std;

int main(){
	//cadenas de texto
	char a = 'y';
	cout << a << endl;
	
	string b = "Gerardo";
	cout << b << endl;
	
	//acceder a los elementos de un string
	cout << b[0] << endl;
	cout << b[1] << endl;
	cout << b[5] << endl;
	
	//reemplazar un char en el string en determinada posicion
	b[0] = 'J';
	cout << b << endl;
	
	//incrustar un string adicional a la cadena
	b = b+" Portillo";
	cout << b << endl;
	
	//obtener el tamaño de una cadena
	cout << "Tamaño de la cadena b: " << b.length() << endl;
	
	//imprimir el string un caracter por linea
	for( int i = 0; i < b.length(); i++ ){
		cout << b[i] << endl;
	}
	
	return 747;
}






