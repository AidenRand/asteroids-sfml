#include "asteroids.hpp"

Asteroids::Asteroids(int asteroid_width, int asteroid_height)
{
	asteroid.setOrigin(asteroid_width / 2, asteroid_height / 2);

	if (!asteroid_texture_1.loadFromFile("content/asteroid1.png"))
	{
		std::cout << "ERROR: Cannot load asteroid_1 texture";
	}

	if (!asteroid_texture_2.loadFromFile("content/asteroid2.png"))
	{
		std::cout << "ERROR: Cannot load asteroid_2 texture";
	}

	if (!asteroid_texture_1.loadFromFile("content/asteroid3.png"))
	{
		std::cout << "ERROR: Cannot load asteroid_3 texture";
	}
}

void Asteroids::spawnAsteroids(int screen_width, int screen_height, int asteroid_height, int asteroid_width)
{
	random_corner = rand() % 4;

	if (random_corner == 0)
	{
		spawn_point.x = asteroid_width;
		spawn_point.y = asteroid_height;
	}
	else if (random_corner == 1)
	{
		spawn_point.x = screen_width - asteroid_width;
		spawn_point.y = asteroid_height;
	}
	else if (random_corner == 2)
	{
		spawn_point.x = screen_width - asteroid_width;
		spawn_point.y = screen_height - asteroid_height;
	}
	else if (random_corner == 3)
	{
		spawn_point.x = asteroid_width;
		spawn_point.y = screen_height - asteroid_width;
	}

	asteroid.setTexture(asteroid_texture_1);
	asteroid.setPosition(spawn_point);
}

void Asteroids::drawTo(sf::RenderWindow& window)
{
	window.draw(asteroid);
}

void Asteroids::chooseAsteroidDirection(int& asteroid_speed)
{
	random_angle = (rand() % 360) * M_PI;

	direction.x = asteroid_speed * cos(random_angle);
	direction.y = asteroid_speed * sin(random_angle);
}

void Asteroids::moveAsteroids()
{
	asteroid.move(direction);
}
