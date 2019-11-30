#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class LevelsButton
{
public:
	LevelsButton();
	LevelsButton(std::string buttonText, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor);
	void SetFont(sf::Font& font);
	void SetBgColor(sf::Color color);
	void SetPosition(sf::Vector2f position);
	void DrawTo(sf::RenderWindow& window);
	bool IsMouseOver(sf::RenderWindow& window);

private:
	sf::RectangleShape m_levelsButton;
	sf::Text m_text;
};
