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

	if (!moving_player_texture.loadFromFile("content/moving_player.png"))
	{
		std::cout << "ERROR: moving player texture could not be loaded" << std::endl;
	}

	// Make playe texture flicker when W is pressed
	player.setTexture(player_texture);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		texture_number += 10;
		if (texture_number % 7 == 0)
		{
			player.setTexture(moving_player_texture);
		}
	}
	else
	{
		texture_number = 0;
	}
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::movePlayer(float& player_speed, float dt)
{
	float player_angle = player.getRotation() * (M_PI / 180);

	// Accelerate player W is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		while (velocity.y <= 10.0f)
		{
			velocity.x += player_speed;
			velocity.y += player_speed;
		}

		velocity = 0.3f * velocity;
		direction.x += velocity.x * cos(player_angle);
		direction.y += velocity.y * sin(player_angle);
	}
	else
	{
		// Decelerate player when W is released
		if (velocity.y <= 0.3f)
		{
			velocity.y = 0;
		}
		if (velocity.x <= 0.3f)
		{
			velocity.x = 0;
		}
	}

	player.move(direction * dt);
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

void Player::screenWrapping(int screen_width, int screen_height)
{
	// If player goes beyond window border, move to other side
	if (player.getPosition().x > screen_width)
	{
		player.setPosition(0, player.getPosition().y);
	}
	else if (player.getPosition().x < 0)
	{
		player.setPosition(screen_width, player.getPosition().y);
	}

	if (player.getPosition().y > screen_height)
	{
		player.setPosition(player.getPosition().x, 0);
	}
	else if (player.getPosition().y < 0)
	{
		player.setPosition(player.getPosition().x, screen_height);
	}
}