#include "LevelsButton.h"

LevelsButton::LevelsButton()
{
	// Empty
}

LevelsButton::LevelsButton(const std::string& buttonText, const  sf::Vector2f& size, const int charSize, const  sf::Color& bgColor, const sf::Color& textColor)
{
	m_text.setString(buttonText);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(charSize);

	m_levelsButton.setSize(size);
	m_levelsButton.setFillColor(bgColor);
}

void LevelsButton::SetFont(const sf::Font& font)
{
	m_text.setFont(font);
}

void LevelsButton::SetBgColor(const sf::Color& color)
{
	m_levelsButton.setFillColor(color);
}

void LevelsButton::SetPosition(const sf::Vector2f& position)
{
	m_levelsButton.setPosition(position);
	float xPos = (position.x + m_levelsButton.getGlobalBounds().width / 4) - (m_text.getGlobalBounds().width / 2);
	float yPos = (position.y + m_levelsButton.getGlobalBounds().height / 3) - (m_text.getGlobalBounds().height / 2);
	m_text.setPosition({ xPos, yPos });
}

void LevelsButton::DrawTo(sf::RenderWindow& window)
{
	window.draw(m_levelsButton);
	window.draw(m_text);
}

bool LevelsButton::IsMouseOver(const sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float buttonPosX = m_levelsButton.getPosition().x;
	float buttonPosY = m_levelsButton.getPosition().y;

	float buttonXPosWidth = m_levelsButton.getPosition().x + m_levelsButton.getLocalBounds().width;
	float buttonYPosHeight = m_levelsButton.getPosition().y + m_levelsButton.getLocalBounds().height;

	if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
		return true;
	return false;
}