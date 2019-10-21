#pragma once
#include <SFML/Graphics.hpp>
class BackGround {
private:
	sf::Sprite*    pSprite;
	sf::Texture*   pTexture;	
public:
	BackGround(const std::string imagePath);
	~BackGround();
	void draw(sf::RenderWindow* window);
};

