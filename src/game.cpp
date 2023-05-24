#include "game.hpp"
#include <SFML/Graphics.hpp>

void gameFunction(sf::RenderWindow& window, int screen_width, int screen_height)
{

	std::cout << screen_width << screen_height;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.display();
	}
}
