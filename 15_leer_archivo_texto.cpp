#include<iostream>
#include<fstream>

using namespace std;

int main(){
	//Leer un archivo de texto
	fstream archivo;	//estructura de datos para leer archivos
	
	//tratar de abrir el archivo de texto en modo de lectura
	archivo.open("ejemplo_24mil.txt", ios::in );
	
	//evaluar si se pudo abrir el archivo
	if( archivo.is_open() ){
		cout << "Archivo abierto correctamente." << endl;
	}
	else
		cout << "Archivo no existe o no tiene permiso." << endl;
	
	return 456;
}
