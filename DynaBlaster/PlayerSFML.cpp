#include "PlayerSFML.h"

PlayerSFML::PlayerSFML()
{
	if (!playerTexture.loadFromFile("TestFront.png", { 0 * 48, 0 * 48, 48 , 48 }))
		std::cout << "Error" << std::endl;
	player.setTexture(&playerTexture);
	player.setSize({ 48,48 });
	player.setPosition({ 48,98 });
	map.Map();
	map.setPosition(0.0f, 50.0f);
}

void PlayerSFML::Move()
{
	float speed = 0.2;
	currentPosition = player.getPosition();

	for (const auto& wallrect : map.GetRectVec())
	{
		if (player.getPosition().x < wallrect.x + 42 &&
			player.getPosition().x + 42 > wallrect.x&&
			player.getPosition().y < wallrect.y + 92 &&
			player.getPosition().y + 42 > wallrect.y + 50)
		{
			currentPosition = lastPosition;
			player.setPosition(currentPosition);
			break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!playerTexture.loadFromFile("TestBack.png", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		player.setTexture(&playerTexture);
		lastPosition = player.getPosition();
		player.move(0, -speed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (!playerTexture.loadFromFile("TestFront.png", { 0 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
		player.setTexture(&playerTexture);
		lastPosition = player.getPosition();
		player.move(0, speed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!playerTexture.loadFromFile("TestRight.png", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		player.setTexture(&playerTexture);
		lastPosition = player.getPosition();
		player.move(speed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!playerTexture.loadFromFile("TestLeft.png", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		player.setTexture(&playerTexture);
		lastPosition = player.getPosition();
		player.move(-speed, 0);
	}
}

sf::Vector2f PlayerSFML::GetPosition()
{
	return player.getPosition();
}

