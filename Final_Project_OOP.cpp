/*
	by: Luis Felipe Alvarez Sanchez A01194173
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void app() {
	bool flag = true;
	while (flag) {
		int opcion;
		cin >> opcion;
		cout << "1.Consulta lista de materiales" << "\n";
		cout << "2.Consulta lista de reservaciones" << "\n";
		cout << "3.Consulta lista de reservaciones de un material dado" << "\n";
		cout << "4.Consulta lista de reservaciones de una fecha dada" << "\n";
		cout << "5.Hacer una reservacion" << "\n";
		cout << "6.Terminar" << "\n";
		switch (opcion) {
		case 1:
			cout << "1";
			break;
		case 2:
			cout << "2";
			break;
		case 3:
			cout << "3";
			break;
		case 4:
			cout << "4";
			break;
		case 5:
			cout << "5";
			break;
		case 6:
			cout << "Bye bye";
			flag = false;
			break;
		default:
			cout << "Invalid value" << "\n";
			break;
		}
	}
	
}

int main()
{
	app();
    return 0;
}

