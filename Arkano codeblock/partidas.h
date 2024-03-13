#ifndef PARTIDAS_H_INCLUDED
#define PARTIDAS_H_INCLUDED
#include <SFML\Graphics.hpp>
class Partida{

    private:

        /// PROPIEDADES

        char _id[5];
        int _nivel;
        int _vidaRestanteJugador;
        int _vidaRestanteEnemigo;

    public:

        /// METODOS

        char* get_id();
        int get_nivel();
        int get_vidaRestanteJugador();
        int get_vidaRestanteEnemigo();

        void set_id(char*);
        void set_nivel(int);
        void set_vidaRestanteJugador(int);
        void set_vidaRestanteEnemigo(int);

        void mostrar();
        bool leerDeArchivo(int);
        bool escribirEnArchivo();
};

void mostrarPartidasGuardadas();
void partidasGuardadas();
void guardarPartida(int, int, int);
int partidaGuardadaONueva();
char* buscarPartidaEnArchivo();
bool verificarID(char*);
int buscarNivelDePartida(char*);
int buscarVidaJugador(char*);
int buscarVidaEnemigo(char*);

#endif // PARTIDAS_H_INCLUDED
