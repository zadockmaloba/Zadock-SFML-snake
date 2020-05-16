#pragma once
#include <SFML/Graphics.hpp>

class Collision
{
public:
	Collision();
	~Collision();
	bool dtcCollision(sf::RectangleShape& a, sf::RectangleShape& b);

private:

};

Collision::Collision()
{
}

Collision::~Collision()
{
}

inline bool Collision::dtcCollision(sf::RectangleShape& a, sf::RectangleShape& b)
{
	if (a.getGlobalBounds() == b.getGlobalBounds())
	{
		return true;
	}
	return false;
}
