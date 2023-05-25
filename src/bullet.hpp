#ifndef BULLET_HPP
#define BULLET_HPP

class Bullet
{
public:
	Bullet(float bullet_width, float bullet_height, sf::Color white);

private:
	sf::RectangleShape bullet;
	sf::Vector2f direction;
};

#endif