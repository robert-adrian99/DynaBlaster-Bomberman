#include "PlayerSFML.h"

PlayerSFML::PlayerSFML()
{
	if (!pTexture.loadFromFile("PlayerSFML.png", { 0 * 48, 0 * 48, 48 , 48 }))
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
	bottom = rect.getPosition().y + 48;
	right = rect.getPosition().x + 48;
	std::cout << "TLBR: " << " " << top << " " << left << " " << bottom << " " << right << "\n\n\n";
}

void PlayerSFML::Movement()
{
	float speed = 0.2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (rect.getPosition().y > 1 * 48)
		{
			source.y = Up;
			rect.move(0, -speed);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (rect.getPosition().y < 11 * 48)
		{
			source.y = Down;
			rect.move(0, speed);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (rect.getPosition().x < 13 * 48)
		{
			source.y = Right;
			rect.move(speed, 0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (rect.getPosition().x > 1 * 48)
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

