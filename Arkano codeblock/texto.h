#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class texto:public sf::Drawable
{	private:
	sf::Text _texto;
	sf::Font _fuente;

	public:
		texto();
		void nuevotexto( const char* );
		void posicion(int, int);
		void cambiorojo();
		void cambioblanco();
		void cambiotamanio(int);
		void cambiotexto(const char*);



		void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;
};



