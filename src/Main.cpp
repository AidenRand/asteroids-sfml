#include "game.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	int screen_width = 1024;
	int screen_height = 768;
	sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Asteroids");
	window.setFramerateLimit(60);

	gameFunction(window, screen_width, screen_height);
	return 0;
}