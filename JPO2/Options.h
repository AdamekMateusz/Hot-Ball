#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 5

class Options :public sf::Drawable
{
public:
	Options(float width, float height);
	~Options();
	void MoveUp();
	void MoveDown();

	int GetPressedItem() { return selectedItemIndex; }
	
	

private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	int selectedItemIndex;
	sf::Font font;
	sf::Text options[MAX_NUMBER_OF_ITEMS];



};