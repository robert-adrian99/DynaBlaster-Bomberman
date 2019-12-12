#include "HelpButton.h"

HelpButton::HelpButton()
{
	// Empty
}

HelpButton::HelpButton(const std::string& buttonText, const sf::Vector2f& size, const int charSize, const sf::Color& bgColor, const sf::Color& textColor)
{
	m_text.setString(buttonText);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(charSize);

	m_helpButton.setSize(size);
	m_helpButton.setFillColor(bgColor);
}

void HelpButton::SetFont(const sf::Font& font)
{
	m_text.setFont(font);
}

void HelpButton::SetBgColor(const sf::Color& color)
{
	m_helpButton.setFillColor(color);
}

void HelpButton::SetPosition(const sf::Vector2f& position)
{
	m_helpButton.setPosition(position);
	float xPos = (position.x + m_helpButton.getGlobalBounds().width / 3) - (m_text.getGlobalBounds().width / 2);
	float yPos = (position.y + m_helpButton.getGlobalBounds().height / 4) - (m_text.getGlobalBounds().height / 2);
	m_text.setPosition({ xPos, yPos });
}

void HelpButton::DrawTo(sf::RenderWindow& window)
{
	window.draw(m_helpButton);
	window.draw(m_text);
}

bool HelpButton::IsMouseOver(const sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float buttonPosX = m_helpButton.getPosition().x;
	float buttonPosY = m_helpButton.getPosition().y;

	float buttonXPosWidth = m_helpButton.getPosition().x + m_helpButton.getLocalBounds().width;
	float buttonYPosHeight = m_helpButton.getPosition().y + m_helpButton.getLocalBounds().height;

	if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
		return true;
	return false;
}