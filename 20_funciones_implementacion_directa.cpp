#include<iostream>
using namespace std;

/*FUNCIONES EN C++
Modelo basado en implementacion directa: antes del main se implementan
las funciones.*/
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

