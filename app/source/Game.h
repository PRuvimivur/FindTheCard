#pragma once
#include<SFML/Graphics.hpp>
#include "BackGround.h"
#include "Card.h"
#include <stack>
class Game {
public:
	static const unsigned int WINDOW_WIDTH = 1280;
	static const unsigned int WINDOW_HEIGHT = 720;

	static const unsigned int CARD_ARRAY_LINES = 4;
	static const unsigned int CARD_ARRAY_ROWS = 3;

	static const unsigned int MAX_STEPS_NUMBERS = 15;
private:
	sf::RenderWindow* pWindow;
	sf::Vector2u      windowSize;
	BackGround*       pBackGround;
	Card*             cardArray[4][3] = {		
		{new Card(Card::ONE,sf::Vector2u(450,50)), new Card(Card::FOUR, sf::Vector2u(560,50)), new Card(Card::FIVE, sf::Vector2u(670,50))},
		{new Card(Card::THREE,sf::Vector2u(450,210)), new Card(Card::ZERO, sf::Vector2u(560,210)), new Card(Card::TWO, sf::Vector2u(670,210))},
		{new Card(Card::TWO,sf::Vector2u(450,370)), new Card(Card::ONE, sf::Vector2u(560,370)), new Card(Card::ZERO, sf::Vector2u(670,370))},
		{new Card(Card::FIVE,sf::Vector2u(450,530)), new Card(Card::FOUR, sf::Vector2u(560,530)), new Card(Card::THREE, sf::Vector2u(670,530))}
	};

	std::stack<Card*> lastClickedCardStack;

	unsigned int stepsNumbers;

public:
	Game(sf::Vector2u windowSize, const std::string GameName);
	~Game();
	void run();

private:
	void processEvents();
	void update(sf::Vector2i mousePosition);
	void render();

	void flipAllCards();
	void removeCards(Card::values enumValue);
};

