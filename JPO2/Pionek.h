#pragma once
#include <SFML/Graphics.hpp>
//tutaj bedziemy robic kwadrat kwadrat bedzie naszym playerem, bedziemy sie nim poruszac
//dziedziczmy publicznie mozliwosc narysownaia nszego pionka

class Pionek :public sf::Drawable
{
public:
	Pionek() = delete;
	~Pionek() = default;
	//wspolrzedne okreslaja polorzenie playera na ekranie
	Pionek(float t_X, float t_Y,float t_width, float t_high);

	void update();
	sf::Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	//sprawdzamy czy Pionek istnieje
	bool isDestroyed();

	//metoda niszczaca bloczek
	void destroy();

	sf::Vector2f getSize();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	sf::RectangleShape shape;
	//const float playerWidth = 40.0;	//okreslamy szerokosc naszego playera
	//const float playerHigh = 40;
	const float player_velocity = 6;

	sf::Vector2f velocity{ player_velocity,0 };	//ustawiamy z jaka predkoscia bedzi poruszal sie nasz player
	bool destroyed{ false };


};

