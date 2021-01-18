#pragma once
#include <SFML/Graphics.hpp>


class Pawn :public sf::Drawable
{
public:
	Pawn() = delete;
	~Pawn() = default;
	//create the countructor whitz parameters
	// t_X i t_Y is a start coordinates of our player, t_width, t_hight is a size of our player

	/**
		Construcors of Pawn accepts the following parameters
		@param1  it is X coordinates when the Pawn started(float)
		@param2  it is Y coordinates when the Pawn started(float)
		@param3 the X axe of size of our ball (float)
		@param4 the Y axe of size of our ball (float)
		@param5 the speed of X direction (float)
		@param6 the speed of Y direction (float)
		@param7 sf::Color, set color of our object, 
	*/
	Pawn(float t_X, float t_Y, float t_width, float t_high, float speed, sf::Color a);

	/**update this ist the function which refres object on the window, no paramiters

	*/
	void update();

	/**
		In this vector will we Position fo our Pawn
	*/
	sf::Vector2f getPosition();

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

	
	/** This function checks if the element has been damaged,check that the player exist
		@return True or False
	*/
	bool isDestroyed();

	/** Set destroyed variable on TRUE,
	*/
	void destroy();

	/**
		In this vector will be size of our Pawn
	*/
	sf::Vector2f getSize();

	/**
		This function set color of our Pawn
		@param1 sf::Color, get SFML color , to set color of our PAWN
	*/
	void change_color(sf::Color a);

	/** 
		This function set position of our Pawn
	*/
	void position();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	sf::RectangleShape shape;	//we set shape our player like Rectangle
	float player_velocity;		

	sf::Vector2f velocity{};	//the vector which will be set the speed of our player
	bool destroyed{ false };
	

};

