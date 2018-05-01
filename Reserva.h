#pragma once
#include "Fecha.h"
class Reserva {
	private:
		int idMaterial;
		int idCliente;
		Fecha fechaReservacion;
	public:
		Reserva() {
			idMaterial = 0;
			idCliente = 0;
			fechaReservacion.setFecha(0, 0, 0);
		}
		Reserva(int idMaterial, int idCliente, int dd, int mm, int aa) {
			this->idMaterial = idMaterial;
			this->idCliente = idCliente;
			fechaReservacion.setFecha(dd, mm, aa);
		}
		Fecha calculaFechaFinReserva(int cantDias);
		void muestra() {
			cout << "idMaterial: "  << idMaterial << "\n";
			cout <<"idCliente: " << idCliente << "\n";
			cout << "Fecha: " <<fechaReservacion.getDia() << " " << fechaReservacion.getMes() << " " << fechaReservacion.getYear() << "\n";
 		}
};