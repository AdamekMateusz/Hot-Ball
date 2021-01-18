#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Ball : public sf::Drawable
{
public:
	
	/**
		this is the contructor of our Ball
		@param1 the X axe of size of our ball (float)
		@param2 the Y axe of size of our ball (float)
		@param3 the speed of X direction (float)
		@param4 the speed of Y direction (float)
	*/
	Ball(float t_X, float t_Y, float velocity_X, float velocity_Y);

	Ball() = delete;
	~Ball() = default;

	/**update this ist the function which refres object on the window, no paramiters
	 
	*/
	void update();

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

	/**This function allow change the level of our game, 
	 @param1 the speed of X direction (float)
	 @param2 the speed of Y direction (float)
	
	*/
	void change_level(float x,float y);

private:
	float speed_X;
	float speed_Y;
	//create the ball
	sf::CircleShape shape;
	//set ball radius
	const float ballRadius{ 10.0f };
	sf::Vector2f velocity{};	//ball move direction



	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;		//nadpisujemy metode z interfejsu z ktorego dziedziczmy jest potrzebne aby moc narysowac figure w main.cpp
};

