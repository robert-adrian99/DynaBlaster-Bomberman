#include "GrassRectengle.h"
#include <iostream>

GrassRectengle::GrassRectengle()
{
	if (!grassTexture.loadFromFile("Grass2.jpg", { 0 * 48, 0 * 48, 48 , 48 }))
		std::cout << "Error" << std::endl;
	
	m_grassRectangle.setSize({ 48,48 });
	m_grassRectangle.setTexture(&grassTexture);
}

void GrassRectengle::SetPosition(sf::Vector2f position)
{
	m_grassRectangle.setPosition(position);
}

sf::RectangleShape GrassRectengle::Draw()
{
	return m_grassRectangle;
}
