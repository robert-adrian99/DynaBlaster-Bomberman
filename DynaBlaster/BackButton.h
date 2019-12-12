#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class BackButton
{
public:
	BackButton();
	BackButton(const std::string& buttonText, const sf::Vector2f& size, const int charSize, const sf::Color& bgColor, const sf::Color& textColor);
	void SetFont(const sf::Font& font);
	void SetBgColor(const sf::Color& color);
	void SetPosition(const sf::Vector2f& position);
	void DrawTo(sf::RenderWindow& window);
	bool IsMouseOver(const sf::RenderWindow& window);

private:
	sf::RectangleShape m_backButton;
	sf::Text m_text;
};

