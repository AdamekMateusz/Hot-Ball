#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	/**
		The constructor of class
		@params1 width of window to display(float)
		@params2 height of window to display(float)
	*/
	Menu(float width, float height);
	~Menu();

	/**
		Function which allow draw class Menu in SFML Redener window
		@parmas1 sf::RenderWindow , part of SFML, main windows of the application
	*/
	void draw(sf::RenderWindow& window);

	/** Function which allow move up of highlighting. elemnt of the up will be light on other color than rest element.
	*/
	void MoveUp();

	/** Function which allow move down of highlighting. elemnt of the down will be light on other color than rest element.
	*/
	void MoveDown();

	/** Function which is responsibility for delete Menu obeject from main windows, all will be cleaned.
	*	@params1 sf::RenderWindow , part of SFML, main windows of the application
	*/
	void close(sf::RenderWindow& window);

	/** Function which return which label was be chooice.
		@return nmer of level which will be set highlighting
	*/
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];



};