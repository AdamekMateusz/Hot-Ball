#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 3

class End_menu :public sf::Drawable
{
public:
	End_menu(float width, float height);
	~End_menu();

	//void draw(sf::RenderWindow& window);
	void MoveLeft();
	void MoveRight();

	int GetPressedItem() { return selectedItemIndex; }
	//int GetPressedItem();
	//void clear(sf::RenderWindow& window);
	void set_finish(bool conditional);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	//void draw(sf::RenderTarget& target, sf::RenderStates state);

	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text the_end[MAX_NUMBER_OF_ITEMS];
	int which_finish = 1;


};