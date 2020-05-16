#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "Collision.h"

constexpr int winSize = 600;

void GameLoop(sf::RenderWindow&);
Snake snk({300,200});
Food fd;
Collision dtc;

sf::Vector2f playerDir = {-1,0};
