#include "funciones.h"

/*

void mainupdate(OPCIONES *opc, sf::RenderWindow* window, AVENTURA *aventura)
{
    Gameplay e;
    Escenario fondo;
    sf::Event teclado;
    window->pollEvent(teclado);
    texto menupartida[7], mpartida[6];

    texto menusalida[3], l2historia[10], mhistoria[16];
    sf::Mutex mutex;
    int opcion = 15;
    int tiempo = 60;

    for (int i = 0;i < 14;i++) {
        mhistoria[i].cambiotamaño(18);
    }



    switch (*opc)
    {
    case OPCIONES::uno:
        e.modoAventura(window,opc);

        break;

    case OPCIONES::dos:

        historia(window, opc);
        break;

    case OPCIONES::tres:

        e.reparto(window);
        *opc = OPCIONES::vacio;
        break;

    case OPCIONES::cuatro:

        //instrucciones();
        *opc = OPCIONES::vacio;
        break;

    case OPCIONES::cinco:
        //partidasGuardadas();
        *opc = OPCIONES::vacio;
        break;

    case OPCIONES::cero:

        menusalida[0].nuevotexto("SEGURO QUE DESEA SALIR?");
        menusalida[0].posicion(345, 100 + 15);
        menusalida[2].nuevotexto("S - SI");
        menusalida[1].posicion(280, 100 + 55);
        menusalida[1].nuevotexto("N - NO");
        menusalida[2].posicion(280, 100 + 70);

        window->clear();
        window->draw(menusalida[0]);
        window->draw(menusalida[1]);
        window->draw(menusalida[2]);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) { *opc = OPCIONES::vacio; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) { *opc = OPCIONES::fin; }


        break;
    case OPCIONES::fin:

        window->close();




        break;


    case OPCIONES::lectura:
        mutex.lock();
        mutex.unlock();
        fondo.cambiomenu00();
        mhistoria[0].nuevotexto("PAGINA 1 de 6");
        mhistoria[0].posicion(300, 100);
        mhistoria[0].cambiotamaño(25);

        mhistoria[1].nuevotexto("___________________________________________________________________");
        mhistoria[1].posicion(0, 135);
        mhistoria[2].nuevotexto("La historia de Arcano se centra en el surgimiento de un Rex de Caelo,");
        mhistoria[2].posicion(20, 170 + 5);
        mhistoria[3].nuevotexto("rey de los cielos, quienes controlan y velan por el destino del mundo.");
        mhistoria[3].posicion(20, 170 + 40);
        mhistoria[4].nuevotexto("Rigieron y guiaron sobre el resto del planeta como la voz del mundo,");
        mhistoria[4].posicion(20, 170 + 70);
        mhistoria[5].nuevotexto("la influencia principal por los siglos de los siglos.");
        mhistoria[5].posicion(20, 170 + 100);
        mhistoria[6].nuevotexto("___________________________________________________________________");
        mhistoria[6].posicion(0, 190 + 110);

        mhistoria[7].nuevotexto("PRESIONE ENTER");
        mhistoria[7].cambiotamaño(25);
        mhistoria[7].posicion(300, 500);

        // PRESIONE ENTER TITILANDO
        srand(time(NULL));
        if (rand() % 2) {
            mhistoria[7].cambiotexto("    ");
        }

        //DIBUJO
        window->clear();
        window->draw(fondo);

        for (int i = 0;i < 8;i++) {
            window->draw(mhistoria[i]);
        }


        // cambio de lectura

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            *opc = OPCIONES::lectura1;


        }


        break;
    case OPCIONES::lectura1:
        mutex.lock();
        mutex.unlock();
        window->clear();
        fondo.cambiomenu00();
        mhistoria[8].nuevotexto("PAGINA 2 de 6");
        mhistoria[8].posicion(300, 100);
        mhistoria[8].cambiotamaño(25);

        mhistoria[9].nuevotexto("___________________________________________________________________________________");
        mhistoria[9].posicion(0, 135);
        mhistoria[10].nuevotexto("El cometa Nibiru, se desplaza cerca de la orbita terrestre una vez cada");
        mhistoria[10].posicion(15, 170);
        mhistoria[11].nuevotexto("cien anios, anunciando asi el comienzo de un nuevo siglo.");
        mhistoria[11].posicion(15, 170 + 25);
        mhistoria[12].nuevotexto("La historia comienza en el siglo XIII, Nibiru desgarro el firmamento ");
        mhistoria[12].posicion(15, 170 + 50);
        mhistoria[13].nuevotexto("nocturno, la sangre de nuestro heroe empieza a hervir, su arma comienza a ");
        mhistoria[13].posicion(15, 170 + 75);
        mhistoria[14].nuevotexto("destellar y una voz en su cabeza lo guia hacia las coordenadas de un portal. ");
        mhistoria[14].posicion(15, 170 + 100);
        mhistoria[14].cambiotamaño(17);
        mhistoria[15].nuevotexto("___________________________________________________________________________________");
        mhistoria[15].posicion(0, 300);

        window->draw(fondo);
        mhistoria[7].nuevotexto("PRESIONE ENTER");
        mhistoria[7].cambiotamaño(25);
        mhistoria[7].posicion(300, 500);

        // PRESIONE ENTER TITILANDO
        srand(time(NULL));
        if (rand() % 2) {
            mhistoria[7].cambiotexto("    ");
        }


        for (int i = 7;i < 16;i++) {
            window->draw(mhistoria[i]);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            *opc = OPCIONES::lectura2;


        }


        break;

    case OPCIONES::lectura2:
        mutex.lock();
        mutex.unlock();
        window->clear();
        fondo.cambiomenu00();


        l2historia[0].nuevotexto("PAGINA 3 de 6");
        l2historia[0].posicion(300, 100);
        l2historia[0].cambiotamaño(25);
        l2historia[1].nuevotexto("___________________________________________________________________________________");
        l2historia[1].posicion(0, 135);
        l2historia[2].nuevotexto("Atravesandolo, una penumbra mental, la voz en su cabeza transmuta en una mas clara,");
        l2historia[2].posicion(15, 170);
        l2historia[2].cambiotamaño(15);
        l2historia[3].nuevotexto("clara como la voz de su abuelo el sabio cuando era pequenio.");
        l2historia[3].posicion(15, 170 + 25);
        l2historia[4].nuevotexto("Como un parpadeo, nuestro heroe Brian se despierta al borde de un acantilado,");
        l2historia[4].posicion(15, 170 + 50);
        l2historia[5].nuevotexto("con mucho calor y rodeado por una planicie inacabable de arena, por otro lado,");
        l2historia[5].posicion(15, 170 + 75);
        l2historia[6].nuevotexto("un abismo y nubes. Una isla flotante, era Arcano. ");
        l2historia[6].posicion(15, 170 + 100);

        l2historia[7].nuevotexto("___________________________________________________________________________________");
        l2historia[7].posicion(0, 300);


        l2historia[9].nuevotexto("PRESIONE ENTER");
        l2historia[9].cambiotamaño(25);
        l2historia[9].posicion(300, 500);

        // PRESIONE ENTER TITILANDO
        srand(time(NULL));
        if (rand() % 2) {
            l2historia[9].cambiotexto("    ");
        }

        //DIBUJO
        window->draw(fondo);
        for (int i = 0;i < 10;i++) {
            window->draw(l2historia[i]);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            *opc = OPCIONES::lectura3;



        }

        break;
    case OPCIONES::lectura3:

        mutex.lock();
        mutex.unlock();
        fondo.cambiomenu00();
        mhistoria[0].nuevotexto("PAGINA 4 de 6");
        mhistoria[0].posicion(300, 100);
        mhistoria[0].cambiotamaño(25);

        mhistoria[1].nuevotexto("___________________________________________________________________________________");
        mhistoria[1].posicion(0, 135);
        mhistoria[2].nuevotexto("Brian recuerda todos sus anios de esfuerzo, sudor y sangre para ");
        mhistoria[2].posicion(20, 160);
        mhistoria[3].nuevotexto("alcanzar sus metas. Las historias de su niniez, de 4 elegidos y un destino,");
        mhistoria[3].posicion(20, 160 + 25);
        mhistoria[4].nuevotexto("un desierto, una cueva oscura y unas montanias heladas.");
        mhistoria[4].posicion(20, 160 + 50);
        mhistoria[5].nuevotexto("En el horizonte del desierto, el reflejo del sol sobre la arena le ");
        mhistoria[5].posicion(20, 160 + 75);
        mhistoria[8].nuevotexto("quema los ojos, le obstruye la vista,con gran esfuerzo logra vislumbrar");
        mhistoria[8].posicion(20, 160 + 100);
        mhistoria[9].nuevotexto("una piramide con una entrada colosalmente grande. Sabe, que...");
        mhistoria[9].posicion(20, 160 + 125);
        mhistoria[6].nuevotexto("___________________________________________________________________________________");
        mhistoria[6].posicion(0, 300);

        mhistoria[7].nuevotexto("PRESIONE ENTER");
        mhistoria[7].cambiotamaño(25);
        mhistoria[7].posicion(300, 500);

        // PRESIONE ENTER TITILANDO
        srand(time(NULL));
        if (rand() % 2) {
            mhistoria[7].cambiotexto("    ");
        }

        //DIBUJO
        window->clear();
        window->draw(fondo);

        for (int i = 0;i < 10;i++) {
            window->draw(mhistoria[i]);
        }


        // cambio de lectura

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            *opc = OPCIONES::lectura4;


        }

        break;
    case OPCIONES::lectura4:
        mutex.lock();
        mutex.unlock();
        fondo.cambiomenu00();
        mhistoria[0].nuevotexto("PAGINA 5 de 6");
        mhistoria[0].posicion(300, 100);
        mhistoria[0].cambiotamaño(25);

        mhistoria[1].nuevotexto("___________________________________________________________________________________");
        mhistoria[1].posicion(0, 135);
        mhistoria[2].nuevotexto("peligros esperan a quien quiera escribir la historia. Y que, solo los ");
        mhistoria[2].posicion(20, 170);
        mhistoria[3].nuevotexto("ganadores son recordados.");
        mhistoria[3].posicion(20, 170 + 25);
        mhistoria[4].nuevotexto("Brian debera salir victorioso de 3 batallas contra los antagonistas. ");
        mhistoria[4].posicion(20, 170 + 50);
        mhistoria[5].nuevotexto("Cross, el reptiliano inmune, Azazel, el no-muerto letal y el implacable ");
        mhistoria[5].posicion(20, 170 + 75);
        mhistoria[8].nuevotexto("Thrall el orco.");
        mhistoria[8].posicion(20, 170 + 100);
        mhistoria[6].nuevotexto("___________________________________________________________________________________");
        mhistoria[6].posicion(0, 300);

         cout << "  "
        mhistoria[7].nuevotexto("PRESIONE ENTER");
        mhistoria[7].cambiotamaño(25);
        mhistoria[7].posicion(300, 500);

        // PRESIONE ENTER TITILANDO
        srand(time(NULL));
        if (rand() % 2) {
            mhistoria[7].cambiotexto("    ");
        }

        //DIBUJO
        window->clear();
        window->draw(fondo);

        for (int i = 0;i < 9;i++) {
            window->draw(mhistoria[i]);
        }


        // cambio de lectura

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            *opc = OPCIONES::lectura5;


        }

        break;

    case OPCIONES::lectura5:
        mutex.lock();
        mutex.unlock();
        fondo.cambiomenu00();
        mhistoria[0].nuevotexto("PAGINA 6 de 6");
        mhistoria[0].posicion(300, 100);
        mhistoria[0].cambiotamaño(25);

        mhistoria[1].nuevotexto("___________________________________________________________________________________");
        mhistoria[1].posicion(0, 135);
        mhistoria[2].nuevotexto("Para ser el, quien controle y vea por el destino del mundo, convencido ");
        mhistoria[2].posicion(20, 170 + 25);
        mhistoria[3].nuevotexto("que el poder corrompe y el poder absoluto corrompe absolutamente.");
        mhistoria[3].posicion(20, 170 + 50);
        mhistoria[4].nuevotexto("La prueba absoluta de su virtud, sera poseer un poder ilimitado sin abusar ");
        mhistoria[4].posicion(20, 170 + 75);
        mhistoria[5].nuevotexto("de el y convertirse en el proximo Rex de Caelo. ");
        mhistoria[5].posicion(20, 170 + 100);
        mhistoria[6].nuevotexto("___________________________________________________________________________________");
        mhistoria[6].posicion(0, 300);

         cout << "  "
        mhistoria[7].nuevotexto("PRESIONE ENTER");
        mhistoria[7].cambiotamaño(25);
        mhistoria[7].posicion(300, 500);

        // PRESIONE ENTER TITILANDO
        srand(time(NULL));
        if (rand() % 2) {
            mhistoria[7].cambiotexto("    ");
        }

        //DIBUJO
        window->clear();
        window->draw(fondo);

        for (int i = 0;i < 8;i++) {
            window->draw(mhistoria[i]);
        }


        // cambio de lectura

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            *opc = OPCIONES::vacio;


        }

        break;
    case OPCIONES::guardadonueva:
        window->clear();

        //MENU
        menupartida[0].nuevotexto("NUEVA PARTIDA O CONTINUAR UNA GUARDADA? ");
        menupartida[0].posicion(155, 100);
        menupartida[0].cambiotamaño(25);

        menupartida[1].nuevotexto("____________________________________________________________________________________");
        menupartida[1].posicion(0, 135);
        menupartida[2].nuevotexto("1 - CONTINUAR PARTIDA");
        menupartida[2].posicion(20, 170 + 5);
        menupartida[3].nuevotexto("2 - NUEVA PARTIDA");
        menupartida[3].posicion(20, 170 + 40);
        menupartida[4].nuevotexto("0 - SALIR");
        menupartida[4].posicion(20, 170 + 70);
        menupartida[5].nuevotexto("____________________________________________________________________________________");
        menupartida[5].posicion(0, 170 + 100);

        menupartida[6].nuevotexto("OPCION");
        menupartida[6].cambiotamaño(25);
        menupartida[6].posicion(300, 500);

        // OPCION TITILANDO
        srand(time(NULL));
        if (rand() % 2) {
            menupartida[6].cambiotexto("    ");
        }

        window->clear();
        for (int j = 0;j < 7;j++) {
            window->draw(menupartida[j]);
        }
        if (teclado.type == sf::Event::KeyPressed) {
            if (teclado.key.code == sf::Keyboard::Num1) { opcion = 1; }
            if (teclado.key.code == sf::Keyboard::Num0) { opcion = 0; }
            if (teclado.key.code == sf::Keyboard::Num2) { opcion = 2; }

        }
        // CONTINUAR PARTIDA
        if (opcion == 1) {}
        // NUEVA PARTIDA
        if(opcion == 2)
        // SALIR
        if (opcion == 0) {
                *opc = OPCIONES::guardadonueva2;}
        }




        break;

    case OPCIONES::guardadonueva2:
        window->clear();



        mpartida[0].nuevotexto("SEGURO QUE DESEA SALIR? ");
        mpartida[0].posicion(210, 100);
        mpartida[0].cambiotamaño(25);

        mpartida[1].nuevotexto("____________________________________________________________________________________");
        mpartida[1].posicion(0, 135);
        mpartida[2].nuevotexto("N - NO");
        mpartida[2].posicion(20, 170 + 5);
        mpartida[3].nuevotexto("S - SI");
        mpartida[3].posicion(20, 170 + 40);
        mpartida[4].nuevotexto("____________________________________________________________________________________");
        mpartida[4].posicion(0, 170 + 100);
        mpartida[5].nuevotexto("OPCION");
        mpartida[5].cambiotamaño(25);
        mpartida[5].posicion(300, 500);

        // OPCION TITILANDO
        srand(time(NULL));
        if (rand() % 2) {
            mpartida[5].cambiotexto("    ");
        }
        for (int j = 0;j < 6;j++) {
            window->draw(mpartida[j]);
        }

        if (teclado.type == sf::Event::KeyPressed) {
            if (teclado.key.code == sf::Keyboard::S) { *opc = OPCIONES::vacio; }
            if (teclado.key.code == sf::Keyboard::N) { *opc = OPCIONES::vacio; }
        }

        break;

    }//fin del switch opc
}   //fin




*/
