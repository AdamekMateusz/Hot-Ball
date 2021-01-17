#include "Options.h"
#include <SFML/Graphics.hpp>

Options::Options(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) {
		//hand error

	}
	options[0].setFont(font);
	options[0].setFillColor(sf::Color::Red);
	options[0].setString("DIFFICULTY LEVEL");
	options[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	options[1].setFont(font);
	options[1].setFillColor(sf::Color::White);
	options[1].setString("MUSIC");
	options[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));	
	
	options[2].setFont(font);
	options[2].setFillColor(sf::Color::White);
	options[2].setString("PLAYER COLOR");
	options[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	options[3].setFont(font);
	options[3].setFillColor(sf::Color::White);
	options[3].setString("BACK");
	options[3].setPosition(sf::Vector2f(20, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	options[4].setFont(font);
	options[4].setFillColor(sf::Color::White);
	options[4].setString("EXIT");
	options[4].setPosition(sf::Vector2f(700, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));


	selectedItemIndex = 0;
}

Options::~Options()
{

}

void Options::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		target.draw(this->options[i], state);
	}
}


void Options::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {

		options[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		options[selectedItemIndex].setFillColor(sf::Color::Red);
	}

}

void Options::MoveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {

		options[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		options[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

