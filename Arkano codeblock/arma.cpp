#include <iostream>
using namespace std;
#include "arma.h"
#include "rlutil.h"
using namespace rlutil;

///GETS Y SETS

int Arma::get_dado(){return _dado;}
int Arma::get_boniDanio(){return _boniDanio;}
int Arma::get_boniCuracion(){return _boniCuracion;}

void Arma::set_dado(int aux){_dado=aux;}
void Arma::set_boniDanio(int aux){_boniDanio=aux;}
void Arma::set_boniCuracion(int aux){_boniCuracion=aux;}

///METODOS

void Arma::cargar(){

    cout << endl << "CARGAR ATRIBUTOS DE SU ARMA:" << endl << endl;
    cout << "Dado: D";
    cin >> _dado;
    cout << "Bonificador de Danio: +";
    cin >> _boniDanio;
    cout << "Bonificador de Curacion: +";
    cin >> _boniCuracion;
}

void Arma::mostrar(){

    setColor(LIGHTRED);
    cout << endl << "ATRIBUTOS DE SU ARMA:" << endl << endl;
    setColor(WHITE);
    cout << "Dado: D" << _dado << endl;
    cout << "Bonificador de Danio: +" << _boniDanio << endl;
    cout << "Bonificador de Curacion: +" << _boniCuracion << endl;
}
