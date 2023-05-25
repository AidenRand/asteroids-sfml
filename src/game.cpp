#include "game.hpp"
#include "asteroids.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

void gameFunction(sf::RenderWindow& window, int screen_width, int screen_height)
{

	// Player variables
	int player_width = 32;
	int player_height = 32;
	float player_x = screen_width / 2;
	float player_y = screen_height / 2;
	float player_speed = 1.0f;
	float player_rotation = 5;
	Player player(player_x, player_y, player_width, player_height);

	// Asteroid variables
	std::vector<Asteroids> asteroid_vector;
	long unsigned int max_asteroids = 10;
	int asteroid_speed = 1;
	int asteroid_width = 128;
	int asteroid_height = 128;

	float dt;
	sf::Clock clock;

	while (window.isOpen())
	{
		dt = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();

		// Create asteroids
		Asteroids asteroid(asteroid_width, asteroid_height);
		asteroid.spawnAsteroids(screen_width, screen_height, asteroid_width, asteroid_height);
		asteroid.chooseAsteroidDirection(asteroid_speed);

		if (asteroid_vector.size() < max_asteroids)
		{
			asteroid_vector.push_back(asteroid);
		}

		for (long unsigned int i = 0; i != asteroid_vector.size(); i++)
		{
			asteroid_vector[i].drawTo(window);
			asteroid_vector[i].moveAsteroids();
		}

		player.setPlayerTexture();
		player.drawTo(window);
		player.movePlayer(player_speed, dt);
		player.rotatePlayer(player_rotation);
		player.screenWrapping(screen_width, screen_height);
		window.display();
	}
}
