#include "BackGround.h"

BackGround::BackGround(const std::string imagePath) {
	this->pSprite = new sf::Sprite();
	this->pTexture = new sf::Texture();
	pTexture->loadFromFile(imagePath);
	pSprite->setTexture(*pTexture);
}

BackGround::~BackGround() {
	delete this->pSprite;
	delete this->pTexture;
}

void BackGround::draw(sf::RenderWindow* window) {
	window->draw(*pSprite);
}

