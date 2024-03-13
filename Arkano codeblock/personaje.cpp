#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include "personaje.h"
#include "rlutil.h"
using namespace rlutil;

///GETS

char * Personaje::get_nombre(){return _nombre;}
int Personaje::get_vida(){return _vida;}
int Personaje::get_vidaRestante(){return _vidaRestante;}
int Personaje::get_resis(){return _resis;}
int Personaje::get_boniFuerza(){return _boniFuerza;}
Arma Personaje::get_armamento(){return _armamento;}
Armadura Personaje::get_armazon(){return _armazon;}

///SETS

void Personaje::set_nombre(char *aux){strcpy(_nombre, aux);}
void Personaje::set_vida(int aux){_vida=aux;}
void Personaje::set_vidaRestante(int aux){_vidaRestante=aux;}
void Personaje::set_resis(int aux){_resis=aux;}
void Personaje::set_boniFuerza(int aux){_boniFuerza=aux;}
void Personaje::set_armamento(Arma obj){_armamento=obj;}
void Personaje::set_armazon(Armadura obj){_armazon=obj;}

/// METODOS PARA ARCHIVOS

void Personaje::cargar(){

    cout << "CARGAR ATRIBUTOS DEL PERSONAJE:" << endl << endl;
    cout << "Nombre:";
    cin >> _nombre;
    cout << "Vida:";
    cin >> _vida;
    cout << "Vida restante:";
    cin >> _vidaRestante;
    cout << "Resistencia:";
    cin >> _resis;
    cout << "Bonificador de fuerza: +";
    cin >> _boniFuerza;
    _armamento.cargar();
    _armazon.cargar();
}

void Personaje::mostrar(){

    cout << "PERSONAJE " << _nombre << endl << endl;
    setColor(LIGHTRED);
    cout << "ATRIBUTOS: " << endl << endl;
    setColor(WHITE);
    cout << "Vida: " << _vidaRestante << "/" <<_vida << endl;
    cout << "Resistencia: " << _resis << endl;
    cout << "Bonificador de fuerza: +" << _boniFuerza << endl;
    _armamento.mostrar();
    _armazon.mostrar();

}

bool Personaje::escribirEnDisco(){

    FILE *p;
    bool escribio;

    p=fopen("personajes.dat", "ab");

    if (p==NULL){

        return false;
    }

    escribio=fwrite(this, sizeof(Personaje), 1, p);

    fclose(p);

    return escribio;
}

bool Personaje::leerDeDisco(int pos){

    FILE *p;
    bool leyo;

    p=fopen("personajes.dat", "rb");

    if (p==NULL){

        return false;
    }

    fseek(p, sizeof(Personaje)*pos, 0);

    leyo=fread(this, sizeof(Personaje), 1, p);

    fclose(p);

    return leyo;
}

bool Personaje::modificarEnDisco(int pos){

    FILE *p;
    bool escribio;

    p=fopen("personajes.dat", "rb+");

    if (p==NULL){

        return false;
    }

    fseek(p, sizeof(Personaje)*pos, 0);

    escribio=fwrite(this, sizeof(Personaje), 1, p);

    fclose(p);

    return escribio;
}

/// ACCIONES EN COMBATE

int Personaje::atacar(int resultadoD20){

    int ataque=resultadoD20+_boniFuerza;

    Sleep(500);
    cout << "ATAQUE DE " << _nombre << endl << endl;
    cout << "D20: " << resultadoD20 << endl;
    cout << "BONIFICADOR DE FUERZA: +" << _boniFuerza << endl;
    cout << "ATAQUE TOTAL: " << ataque << endl;
    cout << "_______________________________________" << endl << endl;

    return ataque;
}

int Personaje::defenderse(){

    int defensa=_resis+_armazon.get_boniResis();

    Sleep(500);
    cout << "DEFENSA DE " << _nombre << endl << endl;
    cout << "RESISTENCIA: " << _resis << endl;
    cout << "BONIFICADOR DE RESISTENCIA DE LA ARMADURA: +" << _armazon.get_boniResis() << endl;
    cout << "DEFENSA TOTAL: " << defensa << endl;
    cout << "_______________________________________" << endl << endl;

    return defensa;
}

void Personaje::recibirDanio(int danio){

    int aux=_vidaRestante-danio;

    if(aux<=0){

        _vidaRestante=0;

    }
    else{

        _vidaRestante=aux;
    }
}

int Personaje::realizarDanio(){

    srand(time(NULL));

    int resultadoDado=(rand()%_armamento.get_dado())+1;

    int danio=resultadoDado+_armamento.get_boniDanio();

    Sleep(500);
    cout << "D" << _armamento.get_dado() << ": " << resultadoDado << endl;
    cout << "BONIFICADOR DE DANIO DEL ARMA: +" << _armamento.get_boniDanio() << endl;
    cout << "DANIO EFECTUADO: " << danio << endl << endl;

    return danio;
}

void Personaje::curarse(){

    srand(time(NULL));

    cls();
    setColor(LIGHTRED);
    cout << " ~ARCANO~" << endl;
    setColor(WHITE);
    cout << "_______________________________________" << endl << endl;
    cout << "CURACION EN PROCESO DE " << _nombre << endl;
    cout << "_______________________________________" << endl << endl;

    if(_vidaRestante==_vida){

        cout << "VITALIDAD YA AL MAXIMO!"<< endl;
        cout << "NO ES POSIBLE INCREMENTARLA MAS" << endl;
        cout << "_______________________________________" << endl << endl;
    }
    else{

        int aux,resultadoDado;
        resultadoDado=(rand()%_armamento.get_dado())+1;
        aux=_vidaRestante+resultadoDado+_armamento.get_boniCuracion();

        if(aux>_vida){

            _vidaRestante=_vida;

            cout << "D" << _armamento.get_dado() << ": " << resultadoDado << endl;
            cout << "BONIFICADOR DE CURACION: +" << _armamento.get_boniCuracion() << endl;
            cout << "CURACION TOTAL: " << resultadoDado+_armamento.get_boniCuracion() << endl;
            cout << "_______________________________________" << endl << endl;
        }
        else{

            _vidaRestante=aux;

            cout << "D" << _armamento.get_dado() << ": " << resultadoDado << endl;
            cout << "BONIFICADOR DE CURACION: +" << _armamento.get_boniCuracion() << endl;
            cout << "CURACION TOTAL: " << resultadoDado+_armamento.get_boniCuracion() << endl;
            cout << "_______________________________________" << endl << endl;
        }
    }

    cout << "VIDA: " << _vidaRestante << "/"<< _vida << endl;
    cout << "_______________________________________" << endl << endl;
    system("pause");

}

///FUNCIONES

int lanzarD20(){

    srand(time(NULL));

    int resultado=(rand()%20)+1;

    return resultado;
}
