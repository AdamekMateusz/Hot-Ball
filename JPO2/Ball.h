#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Ball : public sf::Drawable
{
public:
	

	//pierwsze dwie oznaczaja nasze koordynaty gdzie zostanie stworzony nasz obiket.
	Ball(float t_X, float t_Y, float velocity_X, float velocity_Y);

	Ball() = delete;
	~Ball() = default;

	//funckja odpowiedzialna za aktualizowanie naszego obiektu , ukazuje ze kulka sie przemieszca
	void update();
	//te metody beda zwracac wspolrzedne naszej krawedzi, docelowo bedzimy sprawdzac czy krawedz naszej kulki zderzyal sie z wspolrzedna krawedzi.

	float left();
	float right();
	float top();    
	float bottom();
	void change_level(float x,float y);

private:
	float speed_X;
	float speed_Y;
	//tworzymy kulke
	sf::CircleShape shape;
	//definiujemy wielkosc promienia kulki
	const float ballRadius{ 10.0f };
	//const float ballVelocity{ 3.0f }; //tutaj deklaruje szybosc kulki
	sf::Vector2f velocity{};	//nadajemy w jakich plaszczyznach bedzie sie pporuszala, prosto i w dol



	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;		//nadpisujemy metode z interfejsu z ktorego dziedziczmy jest potrzebne aby moc narysowac figure w main.cpp
};

