/*
Done
*/
#pragma once
#include "Material.h"
class Libro : public Material {
	private:
		int numPag;
		string autor;
	public:
		//Constructors
		Libro() :Material() {
			numPag = 0;
			autor = "";
		}
		Libro(int idMaterial, string titulo, int numPag, string autor) :Material(idMaterial, titulo) {
			this->numPag = numPag;
			this->autor = autor;
		}
		//Setters
		void setNumPag(int numPag) {
			this->numPag = numPag;
		}
		void setAutor(string autor) {
			this->autor = autor;
		}
		//Getters
		int getNumPag() {
			return numPag;
		}
		string getAutor() {
			return autor;
		}
		//Abstract Methods
		void muestraDatos() {
			cout << "id:" << getIdMaterial() << "\n";
			cout << "Tipo: " << "Libro" << "\n";
			cout << "Titulo: " << getTitulo() << "\n";
			cout << "Numero de paginas: " << numPag << "\n";
			cout << "Autor: " << autor << "\n";
		}
		int cantidadDeDiasDePrestamo() {
			return 10;
		}
};