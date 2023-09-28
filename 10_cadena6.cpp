#include<iostream>
using namespace std;

int main(){
	//buscar una cadena de texto dentro de otra
	string str = "El tiempo transcurre inexorable ante atardeceres ";
	str += "que no nos es menester observar.";
	
	string buscar;
	cout << "Digitar el texto a buscar: ";
	getline(cin,buscar);
	
	//para buscar dentro de una cadena usamos find
	//find devuelve -1 si no encontró nada, de lo contrario
	//devuelve la posicion a partir de donde encontró el texto buscado.
	int posicion;
	posicion = str.find(buscar,0);
	//0 significar a partir de que posicion vamos a comenzar a buscar
	//en este caso CERO significa desde el primer caracter.
	
	if(posicion == -1)
		cout << "No se encontro";
	else
		cout << "Encontrado en la posicion " << posicion;
	
	cout << endl;
	
	return 6543;
}
