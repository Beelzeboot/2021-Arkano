#include "gameplay.h"


/// FUNCIONES




void Gameplay::initVariables()
{
    this->endgame = false;
    this->_texto = nullptr;
    this->booltext = false;
    this->background = estadoEscenario::menuprincipal;
    this->opc = OPCIONES::vacio;
    this->cantpaglibro = 5;
    this->est = Estadogame::ultimo;
    this->rectangulo.setFillColor(sf::Color::Red);
    this->rectangulo.setSize(sf::Vector2f(50.f, 50.f));
    this->rectangulo.setOutlineColor(sf::Color::Black);
    this->rectangulo.setOrigin(this->rectangulo.getGlobalBounds().left, this->rectangulo.getGlobalBounds().top);
    this->rectangulo.setPosition(710, 480);
    this->_enemigo[0].cambiocross();
    this->_enemigo[1].cambioesq();
    this->_enemigo[2].cambiothrall();
    this->_jugador.resetframe();
    this->_enemigo[0].resetenemyframe(0);
    this->tiempo = 7;
    this->ronda = 0;
    this->boolD = false;
    this->D = 0;
    this->D2 = 0;
    this->D3 = 0;
    this->booleanodedanios = false;
}

void Gameplay::initWindow()
{
    this->video = sf::VideoMode(800, 600);
    this->window = new sf::RenderWindow(video, "ARKANO", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(30);

}

void Gameplay::initfuente(int pos)
{

    this->_texto[pos].setFont(this->fuente);
    this->_texto[pos].setFillColor(sf::Color::White);
    this->_texto[pos].setCharacterSize(26);
}

void Gameplay::inittexto()
{
    if (!this->fuente.loadFromFile("PixellettersFull.ttf")) { std::cout << "ERROR::GAMEPLAY::INITTEXTO::PIXELLETTERS" << std::endl; }

}

Gameplay::Gameplay()
{
    initVariables();
    initWindow();
    inittexto();

}

const bool Gameplay::running() const
{
    return this->window->isOpen();

}


void Gameplay::classmenuupdate()
{
    switch (est)
    {
    case Gameplay::partida:
        escenariosegunpartida();

        break;
    case Gameplay::Estadogame::presentacionbatalla:
        escenariointrobatalla();
        break;
    case Gameplay::Estadogame::menubatalla:
        this->background = estadoEscenario::batalla1player;

        break;
    case Gameplay::combat3:
        break;
    case Gameplay::curacbri:
        this->background = estadoEscenario::curarsebrian1;

        break;
    case Gameplay::ataqbrian:
        ataquebrian();
        break;
    case Gameplay::resultadobrian:
        resultadoataquebrian();
        break;
    case Gameplay::turnoenemigo:
        this->background = estadoEscenario::enemydecision;
        break;
    case Gameplay::decisionenem:

        break;

    case Gameplay::finalturnoenem:
        break;
    case Gameplay::ataqueenemigos:
        ataqueenem();

        break;
    case Gameplay::resultadoAenemigo:

        this->background = estadoEscenario::atacoesq;
        resultadoataqueenemigo();

        break;
    case Gameplay::curacionenemigo:

        break;
    case Gameplay::ultimo:

        break;
    default:

        break;
    }
}


void Gameplay::escenarioUpdate()
{
    switch (background)
    {
    case Gameplay::menuprincipal:
        this->fondo.cambiomenu0();
        break;
    case Gameplay::menupersonajes:
        this->fondo.menupersonajes();
        MENUPERSONAJES();
        break;
    case Gameplay::menudepartidas:
        this->fondo.cambiomenupartida();
        break;
    case Gameplay::escenario1:
        this->fondo.cambiodesierto();
        break;
    case Gameplay::escenario2:
        this->fondo.cambiocueva();
        break;
    case Gameplay::escenario3:
        this->fondo.cambiomontania();
        break;
        //BRIAN
    case Gameplay::introbatalla:
        this->fondo.fondobatalla(ronda);
        break;
    case Gameplay::batalla1player:
        this->fondo.fondodecisionbrian(ronda);
        break;

        //ENEMIGOS
    case Gameplay::enemydecision:
         fondodecisionenem();

        break;
    case Gameplay::enemyresult:

        break;

        //STATS

    case Gameplay::statsbrian:
        vaciaropcion();
        this->fondo.menupersonajesbrian();
        if (verificacionENTER() == true) { this->background = estadoEscenario::menupersonajes; }
        break;

    case Gameplay::statscross:
        vaciaropcion();
        this->fondo.menupersonajescross();
        if (verificacionENTER() == true) { this->background = estadoEscenario::menupersonajes; }
        break;

    case Gameplay::statsazazel:
        vaciaropcion();
        this->fondo.menupersonajesazazel();
        if (verificacionENTER() == true) { this->background = estadoEscenario::menupersonajes; }
        break;

    case Gameplay::statsthrall:
        vaciaropcion();
        this->fondo.menupersonajesthrall();
        if (verificacionENTER() == true) { this->background = estadoEscenario::menupersonajes; }
        break;

    case Gameplay::historiaa:
        historia();
        break;

    case Gameplay::instruccion:
        instrucciones();
        break;
    case Gameplay::atacarbrian1:


        break;
    case Gameplay::atacarbrian2:


        break;

    case Gameplay::curarsebrian1:
        break;

    case Gameplay::atacocross:
        //en uso
        break;
    case Gameplay::curocross:
        break;
    case Gameplay::atacoesq:
        break;
    case Gameplay::curoesq:
        break;
    case Gameplay::atacothrall:
        break;
    case Gameplay::curothrall:
        break;
    case Gameplay::salir:
        break;
    default:
        break;
    }
}


void Gameplay::maincmd() {

    //para menus o submenus

    if (this->background == estadoEscenario::menuprincipal) {

        switch (opc)
        {
        case Gameplay::uno:
            this->background = estadoEscenario::menudepartidas;

            break;
        case Gameplay::dos:
            vaciaropcion();
            this->background = estadoEscenario::historiaa;

            break;
        case Gameplay::tres:
            vaciaropcion();
            this->background = estadoEscenario::menupersonajes;
            break;
        case Gameplay::cuatro:
            vaciaropcion();
            this->background = estadoEscenario::instruccion;

            break;
        case Gameplay::cinco:

            break;
        case Gameplay::cero:
            this->endgame = true;
            break;
        case Gameplay::fin:
            break;
        case Gameplay::si:
            break;
        case Gameplay::no:
            break;
        case Gameplay::enter:
            break;
        case Gameplay::vacio:
            break;
        default:
            break;
        }
    }


 if (this->background == estadoEscenario::menudepartidas) {

         switch (opc)
         {
         case Gameplay::uno:
           // leerpartidaguardada();
             break;
         case Gameplay::dos:
             iniciaraventura();
             break;

         case Gameplay::cero:
             this->endgame = true;
             break;
         default:
             break;
         }
     }

  if(this->background == estadoEscenario::batalla1player){

      switch (opc)
      {
      case Gameplay::uno:
          this->est = Estadogame::ataqbrian;


          break;
      case Gameplay::dos:
          this->est = Estadogame::curacbri;
          break;

      case Gameplay::cero:
          crearArchivogameplay();
          this->_jugador.set_vidaRestante(_jugador.get_vida());
          this->_enemigo[0].set_vidaRestante(_enemigo[0].get_vida());
          this->_enemigo[1].set_vidaRestante(_enemigo[1].get_vida());
          this->_enemigo[2].set_vidaRestante(_enemigo[2].get_vida());
          guardarPartidagameplay();
          this->endgame = true;
          break;

      default:
          break;
      }

  }
  if (this->background == estadoEscenario::introbatalla) {
      vaciaropcion();
      if (verificacionENTER() == true) { this->est = Estadogame::menubatalla; this->background = estadoEscenario::batalla1player; }

  }

  if (this->background == estadoEscenario::enemydecision) {

      if (verificacionENTER() == true) {
      this->est = Estadogame::decisionenem;
      }


  }








  if (this->est == Estadogame::curacbri) { curacionbrian(); }






}//fin





        //Actualización del estado del juego en general

void Gameplay::update()
{
    //std::cout << "vida restante jugador: "<<_jugador.get_vidaRestante()<<"\n";
    //std::cout << "vida restante enemigo: " << _enemigo[this->ronda].get_vidaRestante()<<"\n";
    //std::cout << "VIDA cros: " << this->_enemigo[0].get_vidaRestante() << "\n\n";
    //std::cout <<"VIDA esq: " << this->_enemigo[1].get_vidaRestante() << "\n\n";
    //std::cout << "VIDA thrall: " << this->_enemigo[2].get_vidaRestante() << "\n\n";

    escenarioUpdate();
    classmenuupdate();
    pollEvents();
    //ENDGAME TECLA "ESC"
    if (this->endgame) { this->window->close(); }

    if(this->ronda != 3 && this->_enemigo[ronda].get_vidaRestante() == 0){

        this->ronda++;
        this->_enemigo[ronda - 1].set_vidaRestante(-1);
        this->est = Estadogame::partida;
    }

    if (this->_jugador.get_vidaRestante() == 0) {

        // CARTEL DE PERDISTE O  this->BACKGROUND = Estadogame::perdiste
        this->endgame = true;

    }
    if(this->est == Estadogame::ultimo){

        maincmd();
    }
    if(this->est == Estadogame::ataqueenemigos){ this->_enemigo[this->ronda].ataque(this->ronda); }


    if (this->est == Estadogame::partida) {
        this->_jugador.cmd();
        this->_jugador.update();
        if (this->_jugador.checkcolision().getGlobalBounds().intersects(this->rectangulo.getGlobalBounds())) {

            this->est = Estadogame::presentacionbatalla;
        }
    }



    if (this->est != Estadogame::partida && this->est != Estadogame::ultimo ) {



        this->tiempo = this->tiempo - 1;

        this->_jugador.getsprite().setPosition(130, 540 - this->_jugador.getsprite().getOrigin().y);

        if(this->est != Estadogame::ataqueenemigos && this->background != estadoEscenario::enemydecision){this->_enemigo[ronda].respiro(ronda);}

         if(this->est != Estadogame::ataqbrian) //1 combatstance 2 ataque brian
            this->_jugador.combate(1);

        if (this->est == Estadogame::decisionenem) {
            this->background = estadoEscenario::atacocross;
            char opcionIA = IAtrucha();
            switch (opcionIA)
            {
            case '1':
                this->est = Estadogame::ataqueenemigos;
                break;
            case '2':
                this->est = Estadogame::ataqueenemigos;
                //enemigocurar();
                break;

            }

        }


        if (this->est == Estadogame::finalturnoenem) { system("pause");std::cout << "llego\n"; }
        maincmd();


    }




}


void Gameplay::render()
{
    this->window->clear();

    this->window->draw(fondo);


    if(this->booltext== true){
        for (int j = 0; j < canttext; j++) {
        this->window->draw(this->_texto[j]);
    }
    } //endif

    if(this->est == Estadogame::partida){
        this->window->draw(rectangulo);
        this->window->draw(fondo);
        this->window->draw(this->_jugador);

    }
    if (this->est != Estadogame::ultimo && this->est != Estadogame::partida ) {
        this->window->draw(this->_jugador);
        this->window->draw(this->_enemigo[ronda]);
    }





    this->window->display();
}
//MUESTRA LA HISTORIA DE ARCANO
void Gameplay::historia()
{
    //setlocale(LC_ALL, "Spanish");
    switch (this->cantpaglibro)
    {
    case 1:
        this->fondo.libro1();
        if (verificacionENTER() == true) {
            this->cantpaglibro = 5;
            this->background = estadoEscenario::menuprincipal;
        }

        break;
    case 2:
        this->fondo.libro2();
        if (verificacionENTER() == true) {
            this->cantpaglibro -= 1;
        }
        break;
    case 3:
        this->fondo.libro3();
        if (verificacionENTER() == true) {
            this->cantpaglibro -= 1;
        }
        break;
    case 4:
        this->fondo.libro4();
        if (verificacionENTER() == true) {
            this->cantpaglibro -= 1;
        }
        break;
    case 5:
        this->fondo.libro5();
        if(verificacionENTER()==true){
           this->cantpaglibro -= 1;
        }
        break;

    }




}
void Gameplay::MENUPERSONAJES()
{
    switch (opc)
    {
    case Gameplay::uno:
        vaciaropcion();
        this->background = estadoEscenario::statsbrian;
        break;
    case Gameplay::dos:
        vaciaropcion();
        this->background = estadoEscenario::statscross;
        break;
    case Gameplay::tres:
        vaciaropcion();
        this->background = estadoEscenario::statsazazel;
        break;
    case Gameplay::cuatro:
        vaciaropcion();
        this->background = estadoEscenario::statsthrall;
        break;
    case Gameplay::cero:
        vaciaropcion();
        this->background = estadoEscenario::menuprincipal;
        break;

    }
}
bool Gameplay::verificacionENTER()
{

        this->booltext = true;

        this->canttext = 1;
        this->_texto = new sf::Text[canttext];

        for (int i = 0;i < 1;i++) {
            initfuente(i);
            _texto[i].setString("PRESIONE ENTER");
            _texto[i].setCharacterSize(25);
            _texto[i].setPosition(330, 500);
        }
        if (rand() % 2) {
            _texto[0].setString("         ");
        }

        if (this->sfmlevent.key.code == sf::Keyboard::Key::Enter) {
            this->booltext = false;
            delete[] this->_texto;
            this->opc = OPCIONES::vacio;
            this->sfmlevent.key.code = sf::Keyboard::Key::Pause;


            return true;

        }
return false;

}

void Gameplay::vaciaropcion()
{
    this->opc = OPCIONES::vacio;
    this->window->setKeyRepeatEnabled(false);

}
        //Actualización de eventos del teclado
void Gameplay::pollEvents()
{
    while (this->window->pollEvent(this->sfmlevent)) {

        switch (this->sfmlevent.type) {

        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->sfmlevent.key.code == sf::Keyboard::Escape) {
                this->window->close();

            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num1) {
                this->opc = OPCIONES::uno;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num2) {
                this->opc = OPCIONES::dos;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num3) {
                this->opc = OPCIONES::tres;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num4) {
                this->opc = OPCIONES::cuatro;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num5) {
                this->opc = OPCIONES::cinco;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num0) {
                this->opc = OPCIONES::cero;

            }
            if (this->sfmlevent.key.code == sf::Keyboard::S) {
                this->opc = OPCIONES::si;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::N) {
                this->opc = OPCIONES::no;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Enter) {
                this->opc = OPCIONES::enter;
            }



            break;

        case sf::Event::KeyReleased:
            if (this->sfmlevent.key.code == sf::Keyboard::Num1) {
                this->opc = OPCIONES::vacio;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num2) {
                this->opc = OPCIONES::vacio;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num3) {
                this->opc = OPCIONES::vacio;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num4) {
                this->opc = OPCIONES::vacio;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num5) {
                this->opc = OPCIONES::vacio;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::Num0) {
                this->opc = OPCIONES::vacio;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::S) {
                this->opc = OPCIONES::vacio;
            }
            if (this->sfmlevent.key.code == sf::Keyboard::N) {
                this->opc = OPCIONES::vacio;}
            if (this->sfmlevent.key.code == sf::Keyboard::Enter) {
                this->opc = OPCIONES::vacio;
            }




                break;

    }


    }
}


