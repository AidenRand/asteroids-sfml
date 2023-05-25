#include "bullet.hpp"

Bullet::Bullet(float bullet_width, float bullet_height, sf::Color white)
{
	bullet.setSize(sf::Vector2f(bullet_width, bullet_height));
	bullet.setFillColor(white);
}