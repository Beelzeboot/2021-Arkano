#include "Items.h"

Corazon::Corazon(int vidarestante, int vida){
	_vida = vida;
	_vidarestante = vidarestante;
	//fuentes
	_fuente.loadFromFile("Numbers.ttf");
	_texto.setFont(_fuente);
	_texto2.setFont(_fuente);
	_texto.setCharacterSize(15);
	_texto2.setCharacterSize(15);
	_texto.setFillColor(sf::Color::White);
	_texto2.setFillColor(sf::Color::White);
	///Corazon
	_texture.loadFromFile("corazon.png");
	_item.setTexture(_texture);
	_item.setTextureRect({ 4,3,18,19 });
	_item.setPosition(9, 12);
	//posicion de textos
	_texto.setPosition(35, 12);
	_texto2.setPosition(75, 12);
	
	_texto.setString(std::to_string(_vidarestante));
	_texto2.setString(std::to_string(_vida));

}



void Corazon::setvida(int& vida)
{
	_vida = vida;
	
	
}

void Corazon::setvidarestante(int& vidarestante)
{
	_vidarestante = vidarestante;
	
}

void Corazon::imagendado()
{
}



void Corazon::imagencorazon()
{
	


}


void Corazon::creardado(int dado)
{
	_dado = dado;
}

void Corazon::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(_item, state);
	target.draw(_texto, state);
	target.draw(_texto2, state);

}
