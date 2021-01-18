#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
#include "Ball.h"
#include "Pawn.h"
#include "meta.h"
#include "End_menu.h"
#include "Level_menu.h"
#include <string>
#include "Music_choise_menu.h"
#include <vector>
#include <SFML/Audio.hpp>
#include "Color_Menu.h"


class Options;

class Action
{
public:
	/** MainMenu_draw display Main Menu in windows,we provide the parameters through references, the function accepts the following parameters
	*  @param1 sf::RenderWindow , we must get window fromm SFML library
	*  @param2 int check, this is the variable that is responsible for exporting the method
	*  @param3 sf::Event ,this is part of SFML library, Event allow us to interaction beetween game and user using keyboards.
	*  @param4 Menu, object of class Menu which will be displaying
	
	*/
	void MainMenu_draw(sf::RenderWindow& window, int& check, sf::Event& event, Menu& menu);

	/** Game_draw it is the method which is responsible for start and display game on our window,
		@param1 sf::RenderWindow , we must get window fromm SFML library
		@param2 transfers the ball object that will be displayed in our game window
		@param3 transfers the ball2 object that will be displayed in our game window
		@param4 transfers the ball3 object that will be displayed in our game window
		@param5 transfers the ball4 object that will be displayed in our game window
		@param6 transfers the ball5 object that will be displayed in our game window
		@param7 transfers the ball6 object that will be displayed in our game window
		@param8 transfers the Pawn object that will be displayed in our game window
		@param9 transfers the Meta object that will be displayed in our game window
		@param10 transfers the End_menu object that will be displayed in our game window
		@param11 int check, this is the variable that is responsible for changing the method, if check will be changed, other funvtion from Action class will be called
	*/
	void Game_draw(sf::RenderWindow& window, Ball& ball, Ball& ball2, Ball& ball3, Ball& ball4, Ball& ball5, Ball& ball6, Pawn& player, Meta& meta, End_menu& the_end2, int& check);

	/** Options_menu this is a method that allows you to view variable from the options menu
		@param1 sf::RenderWindow , we must get window fromm SFML library
		@param2 sf::Event ,this is part of SFML library, Event allow us to interaction beetween game and user using keyboards.
		@param3 int check, this is the variable that is responsible for changing the method, if check will be changed, other funvtion from Action class will be called
		@param4 transfers the Options object that will be displayed in our window
		
	*/
	void Options_menu(sf::RenderWindow& window, sf::Event& event, int& check, Options& options);

	/**	Display_level this is a method that allows you levels of our game to choose
		@param1 sf::RenderWindow , we must get window fromm SFML library
		@param2 transfers the ball object that will be displayed in our game window
		@param3 transfers the ball2 object that will be displayed in our game window
		@param4 transfers the ball3 object that will be displayed in our game window
		@param5 transfers the ball4 object that will be displayed in our game window
		@param6 transfers the ball5 object that will be displayed in our game window
		@param7 transfers the ball6 object that will be displayed in our game window
		@param8 sf::Event ,this is part of SFML library, Event allow us to interaction beetween game and user using keyboards.
		@param9 transfers the Level_menu object that will be displayed in our window
		@param10 We pass a vector that contains, properties for LVL HARD
		@param11 We pass a vector that contains, properties for LVL MEDIUM
		@param12 We pass a vector that contains, properties for LVL EASY
		@param13 int check, this is the variable that is responsible for changing the method, if check will be changed, other funvtion from Action class will be called
	
	*/

	void Display_level(sf::RenderWindow& window, Ball& ball, Ball& ball2, Ball& ball3, Ball& ball4, Ball& ball5, Ball& ball6, sf::Event event, Level_menu& finish, std::vector<std::vector<int>>& level_hard, std::vector<std::vector<int>>& level_medium, std::vector<std::vector<int>>& level_easy, int& check);
	
	/**Music_set A method that allows you to select background music
		@param1 sf::RenderWindow , we must get window fromm SFML library
		@param2 sf::Event ,this is part of SFML library, Event allow us to interaction beetween game and user using keyboards.
		@param3 int check, this is the variable that is responsible for changing the method, if check will be changed, other funvtion from Action class will be called
		@param4 in this variable we set currently playing background music
		@param5 transfers the Music_choice_menu object that will be displayed in our window
		@param6 We pass a vector that contains, properties for avaliable song to choice.
		@param7 sf::Music , we pass object of SFML Music,

	
	*/
	void Music_set(sf::RenderWindow& window, sf::Event& event, int& check, std::string& a, Music_choise_menu& music_choise, std::vector<std::string>& utwory, sf::Music& music);

	/**Color_set_menu this is a method which allow choise color of our player/pawn
		@param1 sf::RenderWindow , we must get window fromm SFML library
		@param2 sf::Event ,this is part of SFML library, Event allow us to interaction beetween game and user using keyboards.
		@param3 transfers the Pawn object that will be displayed in our game window
		@param4 int check, this is the variable that is responsible for changing the method, if check will be changed, other funvtion from Action class will be called
		@param5 transfers the Color_menu object that will be displayed in our window
	
	
	*/
	void Color_set_menu(sf::RenderWindow& window, sf::Event& event, Pawn& player, int& check, Color_Menu& color);

	/**Exit_menu this is the menu which will be displayed when the player finished the game or will be killed from the object
		@param1 sf::RenderWindow , we must get window fromm SFML library
		@param2 transfers the Pawn object that will be displayed in our game window
		@param3 int check, this is the variable that is responsible for changing the method, if check will be changed, other funvtion from Action class will be called
		@param4 sf::Event ,this is part of SFML library, Event allow us to interaction beetween game and user using keyboards.
		@param5 transfers the End_menu object that will be displayed in our window
	*/
	void Exit_menu(sf::RenderWindow& window, Pawn& player, int& check, sf::Event& event, End_menu& the_end2);
};

