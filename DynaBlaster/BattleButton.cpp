#include "BattleButton.h"

BattleButton::BattleButton()
{
	// Empty
}

BattleButton::BattleButton(std::string buttonText, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
{
	m_text.setString(buttonText);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(charSize);

	m_battleButton.setSize(size);
	m_battleButton.setFillColor(bgColor);
}

void BattleButton::SetFont(sf::Font& font)
{
	m_text.setFont(font);
}

void BattleButton::SetBgColor(sf::Color color)
{
	m_battleButton.setFillColor(color);
}

void BattleButton::SetPosition(sf::Vector2f position)
{
	m_battleButton.setPosition(position);
	float xPosition = (position.x + m_battleButton.getGlobalBounds().width / 4) - (m_text.getGlobalBounds().width / 2);
	float yPosition = (position.y + m_battleButton.getGlobalBounds().height / 4) - (m_text.getGlobalBounds().height / 2);
	m_text.setPosition({ xPosition, yPosition });
}

void BattleButton::DrawTo(sf::RenderWindow& window)
{
	window.draw(m_battleButton);
	window.draw(m_text);
}

bool BattleButton::IsMouseOver(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float buttonPosX = m_battleButton.getPosition().x;
	float buttonPosY = m_battleButton.getPosition().y;

	float buttonXPosWidth = m_battleButton.getPosition().x + m_battleButton.getLocalBounds().width;
	float buttonYPosHeight = m_battleButton.getPosition().y + m_battleButton.getLocalBounds().height;

	if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
		return true;
	return false;
}