#ifndef ASTEROIDS_HPP
#define ASTEROIDS_HPP

#include <SFML/Graphics.hpp>

class Asteroids
{
public:
	Asteroids(int asteroid_width, int asteroid_height);
	void spawnAsteroids(int screen_width, int screen_height, int asteroid_height, int asteroid_width);
	void drawTo(sf::RenderWindow& window);
	void chooseAsteroidDirection(int& asteroid_speed);
	void moveAsteroids();
	void screenWrapping(int screen_width, int screen_height);

private:
	sf::Sprite asteroid;
	sf::Texture asteroid_texture_1;
	sf::Texture asteroid_texture_2;
	sf::Texture asteroid_texture_3;

	sf::Vector2f direction;
	sf::Vector2f spawn_point;
	int random_corner;
	int random_angle;
};

#endif