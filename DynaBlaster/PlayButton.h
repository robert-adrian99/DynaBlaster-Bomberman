#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class PlayButton
{
public:
	PlayButton();
	PlayButton(std::string buttonText, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor);
	std::string GetText() const;
	sf::Color GetTextColor() const;
	int GetTextCharacterSize() const;
	sf::Color GetPlayButtonBgColor() const;
	void SetFont(sf::Font& font);
	sf::Font GetTextFont() const;
	void SetBgColor(sf::Color color);
	sf::Color GetBgColor() const;
	void SetPosition(sf::Vector2f position);
	sf::Text GetPosition() const;
	void DrawTo(sf::RenderWindow& window);
	bool IsMouseOver(sf::RenderWindow& window);

private:
	sf::RectangleShape m_playButton;
	sf::Text m_text;
};