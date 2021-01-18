#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 4

class Music_choise_menu :public sf::Drawable
{
public:
	/**
		The constructor of class
		@params1 width of window to display(float)
		@params2 height of window to display(float)
	*/
	Music_choise_menu(float width, float height);
	~Music_choise_menu();

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
	sf::Text music_choise[MAX_NUMBER_OF_ITEMS];



};