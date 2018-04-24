#pragma once
class Fecha {
	private:
		int dd;
		int mm;
		int aa;
	public:
		Fecha();
		Fecha(int dd, int mm, int aa);
		friend Fecha operator+(Fecha f1, Fecha f2) {
			Fecha f3;
			f3.setDia(f1.getDia() + f2.getDia());
			return f3;
		}
		void setFecha(int dd, int mm, int aa);
		void setDia(int dd) {
			this->dd = dd;
		}
		int getDia(){
			return dd;
		}

};