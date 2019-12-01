#include "PlayButton.h"

PlayButton::PlayButton()
{
	// Empty
}

PlayButton::PlayButton(std::string buttonText, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
{
	m_text.setString(buttonText);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(charSize);

	m_playButton.setSize(size);
	m_playButton.setFillColor(bgColor);
}

std::string PlayButton::GetText() const
{
	return m_text.getString;
}

sf::Color PlayButton::GetTextColor() const
{
	return m_text.getFillColor;
}

int PlayButton::GetTextCharacterSize() const
{
	return m_text.getCharacterSize;
}

sf::Color PlayButton::GetPlayButtonBgColor() const
{
	return m_playButton.getFillColor;
}
void PlayButton::SetFont(sf::Font& font)
{
	m_text.setFont(font);
}

sf::Font PlayButton::GetTextFont() const
{
	return m_text.getFont;
}
sf::Color PlayButton::GetBgColor() const
{
	return m_playButton.getFillColor;
}

sf::Text PlayButton::GetPosition() const
{
	return m_text.getPosition;
}

void PlayButton::SetBgColor(sf::Color color)
{
	m_playButton.setFillColor(color);
}

void PlayButton::SetPosition(sf::Vector2f position)
{
	m_playButton.setPosition(position);
	float xPos = (position.x + m_playButton.getGlobalBounds().width / 3) - (m_text.getGlobalBounds().width / 2);
	float yPos = (position.y + m_playButton.getGlobalBounds().height / 4) - (m_text.getGlobalBounds().height / 2);
	m_text.setPosition({ xPos, yPos });
}

void PlayButton::DrawTo(sf::RenderWindow& window)
{
	window.draw(m_playButton);
	window.draw(m_text);
}

bool PlayButton::IsMouseOver(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float buttonPosX = m_playButton.getPosition().x;
	float buttonPosY = m_playButton.getPosition().y;

	float buttonXPosWidth = m_playButton.getPosition().x + m_playButton.getLocalBounds().width;
	float buttonYPosHeight = m_playButton.getPosition().y + m_playButton.getLocalBounds().height;

	if (mouseX < buttonXPosWidth && mouseX > buttonPosX&& mouseY < buttonYPosHeight && mouseY > buttonPosY)
		return true;
	return false;
}