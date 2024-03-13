#pragma once
#include <SFML\Graphics.hpp>
class Corazon :public sf::Drawable {

private:
	sf::Sprite _item;
	sf::Texture _texture;
	int _vida;
	int _vidarestante;
	int _dado;
	sf::Font _fuente;
	sf::Text _texto2;
	sf::Text _texto;
public:
	Corazon(int vidarestante, int vida);
	void imagencorazon();
	void setvida(int& vida);
	void setvidarestante(int& vidarestante);
	void imagendado();
	void creardado(int dado);
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

