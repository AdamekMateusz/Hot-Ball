#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 4

class Finisher :public sf::Drawable
{
public:
	Finisher(float width, float height);
	~Finisher();

	//void draw(sf::RenderWindow& window);
	void MoveLeft();
	void MoveRight();

	int GetPressedItem() { return selectedItemIndex; }
	//int GetPressedItem();
	//void clear(sf::RenderWindow& window);


private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	//void draw(sf::RenderTarget& target, sf::RenderStates state);
	int selectedItemIndex;
	sf::Font font;
	sf::Text FinishW[MAX_NUMBER_OF_ITEMS];



};