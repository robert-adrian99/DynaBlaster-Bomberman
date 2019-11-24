#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class BattleButton
{
public:
	BattleButton() {}
	BattleButton(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
	{
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);

		battleButton.setSize(size);
		battleButton.setFillColor(bgColor);
	}
	void SetFont(sf::Font& font)
	{
		text.setFont(font);
	}
	void SetBgColor(sf::Color color)
	{
		battleButton.setFillColor(color);
	}
	void SetPosition(sf::Vector2f pos)
	{
		battleButton.setPosition(pos);
		float xPos = (pos.x + battleButton.getGlobalBounds().width / 4) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + battleButton.getGlobalBounds().height / 4) - (text.getGlobalBounds().height / 2);
		text.setPosition({ xPos, yPos });
	}
	void DrawTo(sf::RenderWindow& window)
	{
		window.draw(battleButton);
		window.draw(text);
	}
	bool IsMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonPosX = battleButton.getPosition().x;
		float buttonPosY = battleButton.getPosition().y;

		float buttonXPosWidth = battleButton.getPosition().x + battleButton.getLocalBounds().width;
		float buttonYPosHeight = battleButton.getPosition().y + battleButton.getLocalBounds().height;

		if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
			return true;
		return false;
	}

private:
	sf::RectangleShape battleButton;
	sf::Text text;
};


