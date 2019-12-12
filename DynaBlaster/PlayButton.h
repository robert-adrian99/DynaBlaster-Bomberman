#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class PlayButton
{
public:
	PlayButton();
	PlayButton(const std::string& buttonText, const sf::Vector2f& size, const int charSize, const sf::Color& bgColor, const sf::Color& textColor);
	std::string GetText() const;
	sf::Color GetTextColor() const;
	int GetTextCharacterSize() const;
	sf::Color GetPlayButtonBgColor() const;
	void SetFont(const sf::Font& font);
	sf::Font GetTextFont() const;
	void SetBgColor(const sf::Color& color);
	sf::Color GetBgColor() const;
	void SetPosition(const sf::Vector2f& position);
	sf::Text GetPosition() const;
	void DrawTo(sf::RenderWindow& window);
	bool IsMouseOver(const sf::RenderWindow& window);

private:
	sf::RectangleShape m_playButton;
	sf::Text m_text;
};