#include "game.hpp"
#include "asteroids.hpp"
#include "bullet.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

void gameFunction(sf::RenderWindow& window, int screen_width, int screen_height)
{

	bool level_2 = false;

	// Player variables
	int player_width = 32;
	int player_height = 32;
	float player_x = screen_width / 2;
	float player_y = screen_height / 2;
	float player_speed = 1.0f;
	float player_rotation = 5;
	Player player(player_x, player_y, player_width, player_height);

	// Bullet variables
	float bullet_width = 2;
	float bullet_height = 2;
	float bullet_speed = 10;
	bool bullet_dead = false;
	bool bullet_firing = false;
	int reload_timer = 0;
	sf::Color white = sf::Color(200, 200, 200);
	std::vector<Bullet> bullet_vector;

	// Asteroid variables
	std::vector<Asteroids> asteroid_vector;
	std::vector<Asteroids> asteroid_vector2;
	long unsigned int max_asteroids = 5;
	// long unsigned int max_asteroids2 = 0;
	int asteroid_width = 128;
	int asteroid_height = 128;
	float asteroid_posx;
	float asteroid_posy;
	float asteroid_scale = 0.5;
	bool asteroid_dead = false;
	Asteroids asteroid(asteroid_width, asteroid_height);
	Asteroids asteroid2(asteroid_width, asteroid_height);

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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				bullet_firing = true;
			}
		}

		window.clear();

		Bullet bullet(bullet_width, bullet_height, white);

		// Create asteroids
		asteroid.spawnAsteroids(screen_width, screen_height, asteroid_width, asteroid_height);
		asteroid.chooseAsteroidDirection();
		asteroid.chooseTexture();

		asteroid2.spawn_new(level_2, asteroid_posx, asteroid_posy);
		asteroid2.chooseAsteroidDirection();
		asteroid2.chooseTexture();

		// Push asteroids to asteroid vector
		if (asteroid_vector.size() < max_asteroids)
		{
			asteroid_vector.push_back(asteroid);
		}

		if (level_2)
		{
			max_asteroids++;
			asteroid_vector.push_back(asteroid2);
			level_2 = false;
		}

		// Draw and move asteroids
		for (long unsigned int i = 0; i < asteroid_vector.size(); i++)
		{
			asteroid_vector[i].drawTo(window);
			asteroid_vector[i].moveAsteroids(dt);
			asteroid_vector[i].screenWrapping(screen_width, screen_height);
			asteroid_vector[i].collision(asteroid_dead, bullet_dead, asteroid_scale, bullet_vector, level_2, asteroid_posx, asteroid_posy);

			// If bullet_dead is true despawn the bullet
			if (bullet_dead)
			{
				bullet_vector.erase(bullet_vector.begin() + i);
				bullet_dead = false;
			}

			// if (asteroid_dead && level_2)
			// {
			// 	max_asteroids--;
			// 	asteroid_vector.erase(asteroid_vector.begin() + i);
			// 	asteroid_dead = false;
			// }
		}

		std::cout << asteroid_vector.size() << "\n";

		// If reload timer is zero, fire bullet
		if (reload_timer == 0)
		{
			if (bullet_firing)
			{
				bullet.setPos(player);
				bullet.fireBullet(bullet_speed, player);
				bullet_vector.push_back(bullet);
				reload_timer += 10;
				bullet_firing = false;
			}
		}
		else
		{
			reload_timer--;
		}

		// Draw and move bullets
		for (long unsigned int i = 0; i < bullet_vector.size(); i++)
		{
			bullet_vector[i].drawTo(window);
			bullet_vector[i].moveBullet();
			bullet_vector[i].despawnBullet(bullet_dead, screen_width, screen_height);

			// If bullet_dead is true despawn the bullet
			if (bullet_dead)
			{
				bullet_vector.erase(bullet_vector.begin() + i);
				bullet_dead = false;
			}

			// if (asteroid_dead)
			// {
			// 	max_asteroids2--;
			// 	asteroid_vector2.erase(asteroid_vector2.begin() + i);
			// 	asteroid_dead = false;
			// }
		}

		player.setPlayerTexture();
		player.drawTo(window);
		player.movePlayer(player_speed, dt);
		player.rotatePlayer(player_rotation);
		player.screenWrapping(screen_width, screen_height);
		window.display();
	}
}
