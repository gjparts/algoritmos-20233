#include<iostream>
using namespace std;

int main(){
	//Caza de errores
	//hacer un programa que pregunte un numero, lo guarde en un string
	//y nosotros lo mostremos convertido a int
	//en caso de ocurrir un error de conversion mostrar un mensaje indicando
	//que lo digitado no es permitido.
	
	string valor;
	cout << "Digitar un numero: ";
	getline(cin,valor);
	
	try{
		//codigo propenso a fallar
		int numero = stoi(valor);
		cout << "El numero convertido a entero es: " << numero << endl;
	}catch(exception ex){
		//aqui va el codigo a ejecutar en caso de falla
		cout << "El numero digitado no es permitido." << endl;
	}
	
	
	
	return 145;
}
