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
ifstream ifArchivoReserva;

int materialesSize, reservacionSize;
void loadReservaciones() {
	int dd, mm, aa, idMaterial, idCliente;
	ifArchivoReserva.open("reserva.txt");
	while (ifArchivoReserva >> dd >> mm >> aa >> idMaterial >> idCliente) {
		reservaciones[reservacionSize] = new Reserva(idMaterial, idCliente, dd, mm , aa);
		reservacionSize++;
	}
}
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
				materiales[materialesSize]->setTipo(tipo);
				break;
			case 'D':
				ifArchivoMateriales >> duracion;
				materiales[materialesSize] = new Disco(id, titulo, duracion);
				materiales[materialesSize]->setTipo(tipo);
				break;
			case 'S':
				ifArchivoMateriales >> os;
				materiales[materialesSize] = new Software(id, titulo, os);
				materiales[materialesSize]->setTipo(tipo);
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
		//Done :)
		case 1:
			for (int i = 0; i < materialesSize; i++) {
				materiales[i]->muestraDatos();
				cout << "\n";
			}
			break;
		//Done  needs validation
		case 2:
			for (int i = 0; i < reservacionSize; i++) {
				cout << "Fecha inicio: " << reservaciones[i]->getFecha().getDia() << " " <<  reservaciones[i]->getFecha().nombreMes(reservaciones[i]->getFecha().getMes()) << " " << reservaciones[i]->getFecha().getYear() <<  "\n";
				for (int j = 0; j < materialesSize; j++) {
					if (materiales[j]->getIdMaterial() == reservaciones[i]->getidMaterial()) {
						cout << "Fecha final: " << reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getDia() << " ";
						cout << reservaciones[i]->getFecha().nombreMes(reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getMes()) << " ";
						cout << reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getYear() << "\n";
						cout << "Nombre: " << materiales[j]->getTitulo()<< "\n";
					}
				}
				cout << "Id Cliente: " << reservaciones[i]->getIdCliente()<< "\n";
				cout << "\n";
			}
			break;
		//Done  needs validation
		case 3:
			char material;
			cout << "Ingresa que tipo de material quieres ver en la lista de reservaciones: [L- Libro, D- Disco, S- Software " << "\n";
			cin >> material;
			for (int i = 0; i < reservacionSize; i++) {
				for (int j = 0; j < materialesSize; j++) {
					if (reservaciones[i]->getidMaterial() == materiales[j]->getIdMaterial()) {
						if (materiales[j]->getTipo() == material) {
							cout << "Nombre: " << materiales[j]->getTitulo() << "\n";
							cout << "Fecha inicio: " << reservaciones[i]->getFecha().getDia() << " " << reservaciones[i]->getFecha().nombreMes(reservaciones[i]->getFecha().getMes()) << " " << reservaciones[i]->getFecha().getYear() << "\n";
							cout << "Fecha final: " << reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getDia() << " ";
							cout << reservaciones[i]->getFecha().nombreMes(reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getMes()) << " ";
							cout << reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getYear() << "\n";
							cout << "\n";
						}
					}
				}
			}
			break;
		case 4:
			int dd, mm, aa;
			cout << "Ingresa el dd, mm y aa" << "\n";
			cin >> dd;
			cin >> mm;
			cin >> aa;
			for (int i = 0; i < reservacionSize; i++) {
				if (dd == reservaciones[i]->getFecha().getDia() && mm == reservaciones[i]->getFecha().getMes()
					 && aa == reservaciones[i]->getFecha().getYear()) {
					//reservaciones[i]->muestra();
					cout << "\n";
				}
			}
			break;
		case 5:
			int d, m, a, idMaterial, idCliente;
			cout << "Ingresa el dd, mm y aa " << "\n";
			cin >> d;
			cin >> m;
			cin >> a;
			cout << "Ingresa el id del material:" << "\n";
			cin >> idMaterial;
			cout << "Ingresa id del cliente : " << "\n";
			cin >> idCliente;
			reservaciones[reservacionSize] = new Reserva(idMaterial, idCliente, d, m, a);
			reservacionSize++;
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
	loadReservaciones();
	app();
	
    return 0;
}

