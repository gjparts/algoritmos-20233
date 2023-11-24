#include<iostream>
#include<stdexcept>
#include "Empleado.h"
#include "CuentaAhorro.h"
using namespace std;

int main(){
	Empleado *p1 = new Empleado("Gerardo",41,1000);
	cout << p1->nombre << endl;
	//cout << p1->edad << endl;
	/*try{
		p1->setEdad(-12);
	}catch(exception ex){
		cout << "error en la edad" <<endl;
	}*/
	//p1->setEdad(-12);
	cout << p1->getEdad() << endl;
	p1->setEdad(45);
	cout << p1->getEdad() << endl;
	
	p1->setGenero('M');
	cout << p1->getGenero() << endl;
	
	cout << p1->getSalario() << endl;
	p1->setSalario(15000);
	cout << p1->getSalario() << endl;
	
	cout << p1->getContrato() << endl;
	p1->setContrato('P');
	cout << p1->getContrato() << endl;
	
	Empleado *p2 = new Empleado("Filomeno Colinas",78,'M',9000,'P');
	p2->imprimir();
	
	cout << "*****************************" << endl;
	CuentaAhorro *c1 = new CuentaAhorro("Gerardo",41);
	cout << c1->getSaldo() << endl;
	c1->depositar(5000);
	cout << c1->getSaldo() << endl;
	c1->depositar(100);
	c1->depositar(3000);
	//c1->depositar(-15);
	cout << c1->getSaldo() << endl;
	c1->retirar(500);
	cout << c1->getSaldo() << endl;
	
	system("pause");
	
	CuentaAhorro *c2 = new CuentaAhorro("Josue Portillo",41);
	
	int opcion;
	do{
		system("cls");
		cout << "1) Depositar" << endl;
		cout << "2) Retirar" << endl;
		cout << "3) Consultar saldo" << endl;
		cout << "4) Salir" << endl;
		cout << "Digitar opcion: ";
		cin >> opcion;
		
		float monto;
		switch(opcion){
			case 1:
				cout << "Digite monto a DEPOSITAR: ";
				cin >> monto;
				try{
					c2->depositar(monto);
				}catch(invalid_argument &ex){
					cout << "no se pudo depositar" << endl;
					cout << ex.what() << endl;
				}
			break;
			case 2:
				cout << "Digite monto a RETIRAR: ";
				cin >> monto;
				try{
					c2->retirar(monto);
				}catch(invalid_argument &ex){
					cout << "no se pudo hacer el retiro" << endl;
					cout << ex.what() << endl;
				}
			break;
			case 3:
				cout << "El saldo de su cuenta es: " << c2->getSaldo() << endl;
			break;
			case 4:
				cout << "Adios" << endl;
			break;
			default:
				cout << "opcion no valida" << endl;	
		};
		system("pause");
	}while( opcion != 4 );
	
	return 345;
}










