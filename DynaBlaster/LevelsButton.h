#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class LevelsButton
{
public:
	LevelsButton() {}
	LevelsButton(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
	{
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);

		levelsButton.setSize(size);
		levelsButton.setFillColor(bgColor);
	}
	void SetFont(sf::Font& font)
	{
		text.setFont(font);
	}
	void SetBgColor(sf::Color color)
	{
		levelsButton.setFillColor(color);
	}
	void SetPosition(sf::Vector2f pos)
	{
		levelsButton.setPosition(pos);
		float xPos = (pos.x + levelsButton.getGlobalBounds().width / 4) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + levelsButton.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2);
		text.setPosition({ xPos, yPos });
	}
	void DrawTo(sf::RenderWindow& window)
	{
		window.draw(levelsButton);
		window.draw(text);
	}
	bool IsMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonPosX = levelsButton.getPosition().x;
		float buttonPosY = levelsButton.getPosition().y;

		float buttonXPosWidth = levelsButton.getPosition().x + levelsButton.getLocalBounds().width;
		float buttonYPosHeight = levelsButton.getPosition().y + levelsButton.getLocalBounds().height;

		if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
			return true;
		return false;
	}

private:
	sf::RectangleShape levelsButton;
	sf::Text text;
};
