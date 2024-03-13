# include<iostream>
using namespace std;
#include "armadura.h"
#include "rlutil.h"
using namespace rlutil;

///GETS Y SETS

int Armadura::get_boniResis(){return _boniResis;}
void Armadura::set_boniResis(int aux){_boniResis=aux;}

///METODOS DE ARMADURA

void Armadura::cargar(){

	cout << endl << "CARGAR ATRIBUTOS DE SU ARMADURA:" << endl << endl;
	cout <<"Bonificador de Resistencia: +";
    cin >> _boniResis;
    cout << "______________________________ " << endl << endl;
}

void Armadura::mostrar(){

	setColor(LIGHTRED);
    cout << endl << "ATRIBUTOS DE SU ARMADURA:" << endl << endl;
    setColor(WHITE);
	cout << "Bonificador de Resistencia: +"<< _boniResis << endl;
	cout << "______________________________ " << endl << endl;
}
