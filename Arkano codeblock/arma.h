#ifndef ARMA_H_INCLUDED
#define ARMA_H_INCLUDED

class Arma{

    private:

        int _dado;
        int _boniDanio;
        int _boniCuracion;

    public:

        int get_dado();
        int get_boniDanio();
        int get_boniCuracion();

        void set_dado(int);
        void set_boniDanio(int);
        void set_boniCuracion(int);

        void cargar();
        void mostrar();
};

#endif // ARMA_H_INCLUDED
