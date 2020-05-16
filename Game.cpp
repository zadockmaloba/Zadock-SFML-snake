#include "Game.h"

/* **************************************************************************
   *   Project by : Zadock Maloba Muyeshi
   *   E-mail : malobazadock@gmail.com                                       
   *   HELP SCIENCE ;)                         
   ************************************************************************** */  
int main()
{
	sf::RenderWindow window(sf::VideoMode(winSize, winSize), "SNEKGAME 3.0    --Zadock", sf::Style::Close);

	while (window.isOpen())
	{
		GameLoop(window);
	}
	return 0;
}

void GameLoop(sf::RenderWindow& window)
{
	sf::RenderWindow* xwin = &window;
	window.clear();
	sf::Event events;
	while (window.pollEvent(events))
	{
		if (events.type == sf::Event::Closed)
		{
			window.close();
		}
		if (events.type == sf::Event::KeyReleased) {
			if (events.key.code == sf::Keyboard::Up && playerDir.y != 1) {
				//snk.moveSnake({ 0,-1 });
				playerDir = { 0,-1 };
			}
			else if (events.key.code == sf::Keyboard::Down && playerDir.y != -1) {
				//snk.moveSnake({ 0,1 });
				playerDir = { 0,1 };
			}
			else if (events.key.code == sf::Keyboard::Left && playerDir.x!=1) {
				//snk.moveSnake({ -1,0 });
				playerDir = { -1,0 };
			}
			else if (events.key.code == sf::Keyboard::Right && playerDir.x != -1) {
				//snk.moveSnake({ 1,0 });
				playerDir = { 1,0 };
			}
			if (events.key.code == sf::Keyboard::A ) {
				snk.growSnake();
			}
		}
	}
	snk.initHead(xwin, { 200.f,20.f });
	fd.drawFood(xwin, {});
	snk.moveSnake(playerDir);
	window.display();
}
