#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED
#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include "personaje.h"
#include "partidas.h"
#include "texto.h"
#include "Escenario.h"
#include "Enemigo.h"
#include "Items.h"
#include "Brian.h"
#include "funciones.h"

/*
enum AVENTURA
{
    vacio1 = 80,
    guardadonueva = 81,
    guardadonueva2 = 82

};*/

class Gameplay {

private:
    enum OPCIONES {
        uno = 1,
        dos = 2,
        tres = 3,
        cuatro = 4,
        cinco = 5,
        cero = 6,
        fin = 7,
        si = 9,
        no = 10,
        enter=11,
        vacio = 8,




    };
    enum Estadogame {
        partida = 24,
        combat1 = 25,
        presentacionbatalla=31,
        menubatalla=32,
        combat3 = 27,
        curacbri = 28,
        ataqbrian = 29,
        resultadobrian = 23,
        turnoenemigo = 22,
        decisionenem = 26,
        ataqueenemigos=36,
        resultadoAenemigo =39,
        curacionenemigo=37,
        finalturnoenem=35,
        ultimo=30,


    };
    enum estadoEscenario {
        menuprincipal,
        menupersonajes,
        menudepartidas,
        //escenarios
        escenario1,
        escenario2,
        escenario3,
        //introduccion batalla
        introbatalla,
        //batalla
        batalla1player,
        enemydecision,
        enemyresult,
        //stats personajes
        statsbrian,
        statscross,
        statsazazel,
        statsthrall,
        //historia
        historiaa,
        //libros
        instruccion,
        //ataque y curacion
        atacarbrian1,
        atacarbrian2,

        curarsebrian1,

        atacocross,
        curocross,
        atacoesq,
        curoesq,
        atacothrall,
        curothrall,
        instruccion5,
        //

        salir,
        nada,

    };

    /// PROPIEDADES
    Brian _jugador;
    Enemigo _enemigo[3];
    sf::RectangleShape rectangulo;
    //Combate _combate;
    //sfml
    sf::RenderWindow* window;
    sf::VideoMode video;
    sf::Event sfmlevent;
    sf::Mutex mutex;
    bool endgame;
    sf::Font fuente;
    sf::Text s;
    int canttext;
    sf::Text* _texto;
    OPCIONES opc;
    estadoEscenario background;
    Estadogame est;
    bool booltext;
    Escenario fondo;
    int cantpaglibro;
    int tiempo;
    int ronda;
    int D;
    int D2;
    int D3;
    bool boolD;
    bool booleanodedanios;

        //funciones privadas de la clase
        void initVariables();
        void initWindow() ;
        void initfuente(int pos);
        void inittexto();


    public:

        /// CONSTRUCTOR
        //Gameplay(): _combate(_enemigo[0],_jugador){}
        Gameplay();
        //FUNCIONES PARA SFML

        const bool running() const;
                //Encargado de actualizar los inputs de teclado con eventos
        void pollEvents();
                //encargado de actualizar los escenarios
        void escenarioUpdate();
        void escenariointrobatalla();
        // Escenario enemigos
        void fondodecisionenem();
        void updateGUI();
        void renderGUI(sf::RenderTarget* target);
                 //Encargado de actualizar las entradas de datos
        void maincmd();
                 //Encargado de actualizar el game loop
        void update();
                //Encargado de reenderizar la mayor parte del tiempo
        void render();
                //MUESTRA LA HISTORIA DE ARCANO
        void historia();
                //muestra las opciones y stats de los personajes
        void MENUPERSONAJES();
        bool verificacionENTER();
        void vaciaropcion();
        void instrucciones();
        void iniciaraventura();
        void classmenuupdate();
        int getronda() { return ronda; }


        //Escenarios para todos los ataques
        void escenariosegunpartida();
        void combatesegunpartida();
        void ataquesegunpartida( );
        void ataquefallidosegunpartida();
        void ataqueexitososegunpartida();
        void ataquecriticosegunpartida();
       //Brian
        void ataquebrian();
        void resultadoataquebrian();
        void curacionbrian();
       //enemigo
        void enemigoatacar();
        void ataqueenem();
        void resultadoataqueenemigo();
        void enemigocurar();
        void curacionenem();
        char IAtrucha();
        void danioaenemigos(int , int );

        //archivos gameplay
        void crearArchivogameplay();
        void guardarPartidagameplay();
        void leerpartidaguardada();

///Funciones para interacción del menu y juego
       // void modoAventura(sf::RenderWindow *window, OPCIONES* estado);
       // void reparto(sf::RenderWindow *);
};

/// FUNCIONES


#endif // ESCENARIO_H_INCLUDED
