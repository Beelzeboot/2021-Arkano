#include "Brian.h"
#include <iostream>


Brian::Brian()
{
	this->leerDeDisco(0);
	_texture.loadFromFile("brian2.png");
	_personaje.setTexture(_texture);
	_personaje.setTextureRect({ 20,16,52,82 });
	_personaje.setOrigin(_personaje.getGlobalBounds().width / 2,_personaje.getGlobalBounds().height/2);
	_personaje.setPosition(50, 580 - _personaje.getOrigin().y);
	_personaje.setScale(-1, 1);
	_frame = 0;
	_velocidadsalto = 0;
	_move = 0;
	_posicion.x = 1;
	_posicion.y = 600;

	_estado = ESTADOS::Quieto;

}
//Secuencia en la que brian camina
void Brian::camino()
{
	_frame += 0.49f;

	if (_frame > 12) {
		_frame = 0;

	}
	_personaje.setTextureRect({ 82 + int(_frame) * 68, 17, 68, 83 });
}

//Secuencia de brian sacando su espada: inicio combate
void Brian::combatstance()
{
	_frame += 0.2f;
	int cont=0,cont2 = 0;

	if (cont > 2) {
		cont = 0;
	}
	if (cont2 > 2) {
		cont2 = 0;
	}
	if (_frame > 9) {
		_personaje.setTextureRect({ 763, 111, 83, 83 });
	}

	if (_frame >= 0 && _frame <= 2) { _personaje.setTextureRect({ 15 + int(_frame) * 85, 111, 85 , 83 }); }

	if (_frame <= 5 && _frame > 2) {
			_personaje.setTextureRect({ 270 +cont* 109,111,109,83 });

		cont++;
		}
	if (_frame <= 6 && _frame > 5) {
		_personaje.setTextureRect({ 597 + cont2 * 83,111,83,83 });
		cont2++;
	}
}
// Secuencia de brian atacando

void Brian::animacionataque()
{
	_frame += 0.45;
	if (_frame < 23 && _frame >= 22) {
		_personaje.setTextureRect({ 763, 111, 83, 83 });
	}
	if( _frame >= 42){ _frame=0;}//23
	//Fila diferente
	if (int(_frame) < 2 && int(_frame) >= 0) {
		_personaje.setTextureRect({ 1563 + int(_frame) * 150, 1070, 150, 84 });
	}
	//Fila consecuente
					//ataque horizontal
	if (_frame < 4 && _frame >= 2) _personaje.setTextureRect({ 1863, 1070, 125, 84 });
	if (_frame < 6 && _frame >= 4) _personaje.setTextureRect({ 1,1200,86,85 });
	if (_frame < 8 && _frame >= 6) _personaje.setTextureRect({ 81,1200,82,83 });
	if (_frame < 10 && _frame >= 8) _personaje.setTextureRect({ 161,1200,124,83 });//modif
	if (_frame < 12 && _frame >= 10) _personaje.setTextureRect({ 285,1200,116,81 });
	if (_frame < 14 && _frame >= 12) _personaje.setTextureRect({ 397,1200,85,83 });
	if (_frame < 16 && _frame >= 14) _personaje.setTextureRect({ 478,1200,76,83 });
	//escendente
	if(_frame< 18 && _frame >= 16) _personaje.setTextureRect({ 547,1200,86,83 });
	if (_frame< 20 && _frame >= 18) _personaje.setTextureRect({ 627,1183,97,101 });
	if (_frame< 22 && _frame >= 20) _personaje.setTextureRect({ 725,1189,93,96 });
	if (_frame < 24 && _frame >= 22) _personaje.setTextureRect({ 821,1189,80,97 });
	if (_frame < 26 && _frame >= 24) _personaje.setTextureRect({ 907,1189,108,94 });
	if (_frame < 28 && _frame >= 26) _personaje.setTextureRect({ 1015,1189,103,95 });
	if (_frame < 30 && _frame >= 28) _personaje.setTextureRect({ 1113,1168,104,116 });//revisado hasta aca nuevamente
	if (_frame < 32 && _frame >= 30) _personaje.setTextureRect({ 1220,1189,151,95 });
	if (_frame < 34 && _frame >= 32) _personaje.setTextureRect({ 1371,1189,132,94 });
	if (_frame < 36 && _frame >= 34) _personaje.setTextureRect({ 1503,1189,108,94 });
	if (_frame < 38 && _frame >= 36) _personaje.setTextureRect({ 1611,1189,117,94 });
	if (_frame < 40 && _frame >= 38) _personaje.setTextureRect({ 1728,1189,108,94 });
	if (_frame < 42 && _frame >= 40) _personaje.setTextureRect({ 1836,1189,113,94 });
	//if (_frame < 23 && _frame >= 22) _personaje.setTextureRect({ 1863, 1070, 130, 83 });

}