void Gameplay::escenariointrobatalla()
{
    this->background = estadoEscenario::introbatalla;
}


void Gameplay::instrucciones()
{


    switch (cantpaglibro)
    {
    case 1:
        break;

    case 2:
        this->fondo.instrucciones4();
        if (verificacionENTER()==true) {
            this->cantpaglibro = 5;
            this->background = estadoEscenario::menuprincipal;
        }

        break;
    case 3:
        this->fondo.instrucciones3();
        if (verificacionENTER()==true) { cantpaglibro -= 1; }
        break;
    case 4:
        this->fondo.instrucciones2();
        if (verificacionENTER()==true) { cantpaglibro -= 1; }
        break;

    case 5:
        this->fondo.instrucciones1();
         if (verificacionENTER()==true) { cantpaglibro -= 1; }
        break;
    }

}

void Gameplay::iniciaraventura()
{

    this->est = Estadogame::partida;

}


void Gameplay::curacionbrian()
{
    this->booltext = true;
    this->canttext = 2;
    this->_texto = new sf::Text[canttext];

    for (int i = 0;i < 1;i++) {
        initfuente(i);
        _texto[i].setString("PRESIONE ENTER");
        _texto[i].setOutlineColor(sf::Color::White);
        _texto[i].setCharacterSize(25);
        _texto[i].setPosition(330, 500);
    }
    if (rand() % 2) {
        _texto[0].setString("         ");
    }

    //curación con vida maxima igual a vida

  if (this->_jugador.get_vidaRestante() == this->_jugador.get_vida()) {
        if (this->ronda == 0) { this->fondo.curacionb1(); }
        if (this->ronda == 1) { this->fondo.curacionb3(); }
        if (this->ronda == 2) { this->fondo.curacionb5(); }
        for (int j = 1;j < this->canttext;j++) {
            initfuente(j);
            _texto[j].setString(std::to_string(this->_jugador.get_vida()));
            _texto[j].setOutlineColor(sf::Color::White);
            _texto[j].setPosition(250, 223);
        }
    }
 else{
    //escenarios
    if (this->ronda == 0) { this->fondo.curacionb2(); }
    if (this->ronda == 1) { this->fondo.curacionb4(); }
    if (this->ronda == 2) { this->fondo.curacionb6(); }
    // curación con vida maxima menos a vida
            int aux;
            if(this->boolD == false){
            this->D = (rand() % this->_jugador.get_armamento().get_dado()) + 1;
            this->boolD = true;
            }
            aux = this->_jugador.get_vidaRestante() + this->D + this->_jugador.get_armamento().get_boniCuracion();
            this->canttext = 5;
            this->_texto = new sf::Text[canttext];


        if (aux >= this->_jugador.get_vida()) {
        //textos

        if(this->booleanodedanios==false){
        this->_jugador.set_vidaRestante(this->_jugador.get_vida());
        }


        for (int j = 1;j < this->canttext;j++) {
            initfuente(j);
            _texto[j].setOutlineColor(sf::Color::White);


                     if (j == 1) {
                      _texto[j].setString(std::to_string(this->D));
                       _texto[j].setPosition(250, 148);
            }
                     if (j == 2) {
                         _texto[j].setString(std::to_string(this->_jugador.get_armamento().get_boniCuracion()));
                         _texto[j].setPosition(364, 168);
                     }
                     if (j == 3) {
                         _texto[j].setString(std::to_string(this->_jugador.get_armamento().get_boniCuracion()+ this->D));
                         _texto[j].setPosition(320, 198);
                     }
                     if (j == 4) {
                         _texto[j].setString(std::to_string(this->_jugador.get_vidaRestante()));
                         _texto[j].setPosition(245, 246);
                     }}
        }
        else {
            if(this->booleanodedanios==false){
            this->_jugador.set_vidaRestante(aux);
            }
            for (int j = 1;j < this->canttext;j++) {
                initfuente(j);
                _texto[j].setOutlineColor(sf::Color::White);


                if (j == 1) {
                    _texto[j].setString(std::to_string(this->D));
                    _texto[j].setPosition(250, 148);
                }
                if (j == 2) {
                    _texto[j].setString(std::to_string(this->_jugador.get_armamento().get_boniCuracion()));
                    _texto[j].setPosition(364, 168);
                }
                if (j == 3) {
                    _texto[j].setString(std::to_string(this->_jugador.get_armamento().get_boniCuracion() + this->D));
                    _texto[j].setPosition(320, 198);
                }
                if (j == 4) {
                    _texto[j].setString(std::to_string(this->_jugador.get_vidaRestante()));
                    _texto[j].setPosition(245, 246);
                }
            }


        }

}

  this->booleanodedanios = true;


  if (this->sfmlevent.key.code == sf::Keyboard::Key::Enter) {
    this->booltext = false;
    delete[] this->_texto;
    this->boolD = false;
    this->booleanodedanios = false;
    this->D = 0;
    this->est = Estadogame::turnoenemigo;
    }





}

