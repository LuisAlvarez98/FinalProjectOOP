/*
	by: Luis Felipe Alvarez Sanchez A01194173
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Fecha.h"
#include "Reserva.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include <fstream>
using namespace std;
//Vars
Material * materiales[20];
Reserva * reservaciones[50];
ifstream ifArchivoMateriales;

int materialesSize;

void loadMateriales() {
	int id, duracion, numPaginas;
	string titulo, os, autor;
	char tipo;
	
	ifArchivoMateriales.open("materiales.txt");
	while (ifArchivoMateriales >> id >> titulo >> tipo) {
		switch (tipo) {
			case 'L':
				ifArchivoMateriales >> numPaginas >> autor;
				materiales[materialesSize] = new Libro(id, titulo, numPaginas, autor);
				break;
			case 'D':
				ifArchivoMateriales >> duracion;
				materiales[materialesSize] = new Disco(id, titulo, duracion);
				break;
			case 'S':
				ifArchivoMateriales >> os;
				materiales[materialesSize] = new Software(id, titulo, os);
				break;
		}
		materialesSize++;
	}
	ifArchivoMateriales.close();
}
void app() {
	bool flag = true;
	while (flag) {
		int opcion;
		cout << "1.Consulta lista de materiales" << "\n";
		cout << "2.Consulta lista de reservaciones" << "\n";
		cout << "3.Consulta lista de reservaciones de un material dado" << "\n";
		cout << "4.Consulta lista de reservaciones de una fecha dada" << "\n";
		cout << "5.Hacer una reservacion" << "\n";
		cout << "6.Terminar" << "\n";
		cin >> opcion;
		switch (opcion) {
		case 1:
			int i;
			for (i = 0; i < materialesSize; i++) {
				materiales[i]->muestraDatos();
				cout << "\n";
			}
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

	loadMateriales();
	app();

    return 0;
}

