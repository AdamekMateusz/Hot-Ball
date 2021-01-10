#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 4

class Color_Menu :public sf::Drawable
{
public:
	Color_Menu(float width, float height);
	~Color_Menu();

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
	sf::Text colors[MAX_NUMBER_OF_ITEMS];



};