#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 3

class End_menu :public sf::Drawable
{
public:
	End_menu(float width, float height);
	~End_menu();

	void MoveLeft();
	void MoveRight();

	int GetPressedItem() { return selectedItemIndex; }
	
	void set_finish(bool which_finish);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text the_end[MAX_NUMBER_OF_ITEMS];
	int which_finish = 1;


};
