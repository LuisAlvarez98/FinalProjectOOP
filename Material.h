/*
Done
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Material {
	protected:
		int idMaterial;
		string titulo;
		char tipo;
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
		void setTipo(char tipo) {
			this->tipo = tipo;
		}
		//Getters
		int getIdMaterial() {
			return idMaterial;
		}
		string getTitulo() {
			return titulo;
		}
		char getTipo() {
			return tipo;
		}
		//Abstract Methods
		virtual void muestraDatos() = 0;
		virtual int cantidadDeDiasDePrestamo() = 0;
};