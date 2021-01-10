#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 5

class Options :public sf::Drawable
{
public:
	Options(float width, float height);
	~Options();
	
	//void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int GetPressedItem() { return selectedItemIndex; }
	//int GetPressedItem();
	//void clear(sf::RenderWindow& window);
	

private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	//void draw(sf::RenderTarget& target, sf::RenderStates state);
	int selectedItemIndex;
	sf::Font font;
	sf::Text options[MAX_NUMBER_OF_ITEMS];



};