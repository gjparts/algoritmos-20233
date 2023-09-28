#include<iostream>
using namespace std;

int main(){
	//BUG que ocurre cuando venimos de leer
	//un int y vamos a leer un string
	int x;
	string str;
	
	cout << "Digitar un numero entero para x: ";
	cin >> x;
	
	cout << "Digitar una cadena para str: ";
	cin.ignore();	//vaciar el buffer de entrada
					//cuando se viene de leer numero y se quiere leer string
					//debe hacer esto.
	getline(cin,str);
	
	cout << "Gracias, el programa ha terminado." << endl;
		
	return 567;
}
