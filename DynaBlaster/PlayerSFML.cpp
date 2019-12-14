#include "PlayerSFML.h"

PlayerSFML::PlayerSFML()
{
	if (!pTexture.loadFromFile("TestPlayer.png", { 1 * 64,10 * 64,64,64 }))
		std::cout << "Error" << std::endl;
	playerImage.setTexture(pTexture);
	rect.setTexture(playerImage.getTexture());
	rect.setSize({ 48,48 });
	rect.setPosition({ 48,48 });
	rect.setFillColor(sf::Color::White);
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1.0f);
	rect.setScale({ 0.8,0.8 });
	top = rect.getPosition().y;
	left = rect.getPosition().x;
	bottom = rect.getPosition().y + 64;
	right = rect.getPosition().x + 64;
	std::cout << "TLBR: " << " " << top << " " << left << " " << bottom << " " << right << "\n\n\n";
}

void PlayerSFML::Movement()
{
	float speed = 0.2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (rect.getPosition().y > 1 * 32)
		{
			source.y = Up;
			rect.move(0, -speed);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (rect.getPosition().y < 11 * 32)
		{
			source.y = Down;
			rect.move(0, speed);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (rect.getPosition().x < 13 * 32)
		{
			source.y = Right;
			rect.move(speed, 0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (rect.getPosition().x > 1 * 32)
		{
			source.y = Left;
			rect.move(-speed, 0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		std::cout << "TLBR: " << " " << top << " " << left << " " << bottom << " " << right << "\n\n\n";

	}
}

void PlayerSFML::Update()
{
	top = rect.getPosition().y;
	left = rect.getPosition().x;
	bottom = rect.getPosition().y + rect.getScale().y * rect.getSize().y;
	right = rect.getPosition().x + rect.getScale().x * rect.getSize().x;
}