void Gameplay::curacionenem()
{











}

char Gameplay::IAtrucha()
{
        int ve, vj;
        char opcion;

        vj = this->_jugador.get_vidaRestante();
        ve = this->_enemigo[this->ronda].get_vidaRestante();

        if (ve > 5) {
            if (vj > 5) {
                if (vj > 10) {
                    if (ve > 10) {
                        opcion = '1';
                    }
                    else {
                        opcion = '2';
                    }
                }
                else {
                    opcion = '1';
                }
            }
            else {
                opcion = '1';
            }
        }
        else {
            if (vj > 5) {
                opcion = '2';
            }
            else {
                opcion = '1';
            }
        }
        return opcion;

}




void Gameplay::fondodecisionenem()
{
    if (this->ronda == 0) { this->fondo.decision2(); }
    if (this->ronda == 1) { this->fondo.decision4(); }
    if (this->ronda == 2) { this->fondo.decision6(); }


}

void Gameplay::escenariosegunpartida()
{if(this->ronda ==0){
    this->background = estadoEscenario::escenario1;
}if (this->ronda == 1) {
    this->background = estadoEscenario::escenario2;
}
if (this->ronda == 2) {
    this->background = estadoEscenario::escenario3;
}


}

void Gameplay::combatesegunpartida()
{
        this->background = estadoEscenario::introbatalla;
}


