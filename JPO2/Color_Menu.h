#pragma once
#include <SFML/Graphics.hpp> 

#define MAX_NUMBER_OF_ITEMS 4



class Color_Menu :public sf::Drawable
{
public:
	/**@brief constructor whith parameterf of Color Menu
	   @params1 width of our display window (float)
	   @params2 height f our display window (float)
	*/
	Color_Menu(float width, float height);
	~Color_Menu();

	/** Function which allow move left of highlighting. elemnt of the left will be light on other color than rest element.
	*/
	void MoveLeft();

	/** Function which allow move right of highlighting. elemnt of the left will be light on other color than rest element.
	*/
	void MoveRight();

	/** Function which return which label was be choose.
		@return nmer of level which will be set highlighting
	*/
	int GetPressedItem() { return selectedItemIndex; }
	


private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	int selectedItemIndex;
	sf::Font font;
	sf::Text colors[MAX_NUMBER_OF_ITEMS];



};