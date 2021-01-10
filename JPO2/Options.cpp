#include "Options.h"
#include <SFML/Graphics.hpp>

Options::Options(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) {
		//hand error

	}
	options[0].setFont(font);
	options[0].setFillColor(sf::Color::Red);
	options[0].setString("Poziom Trudnosci");
	options[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	options[1].setFont(font);
	options[1].setFillColor(sf::Color::White);
	options[1].setString("Muzyka");
	options[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));	//ta liczb 2 na koncu pozwala nam uzyskac kolejnosc naszego Menu , Play bedzie pierwsze options 2
	
	options[2].setFont(font);
	options[2].setFillColor(sf::Color::White);
	options[2].setString("kolory Obiektow");
	options[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	options[3].setFont(font);
	options[3].setFillColor(sf::Color::White);
	options[3].setString("wstecz");
	options[3].setPosition(sf::Vector2f(20, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	options[4].setFont(font);
	options[4].setFillColor(sf::Color::White);
	options[4].setString("Exit");
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

/*
void Options::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		target.draw(this->options[i], state);
	}
}
*/
/*
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}


}
*/


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
/*
int Menu:: GetPressedItem() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
		return selectedItemIndex;
	}
	else
		return -1000;

}
*/
