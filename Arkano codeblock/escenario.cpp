#include "Escenario.h"

Escenario::Escenario()
{
	_texture.loadFromFile("Desierto.png");
	_escenario.setTexture(_texture);
	_escenario.setOrigin(_escenario.getGlobalBounds().width / 2, _escenario.getGlobalBounds().height / 2);
	_escenario.setPosition(400, 300);
}

void Escenario::cambiocueva()
{
	_texture.loadFromFile("Recorrido 2.png");
	_escenario.setTexture(_texture);

}

void Escenario::cambiomontania()
{
	_texture.loadFromFile("Recorrido 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::cambiodesierto()
{
	_texture.loadFromFile("Recorrido 1.png");
	_escenario.setTexture(_texture);
}
void Escenario::fondobatalla(int x)
{
	if (x == 0) { Escenario::introbatalla1(); }
	if (x == 1) { Escenario::introbatalla2(); }
	if (x == 2) { Escenario::introbatalla3(); }
}
// batallas
void Escenario::introbatalla1()
{
	_texture.loadFromFile("Combate contra 1.png");
	_escenario.setTexture(_texture);
}

void Escenario::introbatalla2()
{
	_texture.loadFromFile("Combate contra 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::introbatalla3()
{
	_texture.loadFromFile("Combate contra 3.png");
	_escenario.setTexture(_texture);
}
//
void Escenario::batalla1()
{
	_texture.loadFromFile("Continuar o nueva partida.png");
	_escenario.setTexture(_texture);
}

void Escenario::batalla2()
{
	_texture.loadFromFile("Continuar o nueva partida.png");
	_escenario.setTexture(_texture);
}

void Escenario::batalla3()
{
	_texture.loadFromFile("Continuar o nueva partida.png");
	_escenario.setTexture(_texture);
}
void Escenario::fondodecisionbrian(int x)
{
	if (x == 0) { Escenario::decision1(); }
	if (x == 1) { Escenario::decision3(); }
	if (x == 2) { Escenario::decision5(); }

}
//turnos y decisión
void Escenario::decision1()
{
	_texture.loadFromFile("Decision de combate 1.png");
	_escenario.setTexture(_texture);
}

void Escenario::decision2()
{
	_texture.loadFromFile("Decision de combate 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::decision3()
{
	_texture.loadFromFile("Decision de combate 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::decision4()
{
	_texture.loadFromFile("Decision de combate 4.png");
	_escenario.setTexture(_texture);
}

void Escenario::decision5()
{
	_texture.loadFromFile("Decision de combate 5.png");
	_escenario.setTexture(_texture);
}

void Escenario::decision6()
{
	_texture.loadFromFile("Decision de combate 6.png");
	_escenario.setTexture(_texture);
}

void Escenario::cambiomenu1()
{
	_texture.loadFromFile("Menu1.png");
	_escenario.setTexture(_texture);
}

void Escenario::cambiomenu2()
{
	_texture.loadFromFile("Menu2.png");
	_escenario.setTexture(_texture);
}

void Escenario::cambiomenu3()
{
	_texture.loadFromFile("Menu3.png");
	_escenario.setTexture(_texture);
}

void Escenario::cambiomenu0()
{
	_texture.loadFromFile("Menu principal.png");
	_escenario.setTexture(_texture);

}

void Escenario::cambiomenupartida()
{
	_texture.loadFromFile("Continuar o nueva partida.png");
	_escenario.setTexture(_texture);

}

void Escenario::curacionb1()
{
	_texture.loadFromFile("Realizando curacion 1.png");
	_escenario.setTexture(_texture);
}

void Escenario::curacionb2()
{
	_texture.loadFromFile("Realizando curacion 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::curacionb3()
{
	_texture.loadFromFile("Realizando curacion 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::curacionb4()
{
	_texture.loadFromFile("Realizando curacion 4.png");
	_escenario.setTexture(_texture);
}

void Escenario::curacionb5()
{
	_texture.loadFromFile("Realizando curacion 5.png");
	_escenario.setTexture(_texture);
}

void Escenario::curacionb6()
{
	_texture.loadFromFile("Realizando curacion 6.png");
	_escenario.setTexture(_texture);
}

void Escenario::libro5()
{
	_texture.loadFromFile("Libro 1.png");
	_escenario.setTexture(_texture);
}

void Escenario::libro4()
{
	_texture.loadFromFile("Libro 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::libro3()
{
	_texture.loadFromFile("Libro 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::libro2()
{
	_texture.loadFromFile("Libro 4.png");
	_escenario.setTexture(_texture);
}

void Escenario::libro1()
{
	_texture.loadFromFile("Libro 5.png");
	_escenario.setTexture(_texture);
}

void Escenario::menupersonajes()
{
	_texture.loadFromFile("Menu de personajes.png");
	_escenario.setTexture(_texture);
}

void Escenario::menupersonajesbrian()
{
	_texture.loadFromFile("Stats de personajes 1.png");
	_escenario.setTexture(_texture);
}

void Escenario::menupersonajescross()
{
	_texture.loadFromFile("Stats de personajes 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::menupersonajesthrall()
{
	_texture.loadFromFile("Stats de personajes 4.png");
	_escenario.setTexture(_texture);
}

void Escenario::menupersonajesazazel()
{
	_texture.loadFromFile("Stats de personajes 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::instrucciones1()
{
	_texture.loadFromFile("Instrucciones 1.png");
	_escenario.setTexture(_texture);
}

void Escenario::instrucciones2()
{
	_texture.loadFromFile("Instrucciones 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::instrucciones3()
{
	_texture.loadFromFile("Instrucciones 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::instrucciones4()
{
	_texture.loadFromFile("Instrucciones 4.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataquecritico1()
{
	_texture.loadFromFile("Ataque critico 1.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataquecritico2()
{
	_texture.loadFromFile("Ataque critico 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataquecritico3()
{
	_texture.loadFromFile("Ataque critico 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataquefallido1()
{
	_texture.loadFromFile("Ataque fallido 1.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataquefallido2()
{
	_texture.loadFromFile("Ataque fallido 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataquefallido3()
{
	_texture.loadFromFile("Ataque fallido 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataqueexitoso1()
{
	_texture.loadFromFile("Ataque exitoso 1.png");
	_escenario.setTexture(_texture);

}

void Escenario::ataqueexitoso2()
{
	_texture.loadFromFile("Ataque exitoso 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataqueexitoso3()
{
	_texture.loadFromFile("Ataque exitoso 3.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataqueenproceso1()
{
	_texture.loadFromFile("Ataque en proceso 1.png");
	_escenario.setTexture(_texture);

}

void Escenario::ataqueenproceso2()
{
	_texture.loadFromFile("Ataque en proceso 2.png");
	_escenario.setTexture(_texture);
}

void Escenario::ataqueenproceso3()
{
	_texture.loadFromFile("Ataque en proceso 3.png");
	_escenario.setTexture(_texture);
}


void Escenario::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_escenario,states);
}
