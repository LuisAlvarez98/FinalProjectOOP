#pragma once
#include "Material.h"
class Disco : public Material {
	private:
		int duracion;
	public:
		//Constructors
		Disco():Material() {
			duracion = 0;
		}
		Disco(int idMaterial, string titulo, int duracion) :Material(idMaterial, titulo) {
			this->duracion = duracion;
		}
		//Setters
		void setDuracion(int duracion) {
			this->duracion = duracion;
		}
		//Getters
		int getDuracion() {
			return duracion;
		}
		//Abstract Methods
		void muestraDatos() {
			cout << "id:" << getIdMaterial() << "\n";
			cout << "Tipo: " <<"Disco"<<  "\n";
			cout << "Titulo: " << getTitulo() << "\n";
			cout << "Duracion: " << duracion << "\n";
		}
		int cantidadDeDiasDePrestamo() {
			return 3;
		}
};