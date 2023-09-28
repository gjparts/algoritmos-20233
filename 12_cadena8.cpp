#include<iostream>
using namespace std;

int main(){
	//conversiones
	//de numero a string
	float num = 500;
	string str1 = to_string(num);
	cout << str1 << endl;	
	
	//de entero a string
	string str2 = "14.9";
	int entero1 = stoi(str2);
	cout << entero1 << endl;	
	
	//de float a string
	string str3 = "3.1416";
	float flotante1 = stof(str3);
	cout << flotante1 << endl;
	
	//de double a string
	string str4 = "20.245998";
	double doble1 = stod(str4);
	cout << doble1 << endl;
	
	return 777;
}









