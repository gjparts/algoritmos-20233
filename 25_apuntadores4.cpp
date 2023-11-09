#include<iostream>
#include<algorithm>
using namespace std;

//prototipo de funcion
void mayusculas(string *str);
void cambiarEspacios(string *str);

int main(){
	/*apuntadores cuando se usa objetos o estructuras de datos.
	a) al declarar la funcion se usa el signo de apuntador * para el objeto/estructura.
	b) al usar la variable en el ambito externo se usa el simbolo del apuntador
	   para el objeto/estructura.
	c) en el ambito externo no se tiene acceso a los atributos y metodos del objeto/estructura
	   para solucionarle se recomienda sacar una copia del objeto/estructura en el
	   ambito externo, trabajar sobre la copia y por ultimo sobreescribir al apuntador
	   con la copia.
	d) al usar la funcion enviar el objeto/estructura con el & */
	   
	string str1 = "Gerardo Portillo";
	cout << "str1: " << str1 << endl;
	cout << "direccion de memoria de str1: " << &str1 << endl;
	mayusculas(&str1);
	cout << "str1 luego de mayusculas: " << str1 << endl;
	string str2 = "Ingenieria en Sistemas UNAH-VS";
	cout << "str2 antes de reemplazar espacios: " << str2 << endl;
	cambiarEspacios(&str2);
	cout << "str2 despues de reemplazar espacios: " << str2 << endl;
	
	return 123;
}

/*hacer una funcion void que reciba un string apuntado
y que le reemplace sus espacios en blanco por guiones bajos.*/
void cambiarEspacios(string *str){
	//sacar una copia local del valor del apuntador
	string copia = *str;
	
	for( int i = 0; i < copia.length(); i++ ){
		if( copia[i] == ' ' )
			copia[i] = '_';
	}
	//una vez alterada la copia, sobreescribir el valor de la variable apuntada
	//por el valor de la copia.
	*str = copia;
}

/*hacer una funcion void que reciba un string apuntado y lo cambie a mayusculas*/
void mayusculas(string *str){
	//sacar una copia local del valor del apuntador
	string copia = *str;
	//pasar la copia local a mayusculas
	transform(copia.begin(), copia.end(), copia.begin(), ::toupper);
	//una vez alterada la copia, sobreescribir el valor de la variable apuntada
	//por el valor de la copia.
	*str = copia;
}





