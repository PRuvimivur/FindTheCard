#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	Game game(sf::Vector2u(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT), "Find the card");
	game.run();
	return 0;
}

