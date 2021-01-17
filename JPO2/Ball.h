#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Ball : public sf::Drawable
{
public:
	

	//coordinates od our ball,speed our ball
	Ball(float t_X, float t_Y, float velocity_X, float velocity_Y);

	Ball() = delete;
	~Ball() = default;

	//function which refresh our object on the map
	void update();
	
	//return the edge, we will be check that the coordinates of our ball is the same like edge
	float left();
	float right();
	float top();    
	float bottom();
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

