#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
#include "Ball.h"
#include "Pionek.h"
#include "meta.h"
#include "End_menu.h"
#include "Finisher.h"
#include <string>
#include "Music_choise_menu.h"
#include <vector>
#include <SFML/Audio.hpp>
#include "Color_Menu.h"


class Options;

class Action
{
public:
	void MainMenu_draw(sf::RenderWindow& window, int& check, sf::Event& event, Menu& menu);
	void Game_draw(sf::RenderWindow& window, Ball& ball, Ball& ball2, Ball& ball3, Ball& ball4, Ball& ball5, Ball& ball6, Pionek& player, Meta& meta, End_menu& the_end2, int& check);
	void Options_menu(sf::RenderWindow& window, sf::Event& event, int& check, Options& options);
	void Display_level(sf::RenderWindow& window, Ball& ball, Ball& ball2, Ball& ball3, Ball& ball4, Ball& ball5, Ball& ball6, sf::Event event, Finisher& finish, std::vector<std::vector<int>>& level_hard, std::vector<std::vector<int>>& level_medium, std::vector<std::vector<int>>& level_easy, int& check);
	void Music_set(sf::RenderWindow& window, sf::Event& event, int& check, std::string& a, Music_choise_menu& music_choise, std::vector<std::string>& utwory, sf::Music& music);
	void Color_set_menu(sf::RenderWindow& window, sf::Event& event, Pionek& player, int& check, Color_Menu& color);
	void Exit_menu(sf::RenderWindow& window, Pionek& player, int& check, sf::Event& event, End_menu& the_end2);
};

