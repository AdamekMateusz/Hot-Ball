/* Przedmiot: Jezyki Programowania Obiektowego
  Project: "Simple Game"
  Author: Mateusz Adamek
  mail: madamek@student.agh.edu.pl
  Index: 305117
*/

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


//Create template function to check for a collision object

template <class T1, class T2> bool isIntersecting(T1& A, T2& B) {

    return A.right() >= B.left() && A.left() <= B.right()
        && A.bottom() >= B.top() && A.top() <= B.bottom();
}

//return true if two or more object are interecting
bool collisionTest(Pionek& player, Ball& ball2) {

    if (!isIntersecting(player, ball2)) {
        return false;
    }
    else {
        
        
        player.destroy();
        return true;
    }
        
    
}

//return true if two or more object are intersecting
bool collisionTest(Pionek& player, Meta& meta) {

    if (!isIntersecting(player, meta)) {
        return false;
    }
    else {
        
        player.destroy();
       return true;
    }
        

}
//create wector which include the name of songs
std::vector<std::string> utwory{
    "podklad.wav",
    "My_Doorbell.wav",
    "Hardest_Button.wav"
};
//set a deafult song, song for posiotion 0 in vectot 'utwory'
std::string a = utwory[0];






int main()
{   
    int check = 0;
    //bool end{ false };

    //Create the level of our game
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
    
    //load our music
    sf::Music music;
    if (!music.openFromFile(a)) {

        std::cout << "ERROR\n";

    }
    music.play();
    
    
   //Create the objectsand set paramiters like start position , and start level
    Meta meta(380, 10);
    //In tthe last paramters set the level and move direction
    Ball ball(20, 20, level_medium[2][0], level_medium[2][1]); //everywhere
    Ball ball2(20, 20, level_medium[1][0], level_medium[1][1]); //vertical
    Ball ball3(20, 20, level_medium[0][0], level_medium[0][1]);  //horizontal

    Ball ball4(300, 300, level_medium[2][0], level_medium[2][1]); //everywhere
    Ball ball5(200, 200, level_medium[1][0], level_medium[1][1]); //vertical
    Ball ball6(500, 500, level_medium[0][0], level_medium[0][1]);  //horizontal
    

    Pionek player(380,560, 40, 40, 6, sf::Color:: Red);

    //Createthe main window, set the size of window, set the title

    sf::RenderWindow window(sf::VideoMode{ 800,600 }, "Simple Game");
    //Create other window which will be display i  our application

    Menu menu(window.getSize().x, window.getSize().y);
    Options options(window.getSize().x, window.getSize().y);
    Finisher finish(window.getSize().x, window.getSize().y);
    Music_choise_menu music_choise(window.getSize().x, window.getSize().y);
    Color_Menu color(window.getSize().x, window.getSize().y);
    End_menu the_end2(window.getSize().x, window.getSize().y);
    
    //Set frame limit 
    window.setFramerateLimit(60);

    //create the object which will be resposible for action between game and user
    sf::Event event;
    
    
    while (true) {
        //clear all
        window.clear(sf::Color::Black);
        
        //MAIN MENU
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
                            std::cout << "PLAY\n";
                            check = 1;
                           
                            break;
                        case 1:
                            check = 2;
                            window.clear(sf::Color::Black);
                            
                            std::cout << "OPTIONS\n";
                            //menu.close(window);

                            break;
                        case 2:
                            window.close();
                            exit(0);
                            break;

                        }

                    }
                    break;
                }  
            }
        }
       

        
       
        //GAME
        if(check==1){
         
                ball.update();
                ball2.update();
                ball3.update();
                ball4.update();
                ball5.update();
                ball6.update();
                player.update();

                //ALL elements will be drawn
                window.draw(meta);
                window.draw(ball);  
                window.draw(ball2);
                window.draw(ball3);
                window.draw(ball4); 
                window.draw(ball5);
                window.draw(ball6);
                window.draw(player);

               


                //if press ESC game will be closed.
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                    exit(0);
                }

                if (collisionTest(player, ball)) {
                    the_end2.set_finish(false);
                    check = 8;
                }
                if (collisionTest(player, ball2)) {
                    the_end2.set_finish(false);
                    check = 8;   
                }

                if (collisionTest(player, ball3)) {
                    the_end2.set_finish(false);
                    check = 8;
                }


                if (collisionTest(player, ball4)) {
                    the_end2.set_finish(false);
                    check = 8;
                }
                if (collisionTest(player, ball5)) {
                    the_end2.set_finish(false);
                    check = 8;
                }

                if (collisionTest(player, ball6)) {
                    the_end2.set_finish(false);
                    check = 8;
                }


                if (collisionTest(player, meta)) {
                    check = 8;
                    the_end2.set_finish(true);
                }
        }
      
        //OPTIONS MENU
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
                            std::cout << "DIFFICULT LEVEL\n";
                            check = 4;

                            break;
                        case 1:
                            std::cout << "MUSIC\n";
                            check = 5;
                            break;
                        case 2:
                            std::cout << "PLAYER COLOR\n";
                            check = 6;
                            break;

                        case 3:
                            std::cout << "BACK\n";
                            check = 0;
                            break;

                        case 4:
                            std::cout << "EXIT\n";
                            window.close();
                            exit(0);
                            break;
                        }
                    }
                    break;
                }
            }
        }

        //DISPLAY LEVEL SET MENU
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
                            std::cout << "EASY\n";
                            //Set the dificult level as easy
                            ball.change_level(level_easy[2][0], level_easy[2][1]);
                            ball2.change_level(level_easy[1][0],level_easy[1][1]);
                            ball3.change_level(level_easy[0][0],level_easy[0][1]);
                            ball4.change_level(level_easy[2][0], level_easy[2][1]);
                            ball5.change_level(level_easy[1][0], level_easy[1][1]);
                            ball6.change_level(level_easy[0][0], level_easy[0][1]);

                            break;
                        case 1:

                            

                            std::cout << "MEDIUM\n";
                            //set the dificult level as MEDIUM
                            ball.change_level(level_medium[2][0], level_medium[2][1]);
                            ball2.change_level(level_medium[1][0], level_medium[1][1]);
                            ball3.change_level(level_medium[0][0], level_medium[0][1]);
                            ball4.change_level(level_medium[2][0], level_medium[2][1]);
                            ball5.change_level(level_medium[1][0], level_medium[1][1]);
                            ball6.change_level(level_medium[0][0], level_medium[0][1]);
                            

                            break;
                        case 2:
                            std::cout << "HARD\n";
                            //Set the difficult level as EASY
                            ball.change_level(level_hard[2][0], level_hard[2][1]);
                            ball2.change_level(level_hard[1][0], level_hard[1][1]);
                            ball3.change_level(level_hard[0][0], level_hard[0][1]);
                            ball4.change_level(level_hard[2][0], level_hard[2][1]);
                            ball5.change_level(level_hard[1][0], level_hard[1][1]);
                            ball6.change_level(level_hard[0][0], level_hard[0][1]);
                            break;

                        case 3:
                            std::cout << "BACK\n";
                            check = 2;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        //DISPLAY MUSIC SET MENU
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
                            std::cout << "BACK\n";
                            check = 2;
                            break;
                        }
                    }
                    break;
                }
            }
        }

       //DISPLAY COLOR SET MENU
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
                            player.change_color(sf::Color::Blue);

                            break;
                        case 1:
                            std::cout << "Yellow\n";
                            player.change_color(sf::Color::Yellow);
                            

                            break;
                        case 2:
                            std::cout << "Green\n";
                            player.change_color(sf::Color::Green);
                            
                            break;

                        case 3:
                            std::cout << "BACK\n";
                            check = 2;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        //Here will be dipslay our END MENU
        if (check == 8) {
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
                }
            }
        }
        
            window.display();
    }

}

