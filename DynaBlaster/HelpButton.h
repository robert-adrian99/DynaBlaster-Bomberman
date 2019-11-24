#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class HelpButton
{
public:
	HelpButton() {}
	HelpButton(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
	{
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);

		helpButton.setSize(size);
		helpButton.setFillColor(bgColor);
	}
	void SetFont(sf::Font& font)
	{
		text.setFont(font);
	}
	void SetBgColor(sf::Color color)
	{
		helpButton.setFillColor(color);
	}
	void SetPosition(sf::Vector2f pos)
	{
		helpButton.setPosition(pos);
		float xPos = (pos.x + helpButton.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + helpButton.getGlobalBounds().height / 4) - (text.getGlobalBounds().height / 2);
		text.setPosition({ xPos, yPos });
	}
	void DrawTo(sf::RenderWindow& window)
	{
		window.draw(helpButton);
		window.draw(text);
	}
	bool IsMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonPosX = helpButton.getPosition().x;
		float buttonPosY = helpButton.getPosition().y;

		float buttonXPosWidth = helpButton.getPosition().x + helpButton.getLocalBounds().width;
		float buttonYPosHeight = helpButton.getPosition().y + helpButton.getLocalBounds().height;

		if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
			return true;
		return false;
	}

private:
	sf::RectangleShape helpButton;
	sf::Text text;
};

