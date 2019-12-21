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
	rect.setOutlineColor(sf::Color::Transparent);
	rect.setOutlineThickness(1.0f);
	top = rect.getPosition().y;
	left = rect.getPosition().x;
	bottom = rect.getPosition().y + 48;
	right = rect.getPosition().x + 48;
	std::cout << "TLBR: " << " " << top << " " << left << " " << bottom << " " << right << "\n\n\n";
	map.Map();
}

void PlayerSFML::Movement()
{
	float speed = 0.2;
	currentPosition = rect.getPosition();

	for (const auto& wallrect : map.GetRectVec())
	{
		if (rect.getPosition().x < wallrect.x + 42 &&
			rect.getPosition().x + 42 > wallrect.x&&
			rect.getPosition().y < wallrect.y + 42 &&
			rect.getPosition().y + 42 > wallrect.y)
		{
			currentPosition = lastPosition;
			rect.setPosition(currentPosition);
			break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!pTexture.loadFromFile("TestBack.png", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		playerImage.setTexture(pTexture);
		rect.setTexture(playerImage.getTexture());
		if (rect.getPosition().y > 1 * 48)
		{
			lastPosition = rect.getPosition();
			source.y = Up;
			rect.move(0, -speed);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (!pTexture.loadFromFile("PlayerSFML.png", { 0 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
		playerImage.setTexture(pTexture);
		rect.setTexture(playerImage.getTexture());
		if (rect.getPosition().y < 11 * 48)
		{
			lastPosition = rect.getPosition();
			source.y = Down;
			rect.move(0, speed);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!pTexture.loadFromFile("TestRight.png", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		playerImage.setTexture(pTexture);
		rect.setTexture(playerImage.getTexture());
		if (rect.getPosition().x < 13 * 48)
		{
			lastPosition = rect.getPosition();
			source.y = Right;
			rect.move(speed, 0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!pTexture.loadFromFile("TestLeft.png", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		playerImage.setTexture(pTexture);
		rect.setTexture(playerImage.getTexture());
		if (rect.getPosition().x > 1 * 48)
		{
			lastPosition = rect.getPosition();
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

sf::Vector2f PlayerSFML::GetPosition()
{
	return rect.getPosition();
}

