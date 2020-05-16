#pragma once
#include <SFML/Graphics.hpp>
#include "Random.h"
#include "Graphics.h"

class Food
{
public:
	Food();
	~Food();
	void drawFood(sf::RenderWindow* win, sf::Vector2f Loc);
	sf::Vector2f getFoodLocation();
	sf::Vector2f foodLocation;
private:
	sf::Color foodColor;
	Graphics gfx;
	Random randm;

};

Food::Food()
{
	foodLocation = getFoodLocation();
	foodColor = sf::Color::Red;
}

Food::~Food()
{
}

inline void Food::drawFood(sf::RenderWindow* win, sf::Vector2f Loc)
{
	win->draw(gfx.getRectAt(foodColor, foodLocation));
}

inline sf::Vector2f Food::getFoodLocation()
{
	return {randm.getRandomInt(0,600), randm.getRandomInt(0,600)};
}

