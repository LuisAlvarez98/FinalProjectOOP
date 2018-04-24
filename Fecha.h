#pragma once
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
		void setMes(int mm) {
			this->mm = mm;
		}
		void setYear(int aa) {
			this->aa = aa;
		}
		void setDia(int dd) {
			this->dd = dd;
		}
		
		//Getters
		int getDia(){
			return dd;
		}
		int getMes() {
			return mm;
		}
		int getYear() {
			return aa;
		}
		//Methods
		void setFecha(int dd, int mm, int aa) {
			this->dd = dd;
			this->mm = mm;
			this->aa = aa;
		}

};