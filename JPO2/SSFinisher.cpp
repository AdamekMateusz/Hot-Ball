#include "Level_menu.h"
#include <SFML/Graphics.hpp>

Level_menu::Level_menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) {
		//hand error

	}
	Level[0].setFont(font);
	Level[0].setFillColor(sf::Color::Red);
	Level[0].setString("EASY");
	Level[0].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 1, height / 2));

	Level[1].setFont(font);
	Level[1].setFillColor(sf::Color::White);
	Level[1].setString("MEDIUM");
	Level[1].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 2, height / 2));;	

	Level[2].setFont(font);
	Level[2].setFillColor(sf::Color::White);
	Level[2].setString("HARD");
	Level[2].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 3, height / 2));

	Level[3].setFont(font);
	Level[3].setFillColor(sf::Color::White);
	Level[3].setString("BACK");
	Level[3].setPosition(sf::Vector2f(20, height / (MAX_NUMBER_OF_ITEMS + 1)*4));
	


	selectedItemIndex = 0;
}

Level_menu::~Level_menu()
{

}

void Level_menu::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		target.draw(this->Level[i], state);
	}
}


void Level_menu::MoveLeft() {
	if (selectedItemIndex - 1 >= 0) {

		Level[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		Level[selectedItemIndex].setFillColor(sf::Color::Red);
	}

}

void Level_menu::MoveRight() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {

		Level[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		Level[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

