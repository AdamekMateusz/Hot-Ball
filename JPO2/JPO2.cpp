/* Przedmiot: Jezyki Programowania Obiektowego
  Project: "Simple Game"
  Author: Mateusz Adamek
  mail: madamek@student.agh.edu.pl
  Index: 305117
*/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Pawn.h"
#include "Meta.h"
#include "Menu.h"
#include "Options.h"
#include "Level_menu.h"
#include <vector>
#include <string> 
#include "Music_choise_menu.h"
#include "End_menu.h"
#include "Color_Menu.h"
#include "Action.h"

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


    Pawn player(380,560, 40, 40, 6, sf::Color:: Red);

    //Createthe main window, set the size of window, set the title

    sf::RenderWindow window(sf::VideoMode{ 800,600 }, "Simple Game");
    //Create other window which will be display i  our application

    Menu menu(window.getSize().x, window.getSize().y);
    Options options(window.getSize().x, window.getSize().y);
    Level_menu finish(window.getSize().x, window.getSize().y);
    Music_choise_menu music_choise(window.getSize().x, window.getSize().y);
    Color_Menu color(window.getSize().x, window.getSize().y);
    End_menu the_end2(window.getSize().x, window.getSize().y);
    Action action;
    
    //Set frame limit 
    window.setFramerateLimit(60);

    //create the object which will be resposible for action between game and user
    sf::Event event;
    
    
    while (true) {
        //clear all
        window.clear(sf::Color::Black);
        


        //MAIN MENU
        if (check==0) {
            action.MainMenu_draw(window, check, event, menu);
        }
      
        //GAME
        if(check==1){
            action.Game_draw(window, ball, ball2, ball3, ball4, ball5, ball6, player, meta, the_end2, check);
        }
      
        //OPTIONS MENU
        if (check == 2) {
            action.Options_menu(window,event,check,options);
        }

        //DISPLAY LEVEL SET MENU
        if (check == 4) {
            action.Display_level(window, ball, ball2, ball3, ball4, ball5, ball6, event, finish, level_hard, level_medium, level_easy, check);
        }

        //DISPLAY MUSIC SET MENU
        if (check == 5){
            action.Music_set(window, event, check, a, music_choise, utwory, music);
        }

       //DISPLAY COLOR SET MENU
        if (check == 6) {
            action.Color_set_menu(window,event,player,check,color);
        }

        //Here will be dipslay our END MENU
        if (check == 8) {
            action.Exit_menu(window, player, check, event, the_end2);
        }
        
            window.display();
    }

}

