#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include "personaje.h"
#include "rlutil.h"
#include "partidas.h"
using namespace rlutil;

/// GETS
char* Partida::get_id(){return _id;}
int Partida::get_nivel(){return _nivel;}
int Partida::get_vidaRestanteJugador(){return _vidaRestanteJugador;}
int Partida::get_vidaRestanteEnemigo(){return _vidaRestanteEnemigo;}

/// SETS
void Partida::set_id(char* aux){strcpy(_id, aux);}
void Partida::set_nivel(int aux){_nivel=aux;}
void Partida::set_vidaRestanteJugador(int aux){_vidaRestanteJugador=aux;}
void Partida::set_vidaRestanteEnemigo(int aux){_vidaRestanteEnemigo=aux;}

/// METODOS AJUSTES
bool Partida::escribirEnArchivo(){

    FILE *p;
    bool ok;

    p=fopen("partidasGuardadas.dat", "ab");

    if (p==NULL){return false;}

    ok=fwrite(this, sizeof(Partida), 1, p);

    fclose(p);

    return ok;
}

bool Partida::leerDeArchivo(int pos){

    FILE *p;
    bool ok;

    p=fopen("partidasGuardadas.dat", "rb");

    if (p==NULL){return false;}

    fseek(p, sizeof(Partida)*pos, 0);

    ok=fread(this, sizeof(Partida), 1, p);

    fclose(p);

    return ok;

}

void Partida::mostrar(){

    cout << "ID: " << _id << endl;
    cout << "NIVEL: " << _nivel+1 << endl;
    cout << "VIDA DEL JUGADOR: " << _vidaRestanteJugador << endl;
    cout << "VIDA DEL ENEMIGO: " << _vidaRestanteEnemigo << endl;
    cout << "_______________________________________" << endl << endl;
}

/// FUNCIONES

void partidasGuardadas(){

    char opcion;

    do{

        cls();
        setColor(LIGHTRED);
        cout << " ~ARCANO~" << endl;
        setColor(WHITE);
        cout << "_______________________________________" << endl << endl;
        cout << "MENU PARTIDAS" << endl;
        cout << "_______________________________________" << endl << endl;
        cout << "1 - VER TODAS LAS PARTIDAS" << endl;
        cout << "2 - BUSCAR PARTIDA" << endl;
        cout << "0 - SALIR" << endl;
        cout << "_______________________________________" << endl << endl;
        cout << "OPCION: ";
        opcion=getkey();

        switch(opcion){

            case 49: /// VER PARTIDAS

                mostrarPartidasGuardadas();

            break;

            case 50: /// BUSCAR UNA PARTIDA
            {

                char id[5];
                int i=0, aux=0;
                Partida p;

                cls();

                setColor(LIGHTRED);
                cout << " ~ARCANO~" << endl;
                setColor(WHITE);
                cout << "_______________________________________" << endl << endl;
                cout << "BUSCANDO PARTIDA" << endl;
                cout << "_______________________________________" << endl << endl;
                cout << "INGRESE EL ID DE 4 LETRAS:";
                cin.getline(id,5,'\n');
                fflush(stdin);
                cin.clear();
                cout << endl << "_______________________________________" << endl << endl;

                while(p.leerDeArchivo(i)){

                    if(strcmp (p.get_id(), id) == 0){

                        aux++;
                        p.mostrar();
                    }

                    i++;
                }

                if(aux==0){

                    setColor(LIGHTRED);
                    cout << "PARTIDA NO ENCONTRADA";
                    setColor(WHITE);
                    cout << endl << "_______________________________________"<< endl << endl;
                }

                system("pause");
            }
            break;
            case 48: /// SALIR

                cls();
                setColor(LIGHTRED);
                cout << " ~ARCANO~" << endl;
                setColor(WHITE);
                cout << "_______________________________________" << endl << endl;
                cout << "SEGURO QUE DESEA SALIR?" << endl << endl;
                cout << "1 - NO" << endl;
                cout << "0 - SI" << endl;
                cout << "_______________________________________"<< endl << endl;
                cout << "OPCION: ";
                opcion=getkey();

            break;
            default: /// OPCION INCORRECTA

                cout << endl << "_______________________________________" << endl << endl;
                setColor(LIGHTRED);
                cout << "OPCION INCORRECTA";
                setColor(WHITE);
                cout << endl << "_______________________________________"<< endl << endl;
                system("pause");

            break;
        }

    }while(opcion!=48);
}

