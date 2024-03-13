#pragma once
#include <SFML\Graphics.hpp>
#include "personaje.h"
enum class enemESTADO
{
	atacar,
	curarse,
	respirando,

};

class Enemigo:public sf::Drawable, public Personaje{

private:

	sf::Sprite personaje;
	sf::Texture textura;

	float frame;


	enemESTADO _estado;

public:
	Enemigo();
	void hacerledanio(int );
	//cross
	void cambiocross();
	void crossrespiro();
	void crossataque();
	//esqueleto
	void cambioesq();
	void esqrespiro();
	void esqataque();
	//thrall
	void cambiothrall();
	void thrallataque();
	void thrallrespiro();
	void respiro(int);
	void ataque(int );
	void cargoenem(int);
	void resetenemyframe(int a) {  frame=a;}
	sf::Sprite& getsprite();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

