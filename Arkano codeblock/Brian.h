#pragma once
#include <SFML\Graphics.hpp>
#include "personaje.h"

enum class ESTADOS
{
	Quieto,
	Izquierda,
	Derecha,
	Saltando,
	Salto,
	Arriba,
	Abajo,

};

class Brian:public sf::Drawable, public Personaje{
private:
	sf::Sprite _personaje;
	sf::Texture _texture;
	ESTADOS _estado;
	float _velocidadsalto;
	float _move;
	sf::Vector2f _posicion;
	float _frame;


public:
	Brian();
	void cmd();
	void update();
	void camino();
	void combate(int);
	sf::Sprite& getsprite();
	void combatstance();
	void animacionataque();
	void resetframe() { _frame = 0; }
	const sf::Sprite& checkcolision() const;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	

};

