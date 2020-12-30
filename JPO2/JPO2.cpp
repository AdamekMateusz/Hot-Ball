// JPO2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Pionek.h"
#include "Meta.h"
#include "Menu.h"

//funkcja z dwoma parametrami szablonowymi dla dowolnych typow obiketow
template <class T1, class T2> bool isIntersecting(T1& A, T2& B) {
    //tutaj sprawdzamy czy jakos obikety sie na sobie nachodza
    return A.right() >= B.left() && A.left() <= B.right()
        && A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTest(Pionek& player, Ball& ball2) {

    if (!isIntersecting(player, ball2)) {
        return false;
    }
    else
        player.destroy();
    
}


bool collisionTest(Pionek& player, Meta& meta) {

    if (!isIntersecting(player, meta)) {
        return false;
    }
    else
        player.destroy();

}


int main()
{   
    /*
    sf::Music music;
    if (!music.openFromFile("podklad.wav")) {

        std::cout << "ERROR\n";

    }
    music.play();
    */
    /*
    sf::SoundBuffer soundbuffer;
    sf::Sound sound;

    if (!soundbuffer.loadFromFile("test.ogg"))
        std::cout << "can't find\n";
    sound.setBuffer(soundbuffer);
    sound.play();
    */
    Meta meta(380, 10);
    Ball ball(400,300,3.0,3.0); //podajemy paramtery gdzie ma byc stworzona kulka
    Ball ball2(20, 580, 0.0, 3.0);
    Ball ball3(20, 20, 5.0, 0.0);
    
    

    Pionek player(580, 380,40,40);
    //tworzymy okno i tworzymy jego nazwe i tytul 
    sf::RenderWindow window(sf::VideoMode{ 800,600 }, "Simple Game");

    Menu menu(window.getSize().x, window.getSize().y);
    //czestotliwosc odswierzania
    window.setFramerateLimit(60);

    //tworzymy obiekt typu event, bedzie odpowiedzilany za interakcje miedzy uzywkonikiem a programem
    sf::Event event;
   
    bool check = true;
    while (true) {
        //czyscimy wszystko
        window.clear(sf::Color::Black);
        
        //mozna rozszerzac i minimalizowac okno
        if (check) {
            menu.draw(window);
            while (window.pollEvent(event))
            {

                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;

                    case sf::Keyboard::Enter:
                        switch (menu.GetPressedItem())
                        {
                        case 0:
                            std::cout << "Play button has been pressed\n";
                            check = false;
                           
                            break;
                        case 1:
                            std::cout << "Options button has been pressed\n";
                            break;
                        case 2:
                            window.close();
                            break;

                        }

                    }
                    break;
                //case sf::Event::Closed:
                  //  window.close();
                   // break;

                }


                
            }
        }
       

        
       
        
        else {
            ball.update();
            ball2.update();
            ball3.update();
            player.update();

            window.draw(meta);
            window.draw(ball);  //kulka zostanie wyswietlona na ekranie
            window.draw(ball2);
            window.draw(ball3);
            window.draw(player);

            //wyswietlimy wszyskie elementy


            //tutaj zamykamy nasza gre
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
                exit(0);
            }

            if (collisionTest(player, ball));
            if (collisionTest(player, ball2));
            if (collisionTest(player, ball3));
            if (collisionTest(player, meta));
        }
       
            
          
           
        //sprawdzamy czy X do zamkniecia zostal klikniety, po tym bedziemy destroy okno
        if (event.type == sf::Event::Closed) {
            window.close();
            break;

        }
            window.display();
    }

}