void Gameplay::ataquesegunpartida()
{
    if (this->ronda == 0) {
        this->fondo.ataqueenproceso1();
    }
    if (this->ronda == 1) {
        this->fondo.ataqueenproceso2();
    }
    if (this->ronda == 2) {
        this->fondo.ataqueenproceso3();
    }

}

void Gameplay::ataquefallidosegunpartida()
{
    if (this->ronda == 0) {
        this->fondo.ataquefallido1();
    }
    if (this->ronda == 1) {
        this->fondo.ataquefallido2();
    }
    if (this->ronda == 2) {
        this->fondo.ataquefallido3();
    }
}

void Gameplay::ataqueexitososegunpartida()
{
    if (this->ronda == 0) {
        this->fondo.ataqueexitoso1();
    }
    if (this->ronda == 1) {
        this->fondo.ataqueexitoso2();
    }
    if (this->ronda == 2) {
        this->fondo.ataqueexitoso3();
    }

}

void Gameplay::ataquecriticosegunpartida()
{
    if (this->ronda == 0) {
        this->fondo.ataquecritico1();
    }
    if (this->ronda == 1) {
        this->fondo.ataquecritico2();
    }
    if (this->ronda == 2) {
        this->fondo.ataquecritico3();
    }
}

void Gameplay::ataquebrian()
{
    this->booltext = true;
    this->canttext = 9;
    this->_texto = new sf::Text[canttext];

    ataquesegunpartida();
    this->_jugador.combate(2);
    for (int i = 0;i < 1;i++) {
        initfuente(i);
        _texto[i].setString("PRESIONE ENTER");
        _texto[i].setCharacterSize(25);
        _texto[i].setPosition(330, 500);
    }
    if (rand() % 2) {
        _texto[0].setString("         ");
    }



    if (this->boolD == false) {
        this->D = (rand() % 20) + 1;
        this->boolD = true;
    }
    int ataque = this->D + this->_jugador.get_boniFuerza();
    int defensa = this->_enemigo[ronda].get_resis() + this->_enemigo[ronda].get_armazon().get_boniResis();

    for (int j = 1;j < this->canttext;j++) {
        initfuente(j);
        _texto[j].setOutlineColor(sf::Color::White);


        if (j == 1) {
            _texto[j].setString(this->_jugador.get_nombre());
            _texto[j].setPosition(290, 98);
        }
        if (j == 2) {
            _texto[j].setString(std::to_string(this->D));
            _texto[j].setPosition(245, 149);
        }
        if (j == 3) {
            _texto[j].setString(std::to_string(this->_jugador.get_boniFuerza()));
            _texto[j].setPosition(350, 170);
        }
        if (j == 4) {
            _texto[j].setString(std::to_string(ataque));
            _texto[j].setPosition(308, 198);
        }
        if (j == 5) {
            _texto[j].setString(this->_enemigo[ronda].get_nombre());
            _texto[j].setPosition(294, 247);
        }
        if (j == 6) {
            _texto[j].setString(std::to_string(this->_enemigo[ronda].get_resis()));
            _texto[j].setPosition(305, 298);
        }
        if (j == 7) {
            _texto[j].setString(std::to_string(this->_enemigo[ronda].get_armazon().get_boniResis()));
            _texto[j].setPosition(516, 322);
        }
        if (j == 8) {
            _texto[j].setString(std::to_string(defensa));
            _texto[j].setPosition(314, 347);
        }
    }









    if (this->sfmlevent.key.code == sf::Keyboard::Key::Enter) {
        this->booltext = false;
        delete[] this->_texto;
        this->boolD = false;
        this->booleanodedanios = false;
        //this->_enemigo[ronda].resetframe(0);
        this->opc = OPCIONES::vacio;
        this->sfmlevent.key.code = sf::Keyboard::Key::Pause;
        this->est = Estadogame::resultadobrian;

    }

}


