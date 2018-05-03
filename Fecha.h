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
		//== done
		friend bool operator==(Fecha f1, Fecha f2) {
			if (f1.getYear() == f2.getYear() && f1.getMes() == f2.getMes() && f1.getDia() == f2.getDia()) {
				return true;
			}
			return false;
		}
		// > done
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
		// < done
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
		//>= done
		friend bool operator >=(Fecha f1, Fecha f2) {
			if (f1 > f2) {
				return true;
			}
			if (f1 == f2) {
				return true;
			}
			return false;
		}
		// <= done
		friend bool operator <=(Fecha f1, Fecha f2) {
			if (f1 < f2) {
				return true;
			}
			if (f1 == f2) {
				return true;
			}
			return false;
		}
		// >> not working
		friend istream& operator>>(istream& is, Fecha &f) {
			is >> f.dd;
			is >> f.mm;
			is >> f.aa;
			return is;
		}
		// << not working
		friend ostream& operator<<(ostream &os, Fecha f) {
			os << f.dd << endl;
			os << f.mm << endl;
			os << f.aa << endl;
			return os;
		}
		inline int getNumMes(int mes) {
			switch (mes) {
				case 2:
					if (esBisiesto(aa)) {
						return 29;
					}
					else {
						return 28;
					}
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					return 30;
					break;
				default:
					return 31;
					break;
			}
		}
		inline bool esBisiesto(int year) {
			bool result;
			(year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0) ? result = true : result = false;
			return result;
			
		}
		friend Fecha operator+(Fecha f1, int cantDias) {
		}
	
		//Nombre mes
		inline string nombreMes(int mes) {
			string result;
			switch (mes) {
				case 1:
					result = "Ene";
					break;
				case 2:
					result = "Feb";
					break;
				case 3:
					result = "Mar";
					break;
				case 4:
					result = "Abr";
					break;
				case 5:
					result = "May";
					break;
				case 6:
					result = "Jun";
					break;
				case 7:
					result = "Jul";
					break;
				case 8:
					result = "Ago";
					break;
				case 9:
					result = "Sep";
					break;
				case 10:
					result = "Oct";
					break;
				case 11:
					result = "Nov";
					break;
				case 12:
					result = "Dic";
					break;
				}
			return result;
		}
};