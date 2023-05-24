#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
	Player(float& player_x, float& player_y, int player_width, int player_height);
	void setPlayerTexture();
	void drawTo(sf::RenderWindow& window);
	void movePlayer(float& player_speed, float dt);
	void rotatePlayer(float player_rotation);
	void screenWrapping(int screen_width, int screen_height);

private:
	sf::Texture moving_player_texture;
	sf::Texture player_texture;
	int texture_number;
	sf::Sprite player;

	sf::Vector2f velocity;
	sf::Vector2f direction;
};

#endif