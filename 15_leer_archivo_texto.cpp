#include<iostream>
#include<fstream>

using namespace std;

int main(){
	//Leer un archivo de texto
	fstream archivo;	//estructura de datos para leer archivos
	string linea;	//variable para ir leyendo renglones en el archivo
	
	//tratar de abrir el archivo de texto en modo de lectura
	//archivo.open("G:\\Temp\\35M.txt", ios::in );
	archivo.open("ejemplo_24mil.txt", ios::in );
	
	//evaluar si se pudo abrir el archivo
	if( archivo.is_open() ){
		cout << "Archivo abierto correctamente." << endl;
		int n = 0; //contador de lineas
		//recorrer el archivo linea por linea e imprimir cada una
		while( !archivo.eof() ){
			//eof = end of file
			//leer linea y depositarla en una variable
			getline(archivo,linea);
			//imprimir la linea recien leida: (opcional)
			//cout << linea << endl;
			n++; //sumar 1 al contador de lineas
		}
		cout << "El archivo tiene " << n << " lineas." << endl;
	}
	else
		cout << "Archivo no existe o no tiene permiso." << endl;
	
	return 456;
}
