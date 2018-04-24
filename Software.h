#pragma once
#include "Material.h"
class Software : public Material {
	private:
		string sistemaOper;
	public:
		//Constructors
		Software() :Material() {
			sistemaOper = "";
		}
		Software(int idMaterial, string titulo, string sistemaOper) : Material(idMaterial, titulo) {
			this->sistemaOper = sistemaOper;
		}
		//Setters
		void setSistemaOperativo(string sistemaOper) {
			this->sistemaOper = sistemaOper;
		}
		//Getters
		string getSistemaOperativo() {
			return sistemaOper;
		}
		//Abstract Methods
		void muestraDatos() {
			cout << "id:" << getIdMaterial() << "\n";
			cout << "Tipo: " << "Software" << "\n";
			cout << "Titulo: " << getTitulo() << "\n";
			cout << "Sistema Operativo: " << sistemaOper << "\n";
		}
		int cantidadDeDiasDePrestamo() {
			return 1;
		}

};