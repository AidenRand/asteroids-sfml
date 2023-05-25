#ifndef BULLET_HPP
#define BULLET_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float bullet_width, float bullet_height, sf::Color white);
	void setPos(Player& player);
	void drawTo(sf::RenderWindow& window);
	void fireBullet(float& bullet_speed, Player& player);
	void moveBullet();
	void despawnBullet(bool& bullet_dead, int screen_width, int screen_height);

private:
	sf::RectangleShape bullet;
	sf::Vector2f direction;
};

#endif