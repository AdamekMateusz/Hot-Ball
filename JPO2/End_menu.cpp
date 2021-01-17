#include "End_menu.h"
#include <SFML/Graphics.hpp>

float width; 
float height;

End_menu::End_menu(float szerokosc, float wysokosc)
{
	if (!font.loadFromFile("arial.ttf")) {
		//hand error

	}
	width = szerokosc;
	height = wysokosc;
	

	selectedItemIndex = 1;
}

End_menu::~End_menu()
{

}

void End_menu::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		target.draw(this->the_end[i], state);
	}
}


void End_menu::MoveLeft() {
	if (selectedItemIndex - 1 >= 1) {

		the_end[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		the_end[selectedItemIndex].setFillColor(sf::Color::Red);
	}

}

void End_menu::MoveRight() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {

		the_end[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		the_end[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


void End_menu::set_finish(bool which_finish) {

	if (which_finish == true) {
		the_end[0].setFont(font);
		the_end[0].setFillColor(sf::Color(255,81,0));
		the_end[0].setString("Gold is yours");
		the_end[0].setPosition(sf::Vector2f(300, height / 2));

		the_end[1].setFont(font);
		the_end[1].setFillColor(sf::Color::White);
		the_end[1].setString("Main Menu");

		the_end[1].setPosition(sf::Vector2f(20, 550));

		the_end[2].setFont(font);
		the_end[2].setFillColor(sf::Color::White);
		the_end[2].setString("EXIT");
		the_end[2].setPosition(sf::Vector2f(720, 550));

		//selectedItemIndex = 0;


	}
	if (which_finish == false) {
		the_end[0].setFont(font);
		the_end[0].setFillColor(sf::Color(255, 81, 0));
		the_end[0].setString("Pick up your bones");
	

		the_end[0].setPosition(sf::Vector2f(300, height / 2));

		the_end[1].setFont(font);
		the_end[1].setFillColor(sf::Color::Red);
		the_end[1].setString("Main Menu");
		the_end[1].setPosition(sf::Vector2f(20, 550));

		the_end[2].setFont(font);
		the_end[2].setFillColor(sf::Color::White);
		the_end[2].setString("EXIT");
		the_end[2].setPosition(sf::Vector2f(720, 550));

		//selectedItemIndex = 0;


	}



}