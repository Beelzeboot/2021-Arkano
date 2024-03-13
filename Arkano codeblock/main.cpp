
#include <SFML/Graphics.hpp>

#include <iostream>
#include "gameplay.h"


int main()
{
    //opciones

    //Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    //Initialize game object
    Gameplay game;

    //Game loop
    while (game.running())
    {

        game.update();
        game.render();

    }
    //End of application
    return 0;

}