void Gameplay::resultadoataquebrian()
{
    this->booltext = true;
    this->canttext = 8;
    this->_texto = new sf::Text[canttext];

    for (int i = 0;i < 1;i++) {
        initfuente(i);
        _texto[i].setString("PRESIONE ENTER");
        _texto[i].setCharacterSize(25);
        _texto[i].setPosition(330, 500);
    }
    if (rand() % 2) {
        _texto[0].setString("         ");
    }
    int ataque = this->D + this->_jugador.get_boniFuerza();
    int defensa = this->_enemigo[this->ronda].get_resis() + this->_enemigo[ronda].get_armazon().get_boniResis();

    // ATAQUE PIFIADO
    if (this->D == 1 || ataque < defensa) {
        ataquefallidosegunpartida();

    }
    //ATAQUE CRITICO
    if (this->D == 20) {

        ataquecriticosegunpartida();
         if (this->boolD == false) {
                this->D2 = (rand() % this->_jugador.get_armamento().get_dado()) + 1;
                this->D3 = (rand() % this->_jugador.get_armamento().get_dado()) + 1;
                this->boolD = true;
         }

        int danio1 = this->_jugador.get_armamento().get_boniDanio() + this->D2;
        int danio2 = this->_jugador.get_armamento().get_boniDanio() + this->D3;
        int daniofinal = danio1 + danio2;


        //primer dado
        for (int j = 1;j < 4;j++) {
            initfuente(j);
            _texto[j].setOutlineColor(sf::Color::White);

            if (j == 1) {
                _texto[j].setString(std::to_string(this->D2));
                _texto[j].setPosition(365, 148);
            }
            if (j == 2) {
                _texto[j].setString(std::to_string(this->_jugador.get_armamento().get_boniDanio()));
                _texto[j].setPosition(410, 170);
            }
            if (j == 3) {
                _texto[j].setString(std::to_string(danio1));
                _texto[j].setPosition(330, 198);


            }
        }
        //segundo dado
        for (int j = 4;j < this->canttext; j++) {
            initfuente(j);
            _texto[j].setOutlineColor(sf::Color::White);
            if (j == 4) {
                _texto[j].setString(std::to_string(this->D3));
                _texto[j].setPosition(365, 248);
            }
            if (j == 5) {
                _texto[j].setString(std::to_string(this->_jugador.get_armamento().get_boniDanio() ));
                _texto[j].setPosition(410, 270);
            }
            if (j == 6) {
                _texto[j].setString(std::to_string(danio2));
                _texto[j].setPosition(330, 298);
            }
            if (j == 7) {
                _texto[j].setString(std::to_string(daniofinal));
                _texto[j].setPosition(369, 348);
            }
        }
       //recibe daño el enemigo
        if (this->booleanodedanios == false) {
            this->_enemigo[this->ronda].hacerledanio(daniofinal);
        }


    }


    // ATAQUE EXITOSO
    if (this->D != 20 && this->D != 1 && ataque >= defensa) {
        ataqueexitososegunpartida();

        int danio = this->_jugador.get_armamento().get_boniDanio() + this->D;

        for (int j = 1;j < this->canttext;j++) {
            initfuente(j);
            _texto[j].setOutlineColor(sf::Color::White);

            if (j == 1) {
                _texto[j].setString(std::to_string(this->D));
                _texto[j].setPosition(365, 148);
            }
            if (j == 2) {
                _texto[j].setString(std::to_string(this->_jugador.get_armamento().get_boniDanio()));
                _texto[j].setPosition(410, 170);
            }
            if (j == 3) {
                _texto[j].setString(std::to_string(danio));
                _texto[j].setPosition(330, 198);
            }
            if (j == 4) { _texto[j].setString("    "); }
            if (j == 5) { _texto[j].setString("    "); }
            if (j == 6) { _texto[j].setString("    "); }
            if (j == 7) { _texto[j].setString("    "); }
        }

        if (this->booleanodedanios == false) {
            //danioaenemigos(this->ronda, daño);
            this->_enemigo[this->ronda].hacerledanio(danio);
        }
    }

    this->booleanodedanios = true;




    if (this->sfmlevent.key.code == sf::Keyboard::Key::Enter) {
        this->booltext = false;
        delete[] this->_texto;
        this->boolD = false;
        this->booleanodedanios = false;
        this->D = 0;
        this->D2 = 0;
        this->D3 = 0;
        this->opc = OPCIONES::vacio;
        this->sfmlevent.key.code = sf::Keyboard::Key::Comma;
        this->est = Estadogame::turnoenemigo;

    }

}

