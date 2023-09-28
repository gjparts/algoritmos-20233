#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	/*Hacer un programa que pida al usuario digitar
	dos cadenas de texto y diga
	si son iguales ignorando mayusculas y minusculas.*/
	string a, b;
	cout << "Digite cadena 1: ";
	getline(cin,a);
	cout << "Digite cadena 2: ";
	getline(cin,b);
	
	//sacar copia de ambos string
	string Acopia = a, Bcopia = b;
	
	//convertir ambas copias al mismo character casing
	transform(Acopia.begin(),Acopia.end(), Acopia.begin(), ::toupper);
	transform(Bcopia.begin(),Bcopia.end(), Bcopia.begin(), ::toupper);
	
	if( Acopia == Bcopia )
		cout << "Las cadenas son iguales ignorando el char.casing";
	else
		cout << "Las cadenas NO son iguales";
		
	cout << endl;
	
	return 567;
}
