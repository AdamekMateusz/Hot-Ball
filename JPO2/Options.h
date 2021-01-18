#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 5

class Options :public sf::Drawable
{
public:
	/**
		The constructor of class
		@params1 width of window to display(float)
		@params2 height of window to display(float)
	*/
	Options(float width, float height);
	~Options();

	/** Function which allow move up of highlighting. elemnt of the up will be light on other color than rest element.
	*/
	void MoveUp();

	/** Function which allow move down of highlighting. elemnt of the down will be light on other color than rest element.
	*/
	void MoveDown();

	/** Function which return which label was be chooice.
		@return nmer of level which will be set highlighting
	*/
	int GetPressedItem() { return selectedItemIndex; }
	
	

private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	int selectedItemIndex;
	sf::Font font;
	sf::Text options[MAX_NUMBER_OF_ITEMS];



};