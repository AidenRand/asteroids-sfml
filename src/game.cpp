#include "game.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

void gameFunction(sf::RenderWindow& window, int screen_width, int screen_height)
{

	// Player variables
	int player_width = 32;
	int player_height = 32;
	float player_x = screen_width / 2;
	float player_y = screen_height / 2;
	float player_speed = 0.3f;
	float player_rotation = 5;
	Player player(player_x, player_y, player_width, player_height);

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
		player.movePlayer(player_speed, player_rotation);
		window.display();
	}
}