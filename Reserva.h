#pragma once
#include "Fecha.h"
class Reserva {
	private:
		int idMaterial;
		int idCliente;
		Fecha fechaReservacion;
	public:
		Fecha calculaFechaFinReserva(int cantDias);

};