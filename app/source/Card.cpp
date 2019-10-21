#include "Card.h"

Card::Card(enum values cardValue, sf::Vector2u position) {
	this->enumCardValue = cardValue;
	this->position.x = position.x;
	this->position.y = position.y;
	this->isCardVisible = true;

	pSpriteFront = new sf::Sprite();
	pTextureFront = new sf::Texture();
	switch (cardValue) {
	case ZERO:
		pTextureFront->loadFromFile("../app/img/zero.png");
		break;
	case ONE:
		pTextureFront->loadFromFile("../app/img/one.png");
		break;
	case TWO:
		pTextureFront->loadFromFile("../app/img/two.png");
		break;
	case THREE:
		pTextureFront->loadFromFile("../app/img/three.png");
		break;
	case FOUR:
		pTextureFront->loadFromFile("../app/img/four.png");
		break;
	case FIVE:
		pTextureFront->loadFromFile("../app/img/five.png");
		break;
	}
	pSpriteFront->setTexture(*pTextureFront);
	pSpriteFront->setPosition(position.x, position.y);

	pSpriteBack = new sf::Sprite();
	pTextureBack = new sf::Texture();
	pTextureBack->loadFromFile("../app/img/shirt.png");
	pSpriteBack->setTexture(*pTextureBack);
	pSpriteBack->setPosition(position.x, position.y);
	enumState = BACK;
}

Card::~Card() {
	delete this->pSpriteFront;
	delete this->pSpriteBack;
	delete this->pTextureFront;
	delete this->pTextureBack;
}

sf::Sprite* Card::getSprite() {
	switch (enumState) {
	case BACK:
		return this->pSpriteBack;
		break;
	case FRONT:
		return this->pSpriteFront;
		break;
	}
}
	
void Card::setState(states state) {
	this->enumState = state;
}

Card::values Card::getCardValue() {
	return this->enumCardValue;
}

Card::states Card::getState() {
	return this->enumState;
}

void Card::draw(sf::RenderWindow* pWindow) {
	if (isCardVisible) {
		switch (enumState) {
		case BACK:
			pWindow->draw(*pSpriteBack);
			break;
		case FRONT:
			pWindow->draw(*pSpriteFront);
			break;
		}
	}
}

bool Card::isVisible() { return isCardVisible; }

void Card::setVisible(bool isVisible) {
	this->isCardVisible = isVisible;
}

