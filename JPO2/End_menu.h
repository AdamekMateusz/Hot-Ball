#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 3



class End_menu :public sf::Drawable
{
public:
	/**
		The constructor of class
		@params1 width of window to display(float)
		@params2 height of window to display(float)
	*/
	End_menu(float width, float height);
	~End_menu();

	/** Function which allow move left of highlighting. elemnt of the left will be light on other color than rest element.
	*/
	void MoveLeft();

	/** Function which allow move right of highlighting. elemnt of the left will be light on other color than rest element.
	*/
	void MoveRight();

	/** Function which return which label was be chooice.
		@return nmer of level which will be set highlighting
	*/
	int GetPressedItem() { return selectedItemIndex; }

	/**
		This function set which end menu will be displayed
		@params1 transform (bool) variable , TRUE means that will be displayed menu that YOU WIN the game, if set FALSE will be displayed LOOSE GAME MENU
	*/
	void set_finish(bool which_finish);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text the_end[MAX_NUMBER_OF_ITEMS];
	int which_finish = 1;


};
