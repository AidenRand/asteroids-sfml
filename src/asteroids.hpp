#ifndef ASTEROIDS_HPP
#define ASTEROIDS_HPP

#include "bullet.hpp"
#include <SFML/Graphics.hpp>

class Asteroids
{
public:
	Asteroids(int asteroid_width, int asteroid_height);
	void chooseTexture();
	void spawnAsteroids(int screen_width, int screen_height, int asteroid_height, int asteroid_width);
	void drawTo(sf::RenderWindow& window);
	void chooseAsteroidDirection(float& asteroid_speed);
	void moveAsteroids();
	void screenWrapping(int screen_width, int screen_height);
	void collision(bool& asteroid_dead, bool& bullet_dead, std::vector<Bullet> bullet_vector);

private:
	sf::Sprite asteroid;
	sf::Texture asteroid_texture_1;
	sf::Texture asteroid_texture_2;
	sf::Texture asteroid_texture_3;
	int random_texture;

	sf::Vector2f direction;
	sf::Vector2f spawn_point;
	int random_corner;
	int random_angle;
};

#endif