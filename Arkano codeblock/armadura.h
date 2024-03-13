#ifndef ARMADURA_H_INCLUDED
#define ARMADURA_H_INCLUDED

class Armadura{

	private:

		///PROPIEDADES
		int _boniResis;
		int _durabilidad;

	public:

		///GETS Y SETS

		int get_boniResis();
		void set_boniResis(int);

		///METODOS
		void cargar();
		void mostrar();
};

#endif // ARMADURA_H_INCLUDED
