#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	//transformar una cadena de texto a mayusculas/minusculas
	string cadena1 = "gErArdo PortilLO";
	//transformar a mayusculas
	//transform aplica el trabajo directamente en la variable
	//se recomienda sacar una copia y trabajar sobre la copia
	//copiar cadena1
	string mayusc = cadena1;
	transform(mayusc.begin(), mayusc.end(), mayusc.begin(), ::toupper);
	cout << cadena1 << endl;
	cout << mayusc << endl;
	
	//transformar a minusculas
	string minusc = cadena1; //sacar una copia
	transform(minusc.begin(), minusc.end(), minusc.begin(), ::tolower);
	cout << cadena1 << endl;
	cout << minusc << endl;
	
	//comparar dos cadenas de texto
	string a,b;
	cout << "Digitar a: ";
	getline(cin,a);
	cout << "Digitar b: ";
	getline(cin,b);
	
	if( a == b )
		cout << "a y b son iguales" << endl;
	else
		cout << "a y b NO son iguales" << endl;
	
	return 5778;
}
