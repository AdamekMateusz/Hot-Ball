#pragma once
#include <SFML/Graphics.hpp>

class Meta : public sf::Drawable
{
public:
	Meta() = delete;
	~Meta() = default;

	Meta(float t_X, float t_Y);

	//void update();

	float left();
	float right();
	float top();
	float bottom();

	bool isDestroyed();
	void destroy();


private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	sf::RectangleShape shape;
	const float Width = 80.0;	
	const float High = 30;

	bool destroyed{ false };
};



