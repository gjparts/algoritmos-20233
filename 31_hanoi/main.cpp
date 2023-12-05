#include<iostream>
#include "nodo.h"
#include "pila.h"
using namespace std;

//prototipos de funcion
void dibujarDisco(string valor); //dibuja un disco en base al valor enviado
void dibujarTorre(Pila *torre); //dibuja una torre con sus discos
void dibujarJuego(Pila *torre1, Pila *torre2, Pila *torre3); //dibuja las tres torres

/* ayuda a memoria:
el juego va a lucir asi:
Torre 1
   |   
   |   
   |   
   |   
   
Torre 2
   *   
  ***
 *****
*******

Torre 3
   |   
   |   
   |   
   |   

Digite torre origen (1-3) o -1 para salir: 2
Digite torre destino (1-3) o -1 para salir: 1

*/
int main(){
	//crear las torres
	Pila *torre1 = new Pila();
	Pila *torre2 = new Pila();
	Pila *torre3 = new Pila();
	
	//poner todos los discos en la torre2
	torre2->push("4");
	torre2->push("3");
	torre2->push("2");
	torre2->push("1");
	
	//torre2->imprimir();
	//dibujarDisco("1");
	//dibujarDisco("3");
	//dibujarTorre(torre2);
	
	//declarar las variables para manejar torre origen, destino, opcion digitada
	int origen = 0, destino = 0, opcion = 0;
	
	while( opcion >= 0 ){
		system("cls");
		dibujarJuego(torre1, torre2, torre3);
		//capturar la torre de origen
		cout << "Digite torre origen (1-3) o -1 para salir: ";
		cin >> opcion;
		if( opcion < 0 ) continue;	//numero negativo, vuelve a iterar el while
		origen = opcion;	//numero positivo, se pasa a la torre de origen
		
		//capturar la torre de destino
		cout << "Digite torre destino (1-3) o -1 para salir: ";
		cin >> opcion;
		if( opcion < 0 ) continue;	//numero negativo, vuelve a iterar el while
		destino = opcion;	//numero positivo, se pasa a la torre de destino
		
		//solo si las torres son correctas movemos los discos, de lo contrario
		//mostrar mensaje que alguna de las torres no es valida
		if( origen >= 1 && origen <= 3 && destino >= 1 && destino <= 3 ){
			//en base al entero de origen sera la Pila de
			//origen desde donde sacar el disco
			Pila *pilaOrigen, *pilaDestino;
			if( origen == 1 ) pilaOrigen = torre1;
			if( origen == 2 ) pilaOrigen = torre2;
			if( origen == 3 ) pilaOrigen = torre3;
			//en base al entero de destino sera la Pila de
			//destino hacia donde va el disco
			if( destino == 1 ) pilaDestino = torre1;
			if( destino == 2 ) pilaDestino = torre2;
			if( destino == 3 ) pilaDestino = torre3;
			
			//obtener los discos que estan en el tope de las torres origen y destino
			Nodo *discoOrigen, *discoDestino;
			discoOrigen = pilaOrigen->peek();
			discoDestino = pilaDestino->peek();
			
			int valorDiscoOrigen, valorDiscoDestino;
			//el disco de origen existe
			if( discoOrigen != NULL )
				valorDiscoOrigen = stoi(discoOrigen->valor);
			else
				valorDiscoOrigen = 0;	//disco de origen no existe, su valor es cero.
			
			//el disco de destino existe
			if( discoDestino != NULL )
				valorDiscoDestino = stoi(discoDestino->valor);
			else
				valorDiscoDestino = 999;	//disco de destino no existe, su valor es 999.
											//para que se pueda apilar otro disco en torre vacia
			
			/*cout << "valor disco Origen: " << valorDiscoOrigen << endl;
			cout << "valor disco Destino: " << valorDiscoDestino << endl;
			system("pause");*/
			
			//No se permitira mover un disco grande sobre un disco pequeño
			if( valorDiscoOrigen >= valorDiscoDestino || discoOrigen == NULL ){
				cout << "Accion no permitida" << endl;
				system("pause");
			}
			else{
				//mover el disco origen hacia la torre destino
				pilaDestino->push( pilaOrigen->pop()->valor );
			}
			
			//evaluar el gane
			//si la torre1 o la torre3 alguna de ellas tiene longitud 4 entonces se ha ganado
			if( torre1->getLongitud() == 4 || torre3->getLongitud() == 4 ){
				cout << "Felicidades, has ganado; pero no es el fin aun vienen mas retos." << endl;
				break;	//terminar con el while principal
			}
		}
		else{
			cout << "Algunas de las torres no es correcta." << endl;
			system("pause");
		}
	}
	
	
	
	return 456;
}

//implementacion de funciones
//dibuja un disco en base al valor enviado
void dibujarDisco(string valor){
	if( valor == "4" ) cout << "*******" << endl;
	if( valor == "3" ) cout << " ***** " << endl;
	if( valor == "2" ) cout << "  ***  " << endl;
	if( valor == "1" ) cout << "   *   " << endl;
}

//dibuja una torre con sus discos
void dibujarTorre(Pila *torre){
	//primero dibujar los postes vacios de la torre
	for( int i = 1; i <= 4-torre->getLongitud(); i++ )
		cout << "   |   " << endl;
	
	//segundo dibujar los discos de la torre (recorrer la pila desde su tope)
	Nodo *tmp = torre->peek();
	while( tmp != NULL )
	{
		dibujarDisco(tmp->valor);
		tmp= tmp->siguiente;
	}
	//tercero: dibujar el suelo de la torre
	cout << "///////" << endl;
}

//dibuja las tres torres
void dibujarJuego(Pila *torre1, Pila *torre2, Pila *torre3){
	cout << "Torre 1" << endl;
	dibujarTorre(torre1);
	cout << endl;
	
	cout << "Torre 2" << endl;
	dibujarTorre(torre2);
	cout << endl;
	
	cout << "Torre 3" << endl;
	dibujarTorre(torre3);
	cout << endl;
}














