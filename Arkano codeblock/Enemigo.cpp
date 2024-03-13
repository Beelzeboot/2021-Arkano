#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo()
{
	this->textura.loadFromFile("cross2.png");
	this->personaje.setTexture(textura);
	this->personaje.setTextureRect({ 9,8,56,72 });
	this->personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(700, 550 - personaje.getOrigin().y);
	personaje.setScale(-1, 1);
	this->_estado = enemESTADO::respirando;
	this->frame = 0;
	this->leerDeDisco(1);
}

void Enemigo::hacerledanio(int x)
{
	int aux = Personaje::get_vidaRestante() - x;
	if (aux <= 0) {
		Personaje::set_vidaRestante(0);
	}
	else {
		Personaje::set_vidaRestante(aux);
	}
}



void Enemigo::cambioesq()
{
	this->leerDeDisco(2);
	this->textura.loadFromFile("eskeleto2.png");
	this->personaje.setTexture(this->textura);
	this->personaje.setTextureRect({ 8,12,72,98 });
	this->personaje.setScale(-1.3f, 1.3f);
	this->personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	this->personaje.setPosition(600, 580- personaje.getOrigin().y);
	this->_estado = enemESTADO::respirando;
}

void Enemigo::esqrespiro()
{// ESQUELETO QUIETO
	frame += 0.05;

	if (frame > 2) frame = 0;
	personaje.setTextureRect({ 8 + int(frame) * 72,12,72,100 });
}

void Enemigo::esqataque()
{
	frame += 0.1500;
	if (frame > 6) { frame = 0; }
	if (int(frame) < 1) { personaje.setTextureRect({ 8,12,72,98 }); }
	if (int(frame) < 2 && int(frame) >= 1)personaje.setTextureRect({ 8,220,72,90 });
	if (int(frame) < 3 && int(frame) >= 2)personaje.setTextureRect({ 8,220,72,90 });
	if (int(frame) < 4 && int(frame) >= 3)personaje.setTextureRect({ 80,220,91,90 });
	if (int(frame) < 5 && int(frame) >= 4)personaje.setTextureRect({ 80,220,91,90 });
}

void Enemigo::cambiocross()
{
	this->leerDeDisco(1);
	this->textura.loadFromFile("cross2.png");
	this->personaje.setTexture(this->textura);
	this->personaje.setTextureRect({ 9,8,56,72 });
	this->personaje.setScale(-2.f, 1.5f);
	this->personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	this->personaje.setPosition(600, 560 - personaje.getOrigin().y);
}

void Enemigo::crossrespiro()
{
	frame += 0.05;
	if (frame > 2) frame = 0;
	if (int(frame) < 1) { personaje.setTextureRect({ 9,8,56,72 }); };
	if (int(frame) < 2 && int(frame) >= 1) { personaje.setTextureRect({ 72,8,61,74 }); };
}

void Enemigo::crossataque()
{
	frame += 0.2500;
	if (int(frame) >= 6) frame = 0;
	if (int(frame) >= 0) { personaje.setTextureRect({ 9,8,56,72 }); }
	if (int(frame) < 2 && int(frame) >= 1) {
		personaje.setTextureRect({ 5,160,63,81 }); }
	if (int(frame) < 3 && int(frame) >= 2) {
		personaje.setTextureRect({ 5,160,63,81 });
	}
	if (int(frame) < 4 && int(frame) >= 3) { personaje.setTextureRect({ 71,175,87,66 }); }
	if (int(frame) < 5 && int(frame) >= 4) {
		personaje.setTextureRect({ 71,175,87,66 });
	}
	if (int (frame) < 6 && int(frame) >= 5) {
		personaje.setTextureRect({ 71,175,87,66 });
	}
}

void Enemigo::thrallrespiro()
{
	frame += 0.15;
	if (frame > 3) { frame = 0; }
	if (int(frame) < 1)personaje.setTextureRect({ 25,656,116,109 });
	if (int(frame) < 2 && int(frame) >= 1)personaje.setTextureRect({ 149,656,120,109 });
	if (int(frame) < 3 && int(frame) >= 2)personaje.setTextureRect({ 269,656,116,109 });
}
void Enemigo::cambiothrall()
{

	this->leerDeDisco(3);
	this->textura.loadFromFile("orco2.png");
	this->personaje.setTexture(this->textura);
	this->personaje.setTextureRect({ 25,656,116,109 });
	this->personaje.setScale(1.f, 1.f);
	this->personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	this->personaje.setPosition(600, 560 - personaje.getOrigin().y);
}

void Enemigo::thrallataque()
{
	frame += 0.1000;
	if (frame > 14) { frame = 0; }
	//inicio ataque
	if (int(frame) < 1)	personaje.setTextureRect({ 17,800,92,108 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 2 && int(frame) >= 1) personaje.setTextureRect({ 118,769,98,138 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 3 && int(frame) >= 2) personaje.setTextureRect({ 226,795,104,111 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 4 && int(frame) >= 3) personaje.setTextureRect({ 341,795,114,112 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	//primer ataque
	if (int(frame) < 5 && int(frame) >= 4) personaje.setTextureRect({ 458,787,203,121 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 6 && int(frame) >= 5) personaje.setTextureRect({ 660,777,200,130 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 7 && int(frame) >= 6) personaje.setTextureRect({ 860,767,157,145 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	//segundo ataque
	if (int(frame) < 8 && int(frame) >= 7) personaje.setTextureRect({ 21,920,101,138 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 9 && int(frame) >= 8) personaje.setTextureRect({ 134,909,139,146 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 10 && int(frame) >= 9) personaje.setTextureRect({ 283,925,163,132 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 11 && int(frame) >= 10) personaje.setTextureRect({ 455,926,192,131 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 12 && int(frame) >= 11) personaje.setTextureRect({ 657,935,109,122 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 13 && int(frame) >= 12) personaje.setTextureRect({ 775,931,131,127 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);
	if (int(frame) < 14 && int(frame) >= 13) personaje.setTextureRect({ 25,656,116,109 });
	personaje.setOrigin(personaje.getGlobalBounds().width / 2, personaje.getGlobalBounds().height / 2);
	personaje.setPosition(personaje.getPosition().x, personaje.getPosition().y);

}

void Enemigo::respiro(int x)
{
	if (x == 0) { crossrespiro(); }
	if (x == 1) { esqrespiro(); }
	if (x == 2) { thrallrespiro(); }
}

void Enemigo::ataque(int x)
{
	if (x == 0) { crossataque(); }
	if (x == 1) { esqataque(); }
	if (x == 2) { thrallataque(); }
}

void Enemigo::cargoenem(int x)
{
	if (x == 0) {
		cambiocross();
	}
	if (x == 1) {
		cambioesq();
	}
	if (x == 2) {
		cambiothrall();
	}

}

sf::Sprite& Enemigo::getsprite()
{
	return personaje;
}




void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(personaje, states);
}
