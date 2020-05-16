#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Graphics.h"
#include "Food.h"

class Snake
{
public:
	Snake(sf::Vector2f loc);
	~Snake();
	void initHead(sf::RenderWindow* win, sf::Vector2f loc);
	void drawSnake(sf::RenderWindow* win, sf::Vector2f loc);
	void moveSnake(sf::Vector2f deltaLoc);
	void growSnake();
private:
	std::vector <sf::Vector2f> segLocations;
	std::vector <sf::RectangleShape> segments;
	sf::Color snkHead ;
	sf::Color snkTail ;
	int numberOfSegs;
	int gameTick;
	const float mvmntRate = 0.2f;
	bool game;
	Graphics gfx;
	Food fd;
};

Snake::Snake(sf::Vector2f loc)
{
	game = true;
	snkHead = sf::Color::Yellow;
	snkTail = sf::Color::Green;
	numberOfSegs = 3;
	gameTick = 100;
	segments.push_back(gfx.getRectAt(snkHead, loc));
	segLocations.push_back(loc);
	for (int i = 1; i < numberOfSegs; i++)
	{
		sf::Vector2f segloc = { loc.x + (20 * i), loc.y + (20 * 0) };
		segLocations.push_back(segloc);
		segments.push_back(gfx.getRectAt(snkTail, segLocations[i]));
	}
}

Snake::~Snake()
{
}

inline void Snake::initHead(sf::RenderWindow* win, sf::Vector2f loc)
{
	drawSnake(win, loc);
	if (numberOfSegs < 10/*segLocations[0] == fd.foodLocation*/)
	{
		growSnake();
	}
}

inline void Snake::drawSnake(sf::RenderWindow* win, sf::Vector2f loc)
{
	for (int i = 0; i < segments.size(); i++)
	{
		segments[i].setPosition(segLocations[i]);
		win->draw(segments[i]);
	}
	for (sf::Vector2f v : segLocations) {
		//std::cout << v.x<<":"<<v.y<<std::endl;
	}
}

inline void Snake::moveSnake(sf::Vector2f deltaLoc)
{
	int f = segments.size()-1;
	int tick = 0;
	gameTick+=1;
	for (int i = numberOfSegs - 1; i > 0; i--)
	{
		//segLocations[0] = { segLocations[0].x += (mvmntRate * deltaLoc.x), segLocations[0].y += (mvmntRate * deltaLoc.y) };
		if ((gameTick % 120) == 0) {
			//segLocations[i] = { segLocations[i].x += (mvmntRate * deltaLoc.x), segLocations[i].y += (mvmntRate * deltaLoc.y) };
			segLocations[i] = { segLocations[i - 1].x /*- (mvmntRate * i)*/, segLocations[i - 1].y };
			//std::cout << segLocations[i].x << " : " << segLocations[i].y;
			f--;
		}
	}
	segLocations[0] = { segLocations[0].x += (mvmntRate * deltaLoc.x), segLocations[0].y += (mvmntRate * deltaLoc.y) };
	//std::cout << std::endl;
}

inline void Snake::growSnake()
{
	numberOfSegs += 1;
	//segments.push_back()
	sf::Vector2f segloc = { segLocations[segLocations.size()-1].x + (20), segLocations[segLocations.size()-1].y + (20 * 0) };
	segLocations.push_back(segloc);
	segments.push_back(gfx.getRectAt(snkTail, segLocations[-1]));
	std::cout << numberOfSegs << std::endl;
}

