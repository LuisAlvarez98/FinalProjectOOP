#pragma once
#include <string>
#include <iostream>
using namespace std;
class Material {
	protected:
		int idMaterial;
		string titulo;
	public:
		virtual void muestraDatos() = 0;
		int cantidadDeDiasDePrestamo();
};