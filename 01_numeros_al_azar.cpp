#include<iostream>
#include<time.h>
using namespace std;

int main(){
	//generar un numero al azar
	int numero;
	//generar un set de numeros aleatorios en base
	//a la fecha/hora de la computadora en milisegundos
	srand( time(NULL) );
	
	//obtener un numero al azar entre 8 y 97
	numero = rand()%(97-8+1)+8;
	
	cout << numero << endl;
	
	//generemos 20 numeros al azar entre 8 y 97
	for(int i = 1; i <= 20; i++){
		numero = rand()%(97-8+1)+8;
		cout << numero << endl;
	}
	
	return 876;
}
