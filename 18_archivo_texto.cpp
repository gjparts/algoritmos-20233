#include<iostream>
#include<fstream>

using namespace std;

int main(){
	/*Hacer un programa que muestre un menu:
	DIARIO
	1) Agregar entrada al diario
	2) Mostrar todo el diario
	3) Salir
	Digitar la opcion deseada: 
	
	* el menu se volverá a mostrar hasta que el usuario
	  seleccione la opcion de salir
	* en la opcion 1:	  la entrada se escribirá al final del diario
	* en la opcion 2 al imprimir el diario hacer una pausa cada 10 lineas*/
	string str;
	int opcion;
	
	do{
		system("cls"); //limpiar la pantalla
		cout << "****** DIARIO ******" << endl;
		cout << "1) Agregar entrada al diario" << endl;
		cout << "2) Mostrar todo el diario" << endl;
		cout << "3) Salir" << endl;
		cout << "Digitar la opcion deseada: ";
		getline(cin,str);
		
		//convertir la cadena leida en numero y ponerlo como opcion
		try{
			opcion = stoi(str);
		}catch(exception ex){
			cout << "Debe ser numero entero" << endl;
			system("pause");
		}
		
		//variables de trabajo
		fstream archivo;
		string linea;
		
		//decidimos de hacer
		switch(opcion){
			case 1:
				cout << "Digite la nueva entrada de diario: ";
				getline(cin,linea);
				//abrir el archivo en modo append
				archivo.open("diario.txt",ios::app);
				if( archivo.is_open() ){
					archivo << linea << endl;
					archivo.close(); //cerrar el archivo
				}
				else
					cout << "Archivo no se puede escribir." << endl;
			break;
			case 2:
				cout << "Leer diario *************" << endl;
				//abrir archivo en modo lectura
				archivo.open("diario.txt",ios::in);
				if( archivo.is_open() ){
					int n = 0; //contador de lineas para saber cuando hemos leido 10 lineas
					while( !archivo.eof() ){
						getline(archivo,linea);
						n++;
						
						cout << n << "\t" << linea << endl;
						
						if( n%10 == 0 )	//pausa cada diez lineas
							system("pause");
					}
					archivo.close(); //cerrar el archivo
				}
				else
					cout << "Archivo no se puede escribir." << endl;
			break;
			case 3:
				cout << "Adios" << endl;
			break;
			default:
				cout << "Opcion no valida" << endl;
		}
		system("pause");
	}while(opcion != 3);
	
	
	return 678;
}