void mostrarPartidasGuardadas(){

    Partida p;
    int i=0;

    cls();
    setColor(LIGHTRED);
    cout << " ~ARCANO~" << endl;
    setColor(WHITE);
    cout << "_______________________________________" << endl << endl;
    cout << "PARTIDAS GUARDADAS" << endl;
    cout << "_______________________________________" << endl << endl;

    while(p.leerDeArchivo(i)){

        p.mostrar();

        i++;
    }

    system("pause");

    return;
}

void guardarPartida(int nivel, int jugadorVidaRestante, int enemigoVidaRestante){

    Partida p;
    char id[5];


    cls();
    setColor(LIGHTRED);
    cout << " ~ARCANO~" << endl;
    setColor(WHITE);
    cout << "_______________________________________" << endl << endl;
    cout << "GUARDANDO PARTIDA" << endl;
    cout << "_______________________________________" << endl << endl;
    cout << "INGRESE 4 LETRAS PARA GUARDAR:";
    cin.getline(id,5,'\n');
    fflush(stdin);
    cin.clear();
    cout << "_______________________________________" << endl << endl;

    while(verificarID(id)==1){ /// Va a hacerlo siempre que sea true, guarda la partida cuando sea false

        cout << "LA PARTIDA YA EXISTE" << endl;
        cout << "INGRESE OTRO ID DIFERENTE" << endl;
        cout << "_______________________________________" << endl << endl;
        system("pause");

        cls();
        setColor(LIGHTRED);
        cout << " ~ARCANO~" << endl;
        setColor(WHITE);
        cout << "_______________________________________" << endl << endl;
        cout << "GUARDANDO PARTIDA" << endl;
        cout << "_______________________________________" << endl << endl;
        cout << "INGRESE 4 LETRAS PARA GUARDAR:";
        cin.getline(id,5,'\n');
        fflush(stdin);
        cin.clear();
        cout << "_______________________________________" << endl << endl;
    }

    cout << "PARTIDA GUARDADA DE FORMA CORRECTA" << endl;
    cout << "_______________________________________" << endl << endl;

    p.set_id(id);
    p.set_nivel(nivel);
    p.set_vidaRestanteJugador(jugadorVidaRestante);
    p.set_vidaRestanteEnemigo(enemigoVidaRestante);
    p.escribirEnArchivo();
    p.mostrar();

    system("pause");
}

int partidaGuardadaONueva(){


    if (sf::Keyboard::isKeyPressed) {
        if (sf::Keyboard::Key::Num1) { return 1; }
        if (sf::Keyboard::Key::Num2) { return 2; }
        if (sf::Keyboard::Key::Num0) { return 0; }
    }
    }

char* buscarPartidaEnArchivo(){

    char id[5];
    int i=0;
    Partida p;

    cls();

    setColor(LIGHTRED);
    cout << " ~ARCANO~" << endl;
    setColor(WHITE);
    cout << "_______________________________________" << endl << endl;
    cout << "BUSCANDO PARTIDA" << endl;
    cout << "_______________________________________" << endl << endl;
    cout << "INGRESE EL ID DE 4 LETRAS:";
    cin.getline(id,5,'\n');
    fflush(stdin);
    cin.clear();

    while(p.leerDeArchivo(i)){

        if(strcmp (p.get_id(), id) == 0){

            return p.get_id();
        }

        i++;
    }

    cout << endl << "_______________________________________" << endl << endl;
    setColor(LIGHTRED);
    cout << "PARTIDA NO ENCONTRADA";
    setColor(WHITE);
    cout << endl << "_______________________________________"<< endl << endl;
    system("pause");
    strcpy(id, "AAAA");
    return id;

}

bool verificarID(char* id){

    Partida p;
    int i=0;

    while(p.leerDeArchivo(i)){

        if(strcmp (p.get_id(), id) == 0){

            return 1;
        }

        i++;
    }

    return 0;
}

int buscarNivelDePartida(char* id){

    Partida p;
    int i=0;

    while(p.leerDeArchivo(i)){

        if(strcmp (p.get_id(), id) == 0){

            return p.get_nivel();
        }

        i++;
    }
}

int buscarVidaJugador(char* id){

    Partida p;
    int i=0;

    while(p.leerDeArchivo(i)){

        if(strcmp (p.get_id(), id) == 0){

            return p.get_vidaRestanteJugador();
        }

        i++;
    }
}

int buscarVidaEnemigo(char* id){

    Partida p;
    int i=0;

    while(p.leerDeArchivo(i)){

        if(strcmp (p.get_id(), id) == 0){

            return p.get_vidaRestanteEnemigo();
        }

        i++;
    }
}

