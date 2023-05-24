#include "game.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

void gameFunction(sf::RenderWindow& window, int screen_width, int screen_height)
{

	// Player variables
	float player_x = screen_width / 2;
	float player_y = screen_height / 2;
	// int player_speed = 5;
	Player player(player_x, player_y);

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
		player.setPlayerTexture();
		player.drawTo(window);
		window.display();
	}
}