void Gameplay::ataqueenem()
{
    this->booltext = true;
    this->canttext = 9;
    this->_texto = new sf::Text[canttext];
    ataquesegunpartida();
    this->_enemigo[this->ronda].ataque(this->ronda);

    for (int i = 0;i < 1;i++) {
        initfuente(i);
        _texto[i].setString("PRESIONE ENTER");
        _texto[i].setCharacterSize(25);
        _texto[i].setPosition(330, 500);
    }
    if (rand() % 2) {
        _texto[0].setString("         ");
    }

    if (this->boolD == false) {
        this->D = (rand() % 20) + 1;
        this->boolD = true;
    }
    int ataque = this->D + this->_enemigo[this->ronda].get_boniFuerza();
    int defensa = this->_jugador.get_resis() + this->_jugador.get_armazon().get_boniResis();

    for (int j = 1;j < this->canttext;j++) {
        initfuente(j);
        _texto[j].setOutlineColor(sf::Color::White);


        if (j == 1) {
            _texto[j].setString(this->_enemigo[this->ronda].get_nombre());
            _texto[j].setPosition(290, 98);
        }
        if (j == 2) {
            _texto[j].setString(std::to_string(this->D));
            _texto[j].setPosition(245, 149);
        }
        if (j == 3) {
            _texto[j].setString(std::to_string(this->_enemigo[this->ronda].get_boniFuerza()));
            _texto[j].setPosition(350, 170);
        }
        if (j == 4) {
            _texto[j].setString(std::to_string(ataque));
            _texto[j].setPosition(308, 198);
        }
        if (j == 5) {
            _texto[j].setString(this->_jugador.get_nombre());
            _texto[j].setPosition(294, 247);
        }
        if (j == 6) {
            _texto[j].setString(std::to_string(this->_jugador.get_resis()));
            _texto[j].setPosition(305, 298);
        }
        if (j == 7) {
            _texto[j].setString(std::to_string(this->_jugador.get_armazon().get_boniResis()));
            _texto[j].setPosition(516, 322);
        }
        if (j == 8) {
            _texto[j].setString(std::to_string(defensa));
            _texto[j].setPosition(314, 347);
        }
    }











    if (this->sfmlevent.key.code == sf::Keyboard::Key::Enter) {
        this->booltext = false;
        delete[] this->_texto;
        this->boolD = false;
        this->booleanodedanios = false;
        //this->_jugador.resetframe();
        this->opc = OPCIONES::vacio;
        this->sfmlevent.key.code = sf::Keyboard::Key::Pause;
        this->est = Estadogame::resultadoAenemigo;

    }
}

