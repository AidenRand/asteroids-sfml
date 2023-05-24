#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
	Player(float player_x, float player_y, float player_speed);

private:
	sf::Texture moving_player_texture;
	sf::Texture player_texture;
	sf::Sprite player;
};

#endif