#pragma once
#include <SFML/Graphics.hpp>
//tutaj bedziemy robic kwadrat kwadrat bedzie naszym playerem, bedziemy sie nim poruszac
//dziedziczmy publicznie mozliwosc narysownaia nszego pionka

class Pawn :public sf::Drawable
{
public:
	Pawn() = delete;
	~Pawn() = default;
	//create the countructor whitz parameters
	// t_X i t_Y is a start coordinates of our player, t_width, t_hight is a size of our player
	Pawn(float t_X, float t_Y, float t_width, float t_high, float speed, sf::Color a);

	void update();
	sf::Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	//the metod which be check that the player exist
	bool isDestroyed();

	//metoda niszczaca bloczek
	void destroy();

	sf::Vector2f getSize();

	
	void change_color(sf::Color a);
	void position();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	sf::RectangleShape shape;	//we set shape our player like Rectangle
	float player_velocity;		

	sf::Vector2f velocity{};	//the vector which will be set the speed of our player
	bool destroyed{ false };
	

};