void Gameplay::enemigoatacar()
{
    ataqueenem();

}
void Gameplay::resultadoataqueenemigo() {
    this->booltext = true;
    this->canttext = 8;
    this->_texto = new sf::Text[canttext];

    for (int i = 0;i < 1;i++) {
        initfuente(i);
        _texto[i].setString("PRESIONE ENTER");
        _texto[i].setCharacterSize(25);
        _texto[i].setPosition(330, 500);
    }
    if (rand() % 2) {
        _texto[0].setString("         ");
    }

    int ataque = this->D + this->_enemigo[this->ronda].get_boniFuerza();
    int defensa = this->_jugador.get_resis() + this->_jugador.get_armazon().get_boniResis();

    // ATAQUE PIFIADO ENEMIGOS
    if (this->D == 1 || ataque<defensa) {
        ataquefallidosegunpartida();

    }
    //ATAQUE CRITICO ENEMIGOS
    if (this->D == 20) {

        ataquecriticosegunpartida();
        if (this->boolD == false) {
            this->D2 = (rand() % this->_enemigo[this->ronda].get_armamento().get_dado()) + 1;
            this->D3 = (rand() % this->_enemigo[this->ronda].get_armamento().get_dado()) + 1;
            this->boolD = true;
        }

        int danio1 = this->_enemigo[this->ronda].get_armamento().get_boniDanio() + this->D2;
        int danio2 = this->_enemigo[this->ronda].get_armamento().get_boniDanio() + this->D3;
        int daniofinal = danio1 + danio2;


        //primer dado ENEMIGOS
        for (int j = 1;j < 4;j++) {
            initfuente(j);
            _texto[j].setOutlineColor(sf::Color::White);

            if (j == 1) {
                _texto[j].setString(std::to_string(this->D2));
                _texto[j].setPosition(365, 148);
            }
            if (j == 2) {
                _texto[j].setString(std::to_string(this->_enemigo[this->ronda].get_armamento().get_boniDanio()));
                _texto[j].setPosition(410, 170);
            }
            if (j == 3) {
                _texto[j].setString(std::to_string(danio1));
                _texto[j].setPosition(330, 198);


            }
        }
        //segundo dado ENEMIGOS
        for (int j = 4;j < this->canttext; j++) {
            initfuente(j);
            _texto[j].setOutlineColor(sf::Color::White);
            if (j == 4) {
                _texto[j].setString(std::to_string(this->D3));
                _texto[j].setPosition(365, 248);
            }
            if (j == 5) {
                _texto[j].setString(std::to_string(this->_enemigo[this->ronda].get_armamento().get_boniDanio()));
                _texto[j].setPosition(410, 270);
            }
            if (j == 6) {
                _texto[j].setString(std::to_string(danio2));
                _texto[j].setPosition(330, 298);
            }
            if (j == 7) {
                _texto[j].setString(std::to_string(daniofinal));
                _texto[j].setPosition(369, 348);
            }
        }
        //recibe daño el jugador osea brian
        if (this->booleanodedanios == false) {
            this->_jugador.recibirDanio(daniofinal);
        }


    }


    // ATAQUE EXITOSO ENEMIGOS
    if (this->D != 20 && this->D != 1 && ataque >= defensa) {
        ataqueexitososegunpartida();

        int danio = this->_enemigo[this->ronda].get_armamento().get_boniDanio() + this->D;

        for (int j = 1;j < this->canttext;j++) {
            initfuente(j);
            _texto[j].setOutlineColor(sf::Color::White);

            if (j == 1) {
                _texto[j].setString(std::to_string(this->D));
                _texto[j].setPosition(365, 148);
            }
            if (j == 2) {
                _texto[j].setString(std::to_string(this->_enemigo[this->ronda].get_armamento().get_boniDanio()));
                _texto[j].setPosition(410, 170);
            }
            if (j == 3) {
                _texto[j].setString(std::to_string(danio));
                _texto[j].setPosition(330, 198);
            }
            if (j == 4) { _texto[j].setString("    "); }
            if (j == 5) { _texto[j].setString("    "); }
            if (j == 6) { _texto[j].setString("    "); }
            if (j == 7) { _texto[j].setString("    "); }
        }
        if (this->booleanodedanios == false) {
            this->_jugador.recibirDanio(danio);
        }
    }

    this->booleanodedanios = true;



    if (this->sfmlevent.key.code == sf::Keyboard::Key::Enter) {
        this->booltext = false;
        delete[] this->_texto;
        this->boolD = false;
        this->booleanodedanios = false;
        this->D = 0;
        this->D2 = 0;
        this->D3 = 0;
        this->opc = OPCIONES::vacio;
        this->sfmlevent.key.code = sf::Keyboard::Key::Comma;
        this->est = Estadogame::menubatalla;
    }


}

