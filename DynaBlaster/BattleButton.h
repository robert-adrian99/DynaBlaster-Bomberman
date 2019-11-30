#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class BattleButton
{
public:
	BattleButton();
	BattleButton(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor);
	void SetFont(sf::Font& font);
	void SetBgColor(sf::Color color);
	void SetPosition(sf::Vector2f pos);
	void DrawTo(sf::RenderWindow& window);
	bool IsMouseOver(sf::RenderWindow& window);

private:
	sf::RectangleShape m_battleButton;
	sf::Text m_text;
};


