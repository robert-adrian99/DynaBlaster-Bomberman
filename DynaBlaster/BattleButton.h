#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class BattleButton
{
public:
	BattleButton();
	BattleButton(const std::string& t, const sf::Vector2f& size, const int charSize, const sf::Color& bgColor, const sf::Color& textColor);
	void SetFont(const sf::Font& font);
	void SetBgColor(const sf::Color& color);
	void SetPosition(const sf::Vector2f& pos);
	void DrawTo(sf::RenderWindow& window);
	bool IsMouseOver(const sf::RenderWindow& window);

private:
	sf::RectangleShape m_battleButton;
	sf::Text m_text;
};


