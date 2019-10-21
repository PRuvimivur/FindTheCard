#pragma once
#include"SFML/Graphics.hpp"
class Card {
public:
	static const enum values {ZERO,ONE,TWO,THREE,FOUR,FIVE};
	static const enum states{FRONT, BACK};
private:
	sf::Sprite*   pSpriteFront;
	sf::Texture*  pTextureFront;

	sf::Sprite*   pSpriteBack;	
	sf::Texture*  pTextureBack;

	sf::Vector2u  position;

	values enumCardValue;
	states enumState;

	bool isCardVisible;
	
public:
	Card(enum values cardValue,sf::Vector2u position);
	~Card();

	sf::Sprite* getSprite();
	void setState(enum states state);
	enum values getCardValue();
	enum states getState();
	void draw(sf::RenderWindow* pWindow);
	bool isVisible();
	void setVisible(bool isVisible);
};

