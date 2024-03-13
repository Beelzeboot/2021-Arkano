#pragma once
#include <SFML\Graphics.hpp>

class Escenario:public sf::Drawable
{

private:
	sf::Sprite _escenario;
	sf::Texture _texture;
public:
	Escenario();
	//escenarios
	void cambiocueva();
	void cambiomontania();
	void cambiodesierto();
	//batallas
	void fondobatalla(int);
	void introbatalla1();
	void introbatalla2();
	void introbatalla3();


	void batalla1();
	void batalla2();
	void batalla3();
	//1 3 5 brian  --- 2 cross --3 azazel -- 6 thrall
	void fondodecisionbrian(int );
	void decision1();
	void decision2();
	void decision3();
	void decision4();
	void decision5();
	void decision6();
	//menus
	void cambiomenu1();
	void cambiomenu2();
	void cambiomenu3();
	void cambiomenu0();
	void cambiomenupartida();
	//curaciones
	void curacionb1();
	void curacionb2();
	void curacionb3();
	void curacionb4();
	void curacionb5();
	void curacionb6();
	//libros
	void libro5();
	void libro4();
	void libro3();
	void libro2();
	void libro1();
	//mas menus
	void menupersonajes();
	void menupersonajesbrian();
	void menupersonajescross();
	void menupersonajesthrall();
	void menupersonajesazazel();
	//instrucciones
	void instrucciones1();
	void instrucciones2();
	void instrucciones3();
	void instrucciones4();
	//atancando
	void ataquecritico1();
	void ataquecritico2();
	void ataquecritico3();
	void ataquefallido1();
	void ataquefallido2();
	void ataquefallido3();
	void ataqueexitoso1();
	void ataqueexitoso2();
	void ataqueexitoso3();
	void ataqueenproceso1();
	void ataqueenproceso2();
	void ataqueenproceso3();

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;


};

