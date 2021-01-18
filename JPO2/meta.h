#pragma once
#include <SFML/Graphics.hpp>

class Meta : public sf::Drawable
{
public:
	Meta() = delete;
	~Meta() = default;

	/** Constructor of Meta 
		@params1 width of window(float)
		@params2 hight of window(float)
	*/
	Meta(float t_X, float t_Y);

	//void update();

	/**void left() this function calculated left edge of our ball
	 @return coordinates of left edge of ball
	*/
	float left();

	/**void right() this function calculated right edge of our ball
	 @return coordinates of right edge of ball
	*/
	float right();

	/**void top() this function calculated top edge of our ball
	 @return coordinates of top edge of ball
	*/
	float top();

	/**void bottom() this function calculated left edge of our ball
	  @return coordinates of bottom edge of ball
	*/
	float bottom();

	/** This function checks if the element has been damaged
		@return True or False
	*/
	bool isDestroyed();

	/** Set destroyed variable on TRUE, 
	*/
	void destroy();


private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	sf::RectangleShape shape;
	const float Width = 80.0;	
	const float High = 30;

	bool destroyed{ false };
};



