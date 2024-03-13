#include <SFML\Graphics.hpp>
#include "texto.h"

texto::texto()
{
	_fuente.loadFromFile("Numbers.ttf");

	_texto.setFont(_fuente);
	_texto.setCharacterSize(15);
	_texto.setFillColor(sf::Color::White);



}


void texto::nuevotexto(const char* n)
{
	_texto.setString(n);

	}


void texto::posicion(int x, int y)
{
	_texto.setPosition(x, y);
}

void texto::cambiorojo()
{
	_texto.setFillColor(sf::Color::Red);
}

void texto::cambioblanco()
{
	_texto.setFillColor(sf::Color::White);
}

void texto::cambiotamanio(int a)
{
	_texto.setCharacterSize(a);
}

void texto::cambiotexto(const char* m)
{
	nuevotexto(m);

}


void texto::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_texto,states);
}
