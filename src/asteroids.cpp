#include "asteroids.hpp"
#include "bullet.hpp"

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

	if (!asteroid_texture_3.loadFromFile("content/asteroid3.png"))
	{
		std::cout << "ERROR: Cannot load asteroid_3 texture";
	}
}

void Asteroids::chooseTexture()
{
	random_texture = rand() % 3;

	// Randomly choose asteroid texture
	if (random_texture == 0)
	{
		asteroid.setTexture(asteroid_texture_1);
	}
	else if (random_texture == 1)
	{
		asteroid.setTexture(asteroid_texture_2);
	}
	else if (random_texture == 2)
	{
		asteroid.setTexture(asteroid_texture_3);
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

void Asteroids::chooseAsteroidDirection()
{
	// Choose asteroid direction
	random_angle = (rand() % 360) * (M_PI / 180);
	asteroid_speed = (rand() % 200) + 1;

	direction.x = asteroid_speed * cos(random_angle);
	direction.y = asteroid_speed * sin(random_angle);
}

void Asteroids::moveAsteroids(float& dt)
{
	asteroid.move(direction * dt);
}

void Asteroids::screenWrapping(int screen_width, int screen_height)
{
	// If asteroid goes beyond window border, move to other side
	if (asteroid.getPosition().x > screen_width)
	{
		asteroid.setPosition(0, asteroid.getPosition().y);
	}
	else if (asteroid.getPosition().x < 0)
	{
		asteroid.setPosition(screen_width, asteroid.getPosition().y);
	}

	if (asteroid.getPosition().y > screen_height)
	{
		asteroid.setPosition(asteroid.getPosition().x, 0);
	}
	else if (asteroid.getPosition().y < 0)
	{
		asteroid.setPosition(asteroid.getPosition().x, screen_height);
	}
}

void Asteroids::collision(bool& asteroid_dead, bool& bullet_dead, float& asteroid_scale, std::vector<Bullet> bullet_vector, bool& level_2, float& asteroid_posx, float& asteroid_posy)
{
	for (unsigned int i = 0; i < bullet_vector.size(); i++)
	{
		auto bullet = bullet_vector[i].bullet;

		// If current bullet collides with asteroid,
		// set asteroid_dead and bullet_dead to true
		if (bullet.getGlobalBounds().intersects(asteroid.getGlobalBounds()))
		{
			asteroid_dead = true;
			bullet_dead = true;
			asteroid.setScale(asteroid_scale, asteroid_scale);
			level_2 = true;
			asteroid_posx = asteroid.getPosition().x;
			asteroid_posy = asteroid.getPosition().y;
		}
	}
}

void Asteroids::spawn_new(bool& level_2, float& asteroid_posx, float& asteroid_posy)
{
	if (level_2)
	{
		asteroid.setPosition(asteroid_posx, asteroid_posy);
	}
	std::cout << asteroid_posx << "\n";
}