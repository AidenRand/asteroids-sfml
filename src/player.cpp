#include "player.hpp"

Player::Player(float& player_x, float& player_y, int player_width, int player_height)
{
	player.setPosition(sf::Vector2f(player_x, player_y));
	player.setOrigin(player_width / 2, player_height / 2);
}

void Player::setPlayerTexture()
{
	// load player textures
	if (!player_texture.loadFromFile("content/player.png"))
	{
		std::cout << "ERROR: player texture could not be loaded" << std::endl;
	}
	player.setTexture(player_texture);

	if (!moving_player_texture.loadFromFile("content/moving_player.png"))
	{
		std::cout << "ERROR: moving player texture could not be loaded" << std::endl;
	}
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::movePlayer(float& player_speed)
{
	float player_angle = player.getRotation() * (M_PI / 180);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		// Accelerate player
		while (velocity.y <= 1.0f)
		{
			velocity.x += player_speed;
			velocity.y += player_speed;
		}

		velocity = 0.09f * velocity;
		direction.x += velocity.x * cos(player_angle);
		direction.y += velocity.y * sin(player_angle);
	}
	else
	{
		// Decelerate player
		if (velocity.y <= 0.3f)
		{
			velocity.y = 0;
		}
		if (velocity.x <= 0.3f)
		{
			velocity.x = 0;
		}
	}

	player.move(direction);
}

void Player::rotatePlayer(float player_rotation)
{
	// Rotate player in direction of button pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.rotate(-player_rotation);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.rotate(player_rotation);
	}
}