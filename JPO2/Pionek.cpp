#include "Pionek.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Pionek::Pionek(float t_X,float t_Y,float width, float high,float speed, sf::Color a) {
	shape.setPosition(t_X, t_Y);
	shape.setFillColor(a);
	shape.setSize({ width,high });
	shape.setOrigin(width / 2.f, high / 2.f); // ustawiamy nasz origicz na srodku naszego playera;
	player_velocity = speed;
	velocity = { player_velocity,0 };
	destroyed = false;

}

void Pionek::draw(sf::RenderTarget& target, sf::RenderStates state) const
{

	target.draw(this->shape, state);

}

void Pionek::update() {
	this->shape.move(this->velocity);
	//tutaj definiuje co sie bedzie dzialo jesli wcisniemy jakis przycisk, np. gddy wcisniemy przycisk strzalka "UP" ora z wspolrzedne nasze beda wieksze niz 0 na osi Y to pozwoli nam sie przesunac do gory


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left() > 0) {
		velocity.x = -player_velocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < 800) {
		velocity.x = player_velocity;
	}

	else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && this->top() > 0) {
		velocity.y = -player_velocity;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && this->bottom() < 600) {
		velocity.y = player_velocity;
	}
	/*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && this->bottom() >= 600 && this ->right()>=800) {
		velocity.y = 0;
		velocity.x = 0;

	}*/

	
	else
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	

}


float Pionek::left()
{	//ustawiamy nasz punkt przedmiotu na jego srodek. 

	if ((this->shape.getPosition().x - shape.getSize().x / 2.f) <= 0) {
		shape.setPosition(20, shape.getPosition().y);
		return this->shape.getPosition().x - shape.getSize().x / 2.f;

	}
	else {
		return this->shape.getPosition().x - shape.getSize().x / 2.f;
	}

}
float Pionek::right()
{
	if ((this->shape.getPosition().x + shape.getSize().x / 2.f) >= 800){
		shape.setPosition(780, shape.getPosition().y);
		return this->shape.getPosition().x + shape.getSize().x / 2.f;
	}
	else {
		return this->shape.getPosition().x + shape.getSize().x / 2.f;
	}
}

float Pionek::top()
{
	if ((this->shape.getPosition().y - shape.getSize().y / 2.f) <= 0) {
		shape.setPosition(shape.getPosition().x,20);
		return this->shape.getPosition().y - shape.getSize().y / 2.f;
	}
	else {
		return this->shape.getPosition().y - shape.getSize().y / 2.f;
	}
	
}

float Pionek::bottom()
{
	if ((this->shape.getPosition().y + shape.getSize().y / 2.f) >= 600) {
		shape.setPosition(shape.getPosition().x, 580);
		return this->shape.getPosition().y + shape.getSize().y / 2.f;
	}
	else {
		return this->shape.getPosition().y + shape.getSize().y / 2.f;
	}
	
}


sf::Vector2f Pionek::getPosition() {

	return this-> shape.getPosition();
}


bool Pionek::isDestroyed() {
	return this->destroyed;
}

void Pionek::destroy(){

	this->destroyed = true;
	std::cout << "Jest w destroy\n";
	//exit(0);
}

sf::Vector2f Pionek :: getSize() {
	return shape.getSize();
}

void Pionek :: change_color(sf::Color a) {
	shape.setFillColor(a);

}

void Pionek::position() {
	shape.setPosition(400, 300);

}