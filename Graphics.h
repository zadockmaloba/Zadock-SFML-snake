#pragma once
#include <SFML/Graphics.hpp>

class Graphics
{
public:
	Graphics();
	~Graphics();
	sf::RectangleShape getRectAt(sf::Color& col, sf::Vector2f coord);

private:
	const sf::Vector2f rectSize = { 20.f,20.f };

};

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

inline sf::RectangleShape Graphics::getRectAt(sf::Color& col, sf::Vector2f coord)
{
	sf::RectangleShape box(rectSize);
	box.setFillColor(col);
	box.setOrigin(rectSize.x / 2, rectSize.y / 2);
	box.setPosition(coord);
	return box;
}