const sf::Sprite& Brian::checkcolision() const
{
	return this->_personaje;
	// TODO: Insertar una instrucción "return" aquí
}

//Funcion para llamar a sus animaciones de combate desde gameplay
/*
	1 combatstance,
	2 ataque,
*/
void Brian::combate(int x)
{
	if (x==1) {
		combatstance();
	}
	if (x == 2) {
		animacionataque();
	}

}

sf::Sprite& Brian::getsprite()
{
	return _personaje;
}



// Modificacion de los estados en funcion de datos de entrada
void Brian::cmd()
{
	if (_estado == ESTADOS::Quieto) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_move = 10;
			_estado = ESTADOS::Derecha;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_move = -10;
			_estado = ESTADOS::Izquierda;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			_velocidadsalto =10;
			_estado = ESTADOS::Saltando;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			_move = -10;
			_estado = ESTADOS::Arriba;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			_move = 10;
			_estado = ESTADOS::Abajo;

		}

	}
}


// update del estado del personaje con movimientos
void Brian::update()
{


	//Actualización de estados
	switch (_estado)
	{

	case ESTADOS::Quieto:


		_personaje.setTextureRect({ 20,16,52,82 });
		_posicion.y = _personaje.getPosition().y;
		_posicion.x = _personaje.getPosition().x;
		_estado = ESTADOS::Quieto;
		break;

	case ESTADOS::Derecha:
		camino();
		_personaje.setScale(-1, 1);
		_personaje.move(_move, 0);
		_posicion.y = _personaje.getPosition().y;
		_posicion.x = _personaje.getPosition().x;

		_estado = ESTADOS::Quieto;

		break;

	case ESTADOS::Izquierda:

		_personaje.setScale(1, 1);
		 camino();
		_personaje.move(_move, 0);
		_posicion.y = _personaje.getPosition().y;
		_posicion.x = _personaje.getPosition().x;
		_estado = ESTADOS::Quieto;
		break;

	case ESTADOS::Saltando:
		_velocidadsalto -= 0.5;
		if ( _personaje.getPosition().y == _posicion.y && _velocidadsalto < 0) {
			_velocidadsalto = 0;
			_personaje.setPosition(_posicion.x, _posicion.y);
			_estado = ESTADOS::Quieto;
		}
		else
		{
			_personaje.move(0, -_velocidadsalto);
		}

		break;

	case ESTADOS::Arriba:
		//obstrucciones por camino
		if (_personaje.getPosition().y < 560 - _personaje.getOrigin().y) {
			_personaje.setPosition(_personaje.getPosition().x, 560 - _personaje.getOrigin().y);
		}
		_personaje.move(0, _move);
		_estado = ESTADOS::Quieto;
		break;
	case ESTADOS::Abajo:
		_personaje.move(0, _move);
		_posicion.y = _personaje.getPosition().y;
		_posicion.x = _personaje.getPosition().x;

		_estado = ESTADOS::Quieto;
		break;
	}

	//posiciones para no salirse de la pantalla

	if (_personaje.getPosition().x > 750-_personaje.getOrigin().x ) {
		_personaje.setPosition(750-_personaje.getOrigin().x , _personaje.getPosition().y);
	}
	if (_personaje.getPosition().x < 0 + _personaje.getOrigin().x) {
		_personaje.setPosition(0 + _personaje.getOrigin().x, _personaje.getPosition().y);
	}

	if (_personaje.getPosition().y > 580-_personaje.getOrigin().y) {
		_personaje.setPosition(_personaje.getPosition().x,580-_personaje.getOrigin().y);
		_estado = ESTADOS::Quieto;

	}



}



void Brian::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_personaje, states);
}
