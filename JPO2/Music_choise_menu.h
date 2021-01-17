#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 4

class Music_choise_menu :public sf::Drawable
{
public:
	Music_choise_menu(float width, float height);
	~Music_choise_menu();

	void MoveUp();
	void MoveDown();

	int GetPressedItem() { return selectedItemIndex; }
	


private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	
	int selectedItemIndex;
	sf::Font font;
	sf::Text music_choise[MAX_NUMBER_OF_ITEMS];



};