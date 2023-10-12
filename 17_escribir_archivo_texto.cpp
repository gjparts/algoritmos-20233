#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream archivo;
	
	/*Escribir en un archivo de texto
	la funcion open tiene tambien modificadores para escribir
	estos son:
	ios::app	APPEND	inserta una nueva linea al final del archivo sin perder
						lo que ya estaba
	ios::out	OUTPUT	sobreescribe el archivo perdiendo lo que ya estaba (overwrite)
	-> IMPORTANTE: si el archivo no existe entonces es creado.
	*/
	archivo.open("salida.txt",ios::app);
	
	if( archivo.is_open() ){
		//escribir en el archivo
		archivo << "Hola UNAH" << endl;
		archivo << 2+2 << endl;
		archivo << "\tHola" << "\nAdios" << endl;
		archivo.close(); //cerrar el archivo
	}
	else
		cout << "Archivo no puede ser escrito" << endl;
	
	return 765;
}
