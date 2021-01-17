#include "Music_choise_menu.h"
#include <SFML/Graphics.hpp>

Music_choise_menu::Music_choise_menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) {
		//hand error

	}
	 music_choise[0].setFont(font);
	 music_choise[0].setFillColor(sf::Color::Red);
	 music_choise[0].setString("podklad");

	 music_choise[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	 music_choise[1].setFont(font);
	 music_choise[1].setFillColor(sf::Color::White);
	 music_choise[1].setString("My_Doorbell");
	 music_choise[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));	
	 
	 music_choise[2].setFont(font);
	 music_choise[2].setFillColor(sf::Color::White);
	 music_choise[2].setString("Hardest_Button");
	 music_choise[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	 
	 music_choise[3].setFont(font);
	 music_choise[3].setFillColor(sf::Color::White);
	 music_choise[3].setString("BACK");
	 music_choise[3].setPosition(sf::Vector2f(20, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));


	
	selectedItemIndex = 0;
}

Music_choise_menu::~Music_choise_menu()
{

}

void Music_choise_menu::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		target.draw(this->music_choise[i], state);
	}
}


void Music_choise_menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {

		music_choise[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		music_choise[selectedItemIndex].setFillColor(sf::Color::Red);
	}

}

void Music_choise_menu::MoveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {

		music_choise[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		music_choise[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

