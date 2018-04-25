#pragma once
#include <string>
#include <iostream>
using namespace std;

class Fecha {
	private:
		int dd;
		int mm;
		int aa;
	public:
		//Constructors
		Fecha() {
			dd = 0;
			mm = 0;
			aa = 0;
		}
		Fecha(int dd, int mm, int aa) {
			this->dd = dd;
			this->mm = mm;
			this->aa = aa;
		}
		//Setters
		inline void setMes(int mm) {
			this->mm = mm;
		}
		inline void setYear(int aa) {
			this->aa = aa;
		}
		inline void setDia(int dd) {
			this->dd = dd;
		}
		
		//Getters
		inline int getDia(){
			return dd;
		}
		inline int getMes() {
			return mm;
		}
		inline int getYear() {
			return aa;
		}
		//Methods
		inline void setFecha(int dd, int mm, int aa) {
			this->dd = dd;
			this->mm = mm;
			this->aa = aa;
		}
		//Sobrecarga de operadores
		//==
		friend bool operator==(Fecha f1, Fecha f2) {
			if (f1.getYear() == f2.getYear() && f1.getMes() == f2.getMes() && f1.getDia() == f2.getDia()) {
				return true;
			}
			return false;
		}
		// > fix
		friend bool operator>(Fecha f1, Fecha f2) {
			if (f1.getYear() > f2.getYear()) 
			{
				return true;
			}else if(f1.getYear() == f2.getYear())
			{
				if (f1.getMes() > f2.getMes())
				{
					return true;
				}else if (f1.getMes() == f2.getMes()) 
				{
					if (f1.getDia() > f2.getDia()) 
					{
						return true;
					}
				}
			}
			return false;
		}
		// < fix
		friend bool operator<(Fecha f1, Fecha f2) {
			if (f1.getYear() < f2.getYear())
			{
				return true;
			}
			else if (f1.getYear() == f2.getYear())
			{
				if (f1.getMes() < f2.getMes())
				{
					return true;
				}
				else if (f1.getMes() == f2.getMes())
				{
					if (f1.getDia() < f2.getDia())
					{
						return true;
					}
				}
			}
			return false;
		}
		//Check fix
		friend bool operator >=(Fecha f1, Fecha f2) {
			if (f1.getYear() >= f2.getYear()) {
				return true;
			}
			else if (f1.getYear() == f2.getYear()) {
				if (f1.getMes() >= f2.getMes()) {
					return true;
				}
				else if (f1.getMes() == f2.getMes()) {
					if (f1.getDia() >= f2.getDia()) {
						return true;
					}
				}
			}
			return false;
		}
		inline string nombreMes(int mes) {
			string result;
			switch (mes) {
				case 1:
					result = "Enero";
					break;
				case 2:
					result = "Febrero";
					break;
				case 3:
					result = "Marzo";
					break;
				case 4:
					result = "Abril";
					break;
				case 5:
					result = "Mayo";
					break;
				case 6:
					result = "Junio";
					break;
				case 7:
					result = "Julio";
					break;
				case 8:
					result = "Agosto";
					break;
				case 9:
					result = "Septiembre";
					break;
				case 10:
					result = "Octubre";
					break;
				case 11:
					result = "Noviembre";
					break;
				case 12:
					result = "Diciembre";
					break;
				}
			return result;
		}
};