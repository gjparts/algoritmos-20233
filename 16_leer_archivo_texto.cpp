#include<iostream>
#include<fstream>

using namespace std;

int main(){
	/*hacer un programa que abra el archivo ejemplo_24mil.txt, lo recorra
	y muestre cuantas lineas tiene, cual es la suma de todos sus numeros,
	cuantos numeros son pares, cuantos numeros son impares, y
	el promedio de todos sus numeros.
	Importante: No imprimir cada linea.*/
	fstream archivo;
	string linea;
	
	archivo.open("ejemplo_24mil.txt", ios::in );
	
	if( archivo.is_open() ){
		//variables
		int n = 0;	//contador de lineas
		int suma = 0; //acumulador para sumar los numeros encontrados
		int pares = 0; //contador de numeros pares
		int impares = 0; //contador de numeros impares
		
		while( !archivo.eof() ){
			getline(archivo, linea);
			n++;	//sumar 1 al contador de lineas
			
			//sumar el valor leido (en caso de ser numero)
			try{
				suma += stoi(linea);
				if( stoi(linea)%2 == 0 )
					pares++;
				else
					impares++;
			}catch(exception ex){
				
			}
		}
		//imprimir resultados
		cout << "Lineas en el archivo: " << n << endl;
		cout << "Suma de los numeros: " << suma << endl;
		cout << "Cantidad de numeros pares: " << pares << endl;
		cout << "Cantidad de numeros impares: " << impares << endl;
		cout << "Promedio de los numeros: " << suma/(pares+impares) << endl;
	}
	else
		cout << "No fue posible abrir el archivo, no existe o no tiene permiso." << endl;
	
	return 432;
}
