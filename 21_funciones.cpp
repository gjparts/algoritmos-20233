#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include<iomanip> //para poder usar setprecision
#include<time.h>
#include<algorithm>
using namespace std;

//prototipos de funcion
int elevar(int base, int exponente);
double hipotenusa(double cateto1, double cateto2);
bool multiplo( int dividendo, int divisor );
void imprimirRectangulo(int largo, int ancho, char caracter);
double areaCirculo(double radio);
float  areaCirculo(float radio);
double 	minimo(double a, double b, double c);
float 	minimo(float a, float b, float c);
int 	minimo(int a, int b, int c);
int azar(int minimo, int maximo);
bool estaEnMayusculas(string cadena);
int buscarChar(char buscado, string donde);

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
	double a = 2.45;
	float b = 3.5;
	cout << setprecision(32) << areaCirculo(a) << endl;
	cout << setprecision(8) << areaCirculo(b) << endl;
	int xe1 = 8, xe2 = 10, xe3 = 5;
	cout << minimo(xe1,xe2,xe3) << endl;
	float xf1 = 89.4, xf2 = 20.1, xf3 = 15.45;
	cout << minimo(xf1,xf2,xf3) << endl;
	double xd1 = 89.4, xd2 = 20.1, xd3 = 15.45;
	cout << minimo(xd1,xd2,xd3) << endl;
	cout << azar(1,6) << endl;
	cout << azar(14,20) << endl;
	cout << azar(-7,-1) << endl;
	cout << estaEnMayusculas("NARANJA") << endl;
	cout << estaEnMayusculas("NARaNJA") << endl;
	cout << buscarChar('L',"muercielago") << endl;
	cout << buscarChar('a',"muercielago") << endl;
	cout << buscarChar('x',"muercielago") << endl;
	
	//cout << "4 es multiplo de 2? " << ( multiplo(4,2) == true ? "Si" : "No" );
	return 678;
}

//implementacion
/*10. Escriba una funcion que reciba como parametros un string y un
arreglo de string, dicha funcion debera buscar el string proporcionado
dentro arreglo, si la cadena es encontrada entonces la funcion
retornara un numero entero con la posicion de la primer
coincidencia en la que se encontró, si no se encuentra
nada entonces retornar -1.*/

/*9. Escriba una funcion a la cual se le proporcione como
parametros un caracter y una cadena de texto, dicha funcion
debera devolver un entero con la posicion de la primer coincidencia
en la que fue encontrado el caracter proporcionado dentro de
la cadena de texto proporcionada, si el caracter no es
encontrado entonces devolver -1.
No tiene permitido utilizar la funcion find del string.*/
int buscarChar(char buscado, string donde){
	for( int i = 0; i < donde.length(); i++ ){
		//cout << donde[i] << endl;
		if( donde[i] == buscado )
			return i; //retornar la posicion del char encontrado
	}
	//si llego hasta aqui es porque termino de recorrer
	//la cadena y no hallo nada.
	return -1;
}

/*8. Escriba una funcion que devuelva true si una cadena
de texto esta escrita toda en mayusculas y false si no es así.*/
bool estaEnMayusculas(string cadena){
	string mayusculas = cadena;
	transform(mayusculas.begin(),mayusculas.end(), mayusculas.begin(),::toupper);
	if( cadena == mayusculas )
		return true;
	else
		return false;
}

/*7. Escriba una funcion que reciba dos numeros enteros
como parametros, uno sera el minimo y el otro el maximo,
la funcion debera retornar un numero aleatorio entero que
se encuentre entre dichos numeros.*/
int azar(int minimo, int maximo){
	srand(time(NULL));
	return rand()%(maximo-minimo+1)+minimo;
}
/*6. Escriba una función llamada minimo que retorne
el menor de tres números, dicha funcion debera poder
funcionar con tres numeros enteros,
tres numeros double o tres numeros float.*/
double 	minimo(double a, double b, double c){
	if( a <= b && a <= c ) return a;
	if( b <= a && b <= c ) return b;
	if( c <= a && c <= b ) return c;
}
float 	minimo(float a, float b, float c){
	double x = a, y = b, z = c;
	return minimo(x,y,z);
}
int 	minimo(int a, int b, int c){
	double x = a, y = b, z = c;
	return minimo(x,y,z);
}

/*5. Hacer un funcion que retorne el area de un circulo,
dicha funcion debera recibir el radio como parametro.
Usando sobrecarga de funciones haga que la funcion pueda
trabajar con numeros double y con numeros float.*/
double areaCirculo(double radio){
	return M_PI*pow(radio,2);
}
float  areaCirculo(float radio){
	return M_PI*pow(radio,2);
}

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
