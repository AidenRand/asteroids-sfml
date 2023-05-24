#include "player.hpp"

Player::Player(float& player_x, float& player_y)
{
	player.setPosition(sf::Vector2f(player_x, player_y));
	player.setOrigin(player.getGlobalBounds().width / 2, player.getGlobalBounds().height / 2);
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