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
ofstream ofArchivoReserva;

int materialesSize, reservacionSize;
//done
void loadReservaciones() {
	int dd, mm, aa, idMaterial, idCliente;
	ifArchivoReserva.open("reserva.txt");
	while (ifArchivoReserva >> dd >> mm >> aa >> idMaterial >> idCliente) {
		reservaciones[reservacionSize] = new Reserva(idMaterial, idCliente, dd, mm , aa);
		reservacionSize++;
	}
}
//done
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
//done
void one() {
	for (int i = 0; i < materialesSize; i++) {
		materiales[i]->muestraDatos();
		cout << "\n";
	}
}
//done
void two() {
	for (int i = 0; i < reservacionSize; i++) {
		cout << "Fecha inicio: " << reservaciones[i]->getFecha().getDia() << " " << reservaciones[i]->getFecha().nombreMes(reservaciones[i]->getFecha().getMes()) << " " << reservaciones[i]->getFecha().getYear() << "\n";
		for (int j = 0; j < materialesSize; j++) {
			if (materiales[j]->getIdMaterial() == reservaciones[i]->getidMaterial()) {
				cout << "Fecha final: " << reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getDia() << " ";
				cout << reservaciones[i]->getFecha().nombreMes(reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getMes()) << " ";
				cout << reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo()).getYear() << "\n";
				cout << "Nombre: " << materiales[j]->getTitulo() << "\n";
			}
		}
		cout << "Id Cliente: " << reservaciones[i]->getIdCliente() << "\n";
		cout << "\n";
	}
}
//done
void three() {
	int idMaterial;
	bool idNoExiste = true;
	int counter = 0;
	while (idNoExiste) {
		cout << "Ingresa el id de material para ver las reservaciones" << "\n";
		cin >> idMaterial;
		for (int i = 0; i < reservacionSize; i++) {
			if (reservaciones[i]->getidMaterial() == idMaterial) {
				counter++;
			}
		}
		if (counter > 0) {
			for (int i = 0; i < reservacionSize; i++) {
				for (int j = 0; j < materialesSize; j++) {
					if (reservaciones[i]->getidMaterial() == materiales[j]->getIdMaterial()) {
						if (materiales[j]->getIdMaterial() == idMaterial) {
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
			idNoExiste = false;
		}
		else if (counter == 0) {
			cout << "Id de material invalido" << "\n";
			idNoExiste = true;
		}
	}
}
//done
void four() {
	Fecha f2;
	int dd, mm, aa, counter = 0;
	cout << "Ingresa el dd, mm y aa" << "\n";
	cin >> dd;
	cin >> mm;
	cin >> aa;
	f2.setFecha(dd, mm, aa);
	for (int i = 0; i < reservacionSize; i++) {
		for (int j = 0; j < materialesSize; j++) {
			if (f2 >= reservaciones[i]->getFecha() && f2 <= reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo())) {
				if (reservaciones[i]->getidMaterial() == materiales[j]->getIdMaterial()) {
					cout << "Titulo: " << materiales[j]->getTitulo() << "\n";
					cout << "Id cliente: " << reservaciones[i]->getIdCliente() << "\n";
					cout << "\n";
					counter++;
				}
			}
		}
	}
	if (counter == 0) {
		cout << "No hay reservaciones por esas fechas " << "\n";
	}
}
//done
void five() {
				ofArchivoReserva.open("reserva.txt", fstream::app);
				Fecha f2;
				bool materialValido = true;
				bool fechaInvalida = true;
				int d, m, a, idMaterial, idCliente, counterOne = 0;

				while (materialValido) {
					cout << "Ingresa el id del material:" << "\n";
					cin >> idMaterial;

					for (int i = 0; i < materialesSize; i++) {
						if (materiales[i]->getIdMaterial() == idMaterial) {
							counterOne++;
						}
					}
					if (counterOne > 0) {
						materialValido = false;
					}
					else if (counterOne == 0) {
						cout << "id No valido" << "\n";
						materialValido = true;
					}
				}

				while (fechaInvalida) {
					bool fp = false;
					cout << "Ingresa el dd, mm y aa " << "\n";
					cin >> d;
					cin >> m;
					cin >> a;
					f2.setFecha(d, m, a);
					
					for (int i = 0; i < reservacionSize; i++) {
						for (int j = 0; j < materialesSize; j++) {
							
								if (f2 >= reservaciones[i]->getFecha() && f2 <= reservaciones[i]->calculaFechaFinReserva(materiales[j]->cantidadDeDiasDePrestamo())) {
									if (idMaterial == reservaciones[i]->getidMaterial()) {
										fp = true;
									}
								}
							
						
						}
					}
					if (fp == true) {
						cout << "Fecha ya ocupada" << "\n";
						fechaInvalida = true;
					}
					else if (fp == false) {
						cout << "Ingresa id del cliente : " << "\n";
						cin >> idCliente;
						reservaciones[reservacionSize] = new Reserva(idMaterial, idCliente, d, m, a);
						reservacionSize++;
						ofArchivoReserva << d << " " << m << " " << a << " " << idMaterial << " " << idCliente << "\n";
						fechaInvalida = false;
					}
				}
				ofArchivoReserva.close();
}
//Main
void app() {
	bool flag = true;
	while (flag) {
		int opcion;
		cout << "1.Consulta lista de materiales*" << "\n";
		cout << "2.Consulta lista de reservaciones*" << "\n";
		cout << "3.Consulta lista de reservaciones de un material dado*" << "\n";
		cout << "4.Consulta lista de reservaciones de una fecha dada" << "\n";
		cout << "5.Hacer una reservacion" << "\n";
		cout << "6.Terminar" << "\n";
		cin >> opcion;
		switch (opcion) {
		case 1:
			one();
			break;
		case 2:
			two();
			break;
		case 3:
			three();
			break;
		case 4:
			four();
			break;
		case 5:
			five();
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

