#pragma once
#include <SFML/Graphics.hpp>
class GrassRectengle
{
public:
	GrassRectengle();
	void SetPosition(sf::Vector2f position);
	sf::RectangleShape Draw();

private:
	sf::RectangleShape m_grassRectangle;
	sf::Texture grassTexture;
};

