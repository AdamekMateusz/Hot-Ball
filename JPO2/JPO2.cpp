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
#include "Options.h"
#include "Finisher.h"
#include <vector>
#include <string> 
#include "Music_choise_menu.h"
#include "End_menu.h"
#include "Color_Menu.h"



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
    else {
        
        
        player.destroy();
        return true;
    }
        
    
}


bool collisionTest(Pionek& player, Meta& meta) {

    if (!isIntersecting(player, meta)) {
        return false;
    }
    else {
        
        player.destroy();
       return true;
    }
        

}

std::vector<std::string> utwory{
    "podklad.wav",
    "My_Doorbell.wav",
    "Hardest_Button.wav"
};
std::string a = utwory[0];






int main()
{   
    int check = 0;
    bool end{ false };
    /*
    std::vector<sf::Color> choose_Col{
        sf::Color::Red,
        sf::Color::Yellow,
        sf::Color::Green
    };
    */
    /* Wektor wypelniamy w nasepujacy sposob  latwy [kulka_ruch_poziomo]
                                                    [kulka_ruch_pionowo]
                                                    [kulka_ruch_wszedzie]
    */


    std::vector<std::vector<int>> level_easy = { {3,0},
                                                 {0,3},
                                                 {3,3}
    };

    std::vector<std::vector<int>> level_medium = { {6,0},
                                                   {0,6},
                                                   {6,6}
    };

    std::vector<std::vector<int>> level_hard = { {9,0},
                                                 {0,9},
                                                 {9,9}
    };


    sf::Music music;
    if (!music.openFromFile(a)) {

        std::cout << "ERROR\n";

    }
    music.play();
    
    
    /*
    sf::SoundBuffer soundbuffer;
    sf::Sound sound;

    if (!soundbuffer.loadFromFile("test.ogg"))
        std::cout << "can't find\n";
    sound.setBuffer(soundbuffer);
    sound.play();
    */
    Meta meta(380, 10);
   // Ball ball(400,300,3.0,3.0); //podajemy paramtery gdzie ma byc stworzona kulka
    Ball ball(20, 20, level_medium[2][0], level_medium[2][1]); //wszedzie
    Ball ball2(20, 20, level_medium[1][0], level_medium[1][1]); //pionowo
    Ball ball3(20, 20, level_medium[0][0], level_medium[0][1]);  //poziomo

    Ball ball4(300, 300, level_medium[2][0], level_medium[2][1]); //wszedzie
    Ball ball5(200, 200, level_medium[1][0], level_medium[1][1]); //pionowo
    Ball ball6(500, 500, level_medium[0][0], level_medium[0][1]);  //poziomo
    
   //sf::Color my_color_player = choose_Col[0];

    Pionek player(380,560, 40, 40, 6, sf::Color:: Red);
    //Pionek player(476, 321,40,40,6,sf::Color::Red);
    //tworzymy okno i tworzymy jego nazwe i tytul 

    sf::RenderWindow window(sf::VideoMode{ 800,600 }, "Simple Game");

    Menu menu(window.getSize().x, window.getSize().y);
    Options options(window.getSize().x, window.getSize().y);
    Finisher finish(window.getSize().x, window.getSize().y);
    Music_choise_menu music_choise(window.getSize().x, window.getSize().y);
    Color_Menu color(window.getSize().x, window.getSize().y);
    End_menu the_end2(window.getSize().x, window.getSize().y);
    
    //czestotliwosc odswierzania
    window.setFramerateLimit(60);

    //tworzymy obiekt typu event, bedzie odpowiedzilany za interakcje miedzy uzywkonikiem a programem
    sf::Event event;
    //options.draw(window);
    
    while (true) {
        //czyscimy wszystko
        window.clear(sf::Color::Black);
        
        //mozna rozszerzac i minimalizowac okno
        if (check==0) {
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
                            check = 1;
                           
                            break;
                        case 1:
                            check = 2;
                            window.clear(sf::Color::Black);
                            
                            std::cout << "Options button has been pressed\n";
                            //menu.close(window);

                            break;
                        case 2:
                            window.close();
                            exit(0);
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
       

        
       
        
        if(check==1){
           // if (k == 0) {
           //     Pionek player(580, 380, 40, 40, 6, my_color_player);
           //     k++;
           // }
           // else {

                ball.update();
                ball2.update();
                ball3.update();
                ball4.update();
                ball5.update();
                ball6.update();
                player.update();

                window.draw(meta);
                window.draw(ball);  //kulka zostanie wyswietlona na ekranie
                window.draw(ball2);
                window.draw(ball3);
                window.draw(ball4);  //kulka zostanie wyswietlona na ekranie
                window.draw(ball5);
                window.draw(ball6);
                window.draw(player);

                //wyswietlimy wszyskie elementy


                //tutaj zamykamy nasza gre
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
                    exit(0);
                }

                if (collisionTest(player, ball)) {
                    //End_menu the_end(window.getSize().x, window.getSize().y, false);
                    //window.draw(the_end);
                   // player.destroy();
                    the_end2.set_finish(false);
                    check = 8;
                   // end = false;
                    std::cout << "ball\n";
                   

                }
                if (collisionTest(player, ball2)) {
                    //End_menu the_end1(window.getSize().x, window.getSize().y, false);
                   // window.draw(the_end1);
                    //player.destroy();
                    the_end2.set_finish(false);
                    check = 8;
                    //end = false;
                    std::cout << "udalo ball2\n";
                    
                }

                if (collisionTest(player, ball3)) {
                    // End_menu the_end2(window.getSize().x, window.getSize().y, false);
                    //window.draw(the_end2);
                    // player.destroy();
                    the_end2.set_finish(false);
                    check = 8;
                    std::cout << "udalo sie\n";
                    //end = false;
                    
                }


                if (collisionTest(player, ball4)) {
                    //End_menu the_end(window.getSize().x, window.getSize().y, false);
                    //window.draw(the_end);
                   // player.destroy();
                    the_end2.set_finish(false);
                    check = 8;
                    // end = false;
                    std::cout << "ball\n";


                }
                if (collisionTest(player, ball5)) {
                    //End_menu the_end1(window.getSize().x, window.getSize().y, false);
                   // window.draw(the_end1);
                    //player.destroy();
                    the_end2.set_finish(false);
                    check = 8;
                    //end = false;
                    std::cout << "udalo ball2\n";

                }

                if (collisionTest(player, ball6)) {
                    // End_menu the_end2(window.getSize().x, window.getSize().y, false);
                    //window.draw(the_end2);
                    // player.destroy();
                    the_end2.set_finish(false);
                    check = 8;
                    std::cout << "udalo sie\n";
                    //end = false;

                }


                if (collisionTest(player, meta)) {

                    //End_menu the_end3(window.getSize().x, window.getSize().y, true);
                     //window.draw(the_end3);
                     //meta.destroy();
                    check = 8;
                    //end = true;
                    std::cout << "meta\n";
                    the_end2.set_finish(true);
                }
                /*
                if (player.isDestroyed==true) {
                    End_menu the_end1(window.getSize().x, window.getSize().y, false);
                    window.draw(the_end1);
                }*/
                /*
                if (meta.isDestroyed()==true) {
                    End_menu the_end(window.getSize().x, window.getSize().y, true);
                    window.draw(the_end);
                }
                */
           // }
        }
       
        if (check == 2) {
            
            window.draw(options);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
                exit(0);
            }
            while (window.pollEvent(event))
            {

                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                    case sf::Keyboard::Up:
                        options.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        options.MoveDown();
                        break;

                    case sf::Keyboard::Enter:
                        switch (options.GetPressedItem())
                        {
                        case 0:
                            std::cout << "Poziom Trundosci\n";
                            check = 4;

                            break;
                        case 1:
                            
                            //window.clear(sf::Color::Black);

                            std::cout << "Muzyka\n";
                            //menu.close(window);
                           /* music.stop();
                            a = utwory[1];
                            if (!music.openFromFile(a)) {

                                std::cout << "ERROR\n";

                            }
                            music.play();
                            */
                            check = 5;

                            break;
                        case 2:
                            std::cout << "kolor obiektow\n";
                            check = 6;
                            break;

                        case 3:
                            std::cout << "wstecz\n";
                            check = 0;
                            break;

                        case 4:
                            std::cout << "exit\n";
                            window.close();
                            exit(0);
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


        if (check == 4) {
            window.draw(finish);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
                exit(0);
            }
            while (window.pollEvent(event))
            {

                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                    case sf::Keyboard::Left:
                        finish.MoveLeft();
                        break;
                    case sf::Keyboard::Right:
                        finish.MoveRight();
                        break;

                    case sf::Keyboard::Enter:
                        switch (finish.GetPressedItem())
                        {
                        case 0:
                            std::cout << "Latwy\n";
                            ball.change_level(level_easy[2][0], level_easy[2][1]);
                            ball2.change_level(level_easy[1][0],level_easy[1][1]);
                            ball3.change_level(level_easy[0][0],level_easy[0][1]);
                            ball4.change_level(level_easy[2][0], level_easy[2][1]);
                            ball5.change_level(level_easy[1][0], level_easy[1][1]);
                            ball6.change_level(level_easy[0][0], level_easy[0][1]);

                            break;
                        case 1:

                            

                            std::cout << "Sredni\n";
                            ball.change_level(level_medium[2][0], level_medium[2][1]);
                            ball2.change_level(level_medium[1][0], level_medium[1][1]);
                            ball3.change_level(level_medium[0][0], level_medium[0][1]);
                            ball4.change_level(level_medium[2][0], level_medium[2][1]);
                            ball5.change_level(level_medium[1][0], level_medium[1][1]);
                            ball6.change_level(level_medium[0][0], level_medium[0][1]);
                            

                            break;
                        case 2:
                            std::cout << "Trudny\n";
                            ball.change_level(level_hard[2][0], level_hard[2][1]);
                            ball2.change_level(level_hard[1][0], level_hard[1][1]);
                            ball3.change_level(level_hard[0][0], level_hard[0][1]);
                            ball4.change_level(level_hard[2][0], level_hard[2][1]);
                            ball5.change_level(level_hard[1][0], level_hard[1][1]);
                            ball6.change_level(level_hard[0][0], level_hard[0][1]);
                            break;

                        case 3:
                            std::cout << "Wstecz\n";
                            check = 2;
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


        if (check == 5)
        {
            window.draw(music_choise);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
                exit(0);
            }
            while (window.pollEvent(event))
            {

                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                    case sf::Keyboard::Up:
                        music_choise.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        music_choise.MoveDown();
                        break;

                    case sf::Keyboard::Enter:
                        switch (music_choise.GetPressedItem())
                        {
                        case 0:
                            std::cout << "Podklad\n";
                            music.stop();
                            a = utwory[0];
                            if (!music.openFromFile(a)) {

                                std::cout << "ERROR\n";

                            }
                            music.play();
                            


                            break;
                        case 1:

                            //window.clear(sf::Color::Black);

                            std::cout << "My_Doorbell\n";
                            music.stop();
                            a = utwory[1];
                            if (!music.openFromFile(a)) {

                                std::cout << "ERROR\n";

                            }
                            music.play();

                            break;
                        case 2:
                            std::cout << "Hardest_Button\n";
                            music.stop();
                            a = utwory[2];
                            if (!music.openFromFile(a)) {

                                std::cout << "ERROR\n";

                            }
                            music.play();

                            break;

                        case 3:
                            std::cout << "Wstecz\n";
                            check = 2;
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

        /*
        if (check == 7) {
            End_menu the_end1(window.getSize().x, window.getSize().y, false);
            window.draw(the_end1);
        }
        */
        if (check == 6) {
            window.draw(color);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
                exit(0);
            }
            while (window.pollEvent(event))
            {

                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                    case sf::Keyboard::Left:
                        color.MoveLeft();
                        break;
                    case sf::Keyboard::Right:
                        color.MoveRight();
                        break;

                    case sf::Keyboard::Enter:
                        switch (color.GetPressedItem())
                        {
                        case 0:
                            std::cout << "Blue\n";
                            //player.change_color(choose_Col[0]);
                            player.change_color(sf::Color::Blue);

                            break;
                        case 1:

                            //window.clear(sf::Color::Black);

                            std::cout << "Yellow\n";
                            //menu.close(window);
                            //my_color_player = choose_Col[1];
                            player.change_color(sf::Color::Yellow);
                            

                            break;
                        case 2:
                            std::cout << "Green\n";
                            player.change_color(sf::Color::Green);
                            
                            break;

                        case 3:
                            std::cout << "Wstecz\n";
                            check = 2;
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


        if (check == 8) {
            //End_menu the_end2(window.getSize().x, window.getSize().y, end);
            window.draw(the_end2);
            player.position();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
                exit(0);
            }
            while (window.pollEvent(event))
            {

                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                    case sf::Keyboard::Left:
                        the_end2.MoveLeft();
                        break;
                    case sf::Keyboard::Right:
                        the_end2.MoveRight();
                        break;

                    case sf::Keyboard::Enter:
                        switch (the_end2.GetPressedItem())
                        {
                        case 1:
                            std::cout << "Main Menu\n";
                            check = 0;

                            break;
                        case 2:


                            window.close();
                            exit(0);
                            std::cout << "Exit\n";
                            ;


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
        

           
          
           
        //sprawdzamy czy X do zamkniecia zostal klikniety, po tym bedziemy destroy okno
        
            window.display();
    }

}

