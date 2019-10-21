#include "Game.h"
#include <windows.h>

Game::Game(sf::Vector2u windowSize, const std::string GameName) {
	this->windowSize.x = windowSize.x;
	this->windowSize.y = windowSize.y;
	this->pWindow = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), GameName);
	this->pBackGround = new BackGround("../app/img/back.png");
	this->stepsNumbers = 0;
}

Game::~Game() { delete this->pWindow; }

void Game::run() {
	while (pWindow->isOpen()) {
		processEvents();		
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (this->pWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			this->pWindow->close();
		if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(*pWindow);
			update(mousePosition);
		}
	}
}

void Game::update(sf::Vector2i mousePosition) {
	for (int i = 0; i < Game::CARD_ARRAY_LINES; ++i) {
		for (int j = 0; j < Game::CARD_ARRAY_ROWS; ++j) {
			if (cardArray[i][j]->isVisible() == true && cardArray[i][j] ->getSprite()
																		->getGlobalBounds()
																		.contains(mousePosition.x, mousePosition.y)) {

				cardArray[i][j]->setState(Card::states::FRONT);

				if (lastClickedCardStack.empty()) {
					lastClickedCardStack.push(cardArray[i][j]);
					return;
				}

				if (lastClickedCardStack.top() != cardArray[i][j]) {
					Card::values lastCardValue = lastClickedCardStack.top()->getCardValue();
					lastClickedCardStack.pop();
					pWindow->draw(*cardArray[i][j]->getSprite());
					pWindow->display();
					Sleep(500);
					if (lastCardValue == cardArray[i][j]->getCardValue())
						removeCards(cardArray[i][j]->getCardValue());
					else
						flipAllCards();
					stepsNumbers++;					
				}
			}
		}
	}
}

void Game::render() {
	this->pWindow->display();
	this->pBackGround->draw(pWindow);	
	for (int i = 0; i < CARD_ARRAY_LINES; ++i) {
		for (int j = 0; j < CARD_ARRAY_ROWS; ++j) {
			cardArray[i][j]->draw(pWindow);
		}
	}
}

void Game::flipAllCards() {
	for (int i = 0; i < Game::CARD_ARRAY_LINES; ++i) {
		for (int j = 0; j < Game::CARD_ARRAY_ROWS; ++j) {
			cardArray[i][j]->setState(Card::states::BACK);
		}
	}
}

void Game::removeCards(Card::values enumValue) {
	for (int i = 0; i < Game::CARD_ARRAY_LINES; ++i) {
		for (int j = 0; j < Game::CARD_ARRAY_ROWS; ++j) {
			if (cardArray[i][j]->getCardValue() == enumValue)
				cardArray[i][j]->setVisible(false);					
		}
	}
}

