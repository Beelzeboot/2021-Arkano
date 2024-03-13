#ifndef HUMANO_H_INCLUDED
#define HUMANO_H_INCLUDED

#include "arma.h"
#include "armadura.h"

class Personaje{

    protected:

        ///PROPIEDADES
        char _nombre[10];
        int _vida;
        int _vidaRestante;
        int _resis;
        int _boniFuerza;
        Arma _armamento;
        Armadura _armazon;

    public:

        ///GETS
        char * get_nombre();
        int get_vida();
        int get_vidaRestante();
        int get_resis();
        int get_boniFuerza();
        Arma get_armamento();
        Armadura get_armazon();

        ///SETS
        void set_nombre(char *);
        void set_vida(int);
        void set_vidaRestante(int);
        void set_resis(int);
        void set_boniFuerza(int);
        void set_armamento(Arma);
        void set_armazon(Armadura);

        ///METODOS PARA ARCHIVOS
        void cargar();
        void mostrar();
        bool escribirEnDisco();
        bool leerDeDisco(int);
        bool modificarEnDisco(int);

        ///ACCIONES EN COMBATE
        int atacar(int);
        int defenderse();
        int realizarDanio();
        void recibirDanio(int);
        void curarse();
};

///FUNCIONES
int lanzarD20();

#endif // HUMANO_H_INCLUDED
