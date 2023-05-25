#include "bullet.hpp"

Bullet::Bullet(float bullet_width, float bullet_height, sf::Color white)
{
	bullet.setSize(sf::Vector2f(bullet_width, bullet_height));
	bullet.setFillColor(white);
}

void Bullet::setPos(Player& player)
{
	auto player_x = player.player.getPosition().x;
	auto player_y = player.player.getPosition().y;

	bullet.setPosition(sf::Vector2f(player_x, player_y));
}

void Bullet::drawTo(sf::RenderWindow& window)
{
	window.draw(bullet);
}

void Bullet::fireBullet(float& bullet_speed, Player& player)
{
	// Fire bullet in direction player is facing
	auto player_angle = player.player.getRotation() * (M_PI / 180);
	direction.x = bullet_speed * cos(player_angle);
	direction.y = bullet_speed * sin(player_angle);
}

void Bullet::moveBullet()
{
	bullet.move(direction);
}