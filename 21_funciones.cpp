#include<iostream>
#include<cmath>
using namespace std;

//prototipos de funcion
int elevar(int base, int exponente);
double hipotenusa(double cateto1, double cateto2);
bool multiplo( int dividendo, int divisor );
void imprimirRectangulo(int largo, int ancho, char caracter);

int main(){
	cout << elevar(2,0) << endl;
	cout << elevar(3,3) << endl;
	cout << elevar(20,1) << endl;
	cout << elevar(5,4) << endl;
	cout << hipotenusa(4,3) << endl;
	cout << hipotenusa(6,8) << endl;
	cout << multiplo(4,3) << endl;
	cout << multiplo(10,2) << endl;
	imprimirRectangulo(5,4,'\\');
	imprimirRectangulo(15,40,'$');
	
	//cout << "4 es multiplo de 2? " << ( multiplo(4,2) == true ? "Si" : "No" );
		
	return 678;
}

//implementacion
/*4. Escriba una funcion que imprima un rectagulo de caracteres,
dicha funcion recibira como parametros el ancho y largo del mismo
asi como otro parametro con el caracter a usar para dibujar
dicho rectangulo.*/
void imprimirRectangulo(int largo, int ancho, char caracter){
	for( int i = 1; i <= largo; i++ ){
		for( int j = 1; j <= ancho; j++ ){
			cout << caracter;
		}
		cout << endl;
	}
}
/*3. Escriba una funcion que reciba dos numeros enteros y retorne true
si el primer numero es multiplo del segundo o false en caso contrario.*/
bool multiplo( int dividendo, int divisor ){
	//return dividendo%divisor == 0 ? true : false;
	if( dividendo%divisor == 0 )
		return true;
	else
		return false;
}


/*2. Defina una funcion llamada hipotenusa que retorne
la longitud de la hipotenusa de un triángulo rectángulo,
la funcion recibira los lados de dicho trinagulo.
La funcion debera funcionar con numeros double.*/
double hipotenusa(double cateto1, double cateto2){
	return sqrt( pow(cateto1,2)+pow(cateto2,2) );
}

/*1. Escriba una funcion llamada elevar que reciba
	dos numeros enteros, uno para la base y otro para la
	potencia, la funcion debe retornar un entero
	resultado de elevar el numero base a la potencia
	sin utilizar la funcion pow.*/
int elevar(int base, int exponente){
	int r = 1;
	
	for( int i = 1; i <= exponente; i++ ){
		r = r*base;
	}
	
	return r;
}
