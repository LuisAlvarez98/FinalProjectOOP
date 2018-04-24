#pragma once
#include <string>
#include <iostream>
using namespace std;
class Material {
	protected:
		int idMaterial;
		string titulo;
	public:
		//Constructors
		Material() {
			idMaterial = 0;
			titulo = "";
		}
		Material(int idMaterial, string titulo) {
			this->idMaterial = idMaterial;
			this->titulo = titulo;
		}
		//Setters
		void setIdMaterial(int idMaterial) {
			this->idMaterial = idMaterial;
		}
		void setTitulo(string titulo) {
			this->titulo;
		}
		//Getters
		int getIdMaterial() {
			return idMaterial;
		}
		string getTitulo() {
			return titulo;
		}
		//Abstract Methods
		virtual void muestraDatos() = 0;
		virtual int cantidadDeDiasDePrestamo() = 0;
};