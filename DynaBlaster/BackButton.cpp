#include "BackButton.h"

BackButton::BackButton()
{
	// Empty
}

BackButton::BackButton(std::string buttonText, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
{
	m_text.setString(buttonText);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(charSize);

	m_backButton.setSize(size);
	m_backButton.setFillColor(bgColor);
}

void BackButton::SetFont(sf::Font& font)
{
	m_text.setFont(font);
}

void BackButton::SetBgColor(sf::Color color)
{
	m_backButton.setFillColor(color);
}

void BackButton::SetPosition(sf::Vector2f position)
{
	m_backButton.setPosition(position);
	float xPosition = (position.x + m_backButton.getGlobalBounds().width / 4) - (m_text.getGlobalBounds().width / 2);
	float yPosition = (position.y + m_backButton.getGlobalBounds().height / 4) - (m_text.getGlobalBounds().height / 2);
	m_text.setPosition({ xPosition, yPosition });
}

void BackButton::DrawTo(sf::RenderWindow& window)
{
	window.draw(m_backButton);
	window.draw(m_text);
}

bool BackButton::IsMouseOver(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float buttonPosX = m_backButton.getPosition().x;
	float buttonPosY = m_backButton.getPosition().y;

	float buttonXPosWidth = m_backButton.getPosition().x + m_backButton.getLocalBounds().width;
	float buttonYPosHeight = m_backButton.getPosition().y + m_backButton.getLocalBounds().height;

	if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
		return true;
	return false;
}