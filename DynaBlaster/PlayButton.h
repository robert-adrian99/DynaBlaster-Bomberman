#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class PlayButton
{
public:
	PlayButton() {}
	PlayButton(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
	{
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);

		playButton.setSize(size);
		playButton.setFillColor(bgColor);
	}
	void SetFont(sf::Font& font)
	{
		text.setFont(font);
	}
	void SetBgColor(sf::Color color)
	{
		playButton.setFillColor(color);
	}
	void SetPosition(sf::Vector2f pos)
	{
		playButton.setPosition(pos);
		float xPos = (pos.x + playButton.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + playButton.getGlobalBounds().height / 4) - (text.getGlobalBounds().height / 2);
		text.setPosition({ xPos, yPos });
	}
	void DrawTo(sf::RenderWindow& window)
	{
		window.draw(playButton);
		window.draw(text);
	}
	bool IsMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonPosX = playButton.getPosition().x;
		float buttonPosY = playButton.getPosition().y;

		float buttonXPosWidth = playButton.getPosition().x + playButton.getLocalBounds().width;
		float buttonYPosHeight = playButton.getPosition().y + playButton.getLocalBounds().height;

		if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
			return true;
		return false;
	}

private:
	sf::RectangleShape playButton;
	sf::Text text;
};