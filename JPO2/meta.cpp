#include "meta.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Meta::Meta(float t_X, float t_Y) {
	shape.setPosition(t_X, t_Y);
	shape.setFillColor(sf::Color::Yellow);
	shape.setSize({ this->Width, this->High});
	shape.setOrigin(Width / 2.f, High/2.f); // ustawiamy nasz origicz na srodku naszego playera;


}

void Meta::draw(sf::RenderTarget& target, sf::RenderStates state) const
{

	target.draw(this->shape, state);

}



float Meta::left()
{	//ustawiamy nasz punkt przedmiotu na jego srodek. 
	return this->shape.getPosition().x - shape.getSize().x / 2.f;

}
float Meta::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Meta::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Meta::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

bool Meta::isDestroyed() {
	return this->destroyed;
}

void Meta::destroy() {
	//if player get Meta , something might display
	this->destroyed = true;
	
	
	
	
}