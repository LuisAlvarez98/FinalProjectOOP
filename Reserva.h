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
		bool esBisiesto(int aa) {
			bool result;
			(aa % 4 == 0) && !(aa % 100 == 0) || (aa % 400 == 0) ? result = true : result = false;
			return result;
		}
		Fecha calculaFechaFinReserva(int cantDias) {
			Fecha fechaFin;
			int aa = fechaReservacion.getYear();
			int mm = fechaReservacion.getMes();
			int dd = fechaReservacion.getDia();

			switch (fechaReservacion.getMes()) {
				case 1:
					dd += cantDias;
					if (dd > 31) {
						dd -= 31;
						mm++;
					}
					break;
				case 2:
					dd += cantDias;
					if (esBisiesto(aa)) {
						if (dd > 29) {
							dd -= 29;
							mm++;
						}
					}
					else {
						if (dd > 28) {
							dd -= 28;
							mm++;
						}
					}
					break;
				case 3:
					dd += cantDias;
					if (dd > 31) {
						dd -= 31;
						mm++;
					}
					
					//31
					break;
				case 4:
					dd += cantDias;
					if (dd > 30) {
						dd -= 30;
						mm++;
					}
					
					//30
					break;
				case 5:
					dd += cantDias;
					if (dd > 31) {
						dd -= 31;
						mm++;
					}
					
					//31
					break;
				case 6:
					//30
					dd += cantDias;
					if (dd > 30) {
						dd -= 30;
						mm++;
					}
					
					break;
				case 7:
					//31
					dd += cantDias;
					if (dd > 31) {
						dd -= 31;
						mm++;
					}
					break;
				case 8:
					//31
					dd += cantDias;
					if (dd > 31) {
						dd -= 31;
						mm++;
					}
					
					break;
				case 9:
					//30
					dd += cantDias;
					if (dd > 30) {
						dd -= 30;
						mm++;
					}
					break;
				case 10:
					//31
					dd += cantDias;
					if (dd > 31) {
						dd -= 31;
						mm++;
					}
					break;
				case 11:
					//30
					dd += cantDias;
					if (dd > 30) {
						dd -= 30;
						mm++;
					}
					break;
				case 12:
					dd += cantDias;
					if (dd > 31) {
						dd -= 31;
						mm++;
					}
					 if (mm > 12) {
						mm = 1;
						aa += 1;
					}
					//31
					break;
			}
			fechaFin.setFecha(dd, mm, aa);
			return fechaFin;
		}
		int getidMaterial() {
			return idMaterial;
		}
		Fecha getFecha() {
			return fechaReservacion;
		}
		int getIdCliente() {
			return idCliente;
		}
};