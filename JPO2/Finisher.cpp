#include "Finisher.h"
#include <SFML/Graphics.hpp>

Finisher::Finisher(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) {
		//hand error

	}
	FinishW[0].setFont(font);
	FinishW[0].setFillColor(sf::Color::Red);
	FinishW[0].setString("Latwy");
	//FinishW[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	FinishW[0].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 1, height / 2));

	FinishW[1].setFont(font);
	FinishW[1].setFillColor(sf::Color::White);
	FinishW[1].setString("Sredni");
	FinishW[1].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 2, height / 2));;	//ta liczb 2 na koncu pozwala nam uzyskac kolejnosc naszego Menu , Play bedzie pierwsze options 2

	FinishW[2].setFont(font);
	FinishW[2].setFillColor(sf::Color::White);
	FinishW[2].setString("Trudny");
	FinishW[2].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 3, height / 2));

	FinishW[3].setFont(font);
	FinishW[3].setFillColor(sf::Color::White);
	FinishW[3].setString("wstecz");
	FinishW[3].setPosition(sf::Vector2f(20, height / (MAX_NUMBER_OF_ITEMS + 1)*4));
	


	selectedItemIndex = 0;
}

Finisher::~Finisher()
{

}

void Finisher::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		target.draw(this->FinishW[i], state);
	}
}


void Finisher::MoveLeft() {
	if (selectedItemIndex - 1 >= 0) {

		FinishW[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		FinishW[selectedItemIndex].setFillColor(sf::Color::Red);
	}

}

void Finisher::MoveRight() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {

		FinishW[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		FinishW[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

