#include "Ball.h"


Ball::Ball(float t_X, float t_Y,float velocity_X,float velocity_Y) {
	
	shape.setPosition(t_X, t_Y);				//ustawiamy pozycje gfdzie kulka zostanie utworzna
	shape.setRadius(this->ballRadius);			//ustawiamy promien
	shape.setFillColor(sf::Color::Cyan);		//ustawiamy kolor wypelninienia
	shape.setOrigin(this->ballRadius, this->ballRadius);							//chemy ustawic nasz punkt przesuniecia, ktory znajduje sie w lewym rogu figury na jego srodek.
	velocity = { velocity_X,velocity_Y };
	speed_X = velocity_X;
	speed_Y = velocity_Y;

}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const
{

	target.draw(this->shape, state);

}

void Ball::update() {
	//metoda move przyjmuje jako parametr vektor
	shape.move(this->velocity);

	//tutaj bedziemy sprawdzac kolizje ze scianami
	if (this->left() < 0) {
		velocity.x = speed_X;		//jezli jest rowna to zmieniamy nasza predkosc naszej kulki na odwrtona (dodatnia w tym przypadku)
	}
	else if (this->right() > 800) {
		velocity.x = -speed_X;	//800 to rozmiar naszego okna
	}
	else if (this->top() < 0) {
		velocity.y = speed_Y;
	}
	else if (this->bottom() > 600) {
		velocity.y = -speed_Y;
	}


}

float Ball::left() 
{	//odejmujemy promien wtedy dostaniemy wspolrzedne lewej krawedzi kulki
	return this->shape.getPosition().x - shape.getRadius();

}
float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

void Ball::change_level(float x, float y) {
	speed_X = x;
	speed_Y = y;

}