void Gameplay::enemigocurar()
{
    std::cout << "curar\n";
}

void Gameplay::danioaenemigos(int R, int danio)
{
    if (R == 0) {
        this->_enemigo[0].hacerledanio(danio);
    }
    if (R == 1) {
        this->_enemigo[1].hacerledanio(danio);
    }
    if (R == 2) {
        this->_enemigo[2].hacerledanio(danio);
    }
}

void Gameplay::crearArchivogameplay()
{
    FILE* p;
    p = fopen("gameplay.bkp", "wb");
    if (p == NULL) { std::cout << " ERROR::crearArchivogameplay::gameplay.bkp \n";system("pause"); }
    fclose(p);

}

void Gameplay::guardarPartidagameplay()
{
    FILE* p;
    p = fopen("gameplay.kbp", "ab");
    if (p == NULL) { std::cout << " ERROR::guardarPartidagameplay::gameplay.bkp \n";system("pause"); }
    //ronda
    fwrite(&ronda, sizeof(ronda), 1, p);
    fclose(p);

}
void Gameplay::leerpartidaguardada() {
  /*  FILE* p;
    p = fopen("gameplay.kbp", "rb");
    if (p == NULL) { std::cout << " ERROR::leerpartidaguardada::gameplay.bkp \n";system("pause"); }
    fclose(p);*/

}



