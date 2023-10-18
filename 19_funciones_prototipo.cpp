#include<iostream>
using namespace std;

/*FUNCIONES EN C++
Modelo basado en prototipos: antes del main se declaran las
firmas de las funciones y despues del main se implementan.*/

//prototipos de funcion
int sumar(int a, int b);	//funcion que devuelve la suma de dos enteros
int sumar(int a, int b, int c); //funcion que devuelve la suma de tres enteros
double sumar(double a, double b); //funcion que devuelve la suma de dos doubles
string grupoEdad(int edad);	//determina si la edad es para mayor o menor de edad
bool numeroPar(int n);	//retorna true si un entero es par
void saludar(string nombre, bool saludarEnIngles);  //imprime un saludo

int main(){
	cout << sumar(2,3) << endl;
	cout << sumar(2,3,5) << endl;
	cout << sumar(2.5, 6.3) << endl;
	cout << grupoEdad(19) << endl;
	cout << grupoEdad(15) << endl;
	cout << numeroPar(4) << endl;
	cout << numeroPar(7) << endl;
	
	if( numeroPar(8) == true )
		cout << "8 es Par" << endl;
	else
		cout << "8 es Impar" << endl;
		
	saludar("Gerardo", true);
	return 567;
}

//implementacion de funciones
void saludar(string nombre, bool saludarEnIngles){
	if( saludarEnIngles == true ) cout << "Hello "; else cout << "Hola ";
	cout << nombre << endl;
}
int sumar(int a, int b){
	return a+b;
}
int sumar(int a, int b, int c){
	return a+b+c;
}
double sumar(double a, double b){
	return a+b;
}
string grupoEdad(int edad){
	if( edad < 18 )
		return "Menor de edad";
	else
		return "Mayor de edad";
}
bool numeroPar(int n){
	if( n%2 == 0 )
		return true;
	else
		return false;
}
