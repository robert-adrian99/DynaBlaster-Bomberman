#include "PlayerSFML.h"

PlayerSFML::PlayerSFML()
{
	if (!playerTexture.loadFromFile("TestFront.png", { 0 * 48, 0 * 48, 48 , 48 }))
		std::cout << "Error" << std::endl;
	player.setTexture(&playerTexture);
	player.setSize({ 48,48 });
	player.setPosition({ 48,98 });
	allowToMove = false;
	m_active = true;
	m_lives = 3;
}

void PlayerSFML::Move()
{
	float speed = 0.5;
	currentPosition = player.getPosition();

	for (const auto& wallrect : map->GetRectVec())
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
	for (const auto& wallrect : map->GetRectVecTemporar())
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
	for (const auto& bombrect : bombRect)
	{
		if (player.getPosition().x < bombrect.x + 42 &&
			player.getPosition().x + 42 > bombrect.x&&
			player.getPosition().y < bombrect.y + 92 &&
			player.getPosition().y + 42 > bombrect.y + 50 && allowToMove == false)
		{
			currentPosition = lastPosition;
			player.setPosition(currentPosition);
			break;
		}

		if (!(player.getPosition().x < bombrect.x + 42 &&
			player.getPosition().x + 42 > bombrect.x&&
			player.getPosition().y < bombrect.y + 92 &&
			player.getPosition().y + 42 > bombrect.y + 50) && allowToMove == true)
		{
			allowToMove = false;
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


void PlayerSFML::SetMap(TileMap& map)
{
	this->map = &map;
}

void PlayerSFML::SetBombRect(const sf::Vector2f& position)
{
	bombRect.emplace_back(position);
}

void PlayerSFML::PlayerDie()
{
	if (m_lives > 0)
	{
		--m_lives;
	}
	if (m_lives == 0)
	{
		m_active = false;
		player.setPosition({ 0,0 });
	}
}

bool PlayerSFML::GetActive() const
{
	return m_active;
}

int PlayerSFML::GetLives() const
{
	return m_lives;
}

void PlayerSFML::SetLives(int lives)
{
	m_lives = lives;
}

bool PlayerSFML::Intersects(sf::Vector2f position)
{
	if (currentPosition.x < position.x + 48 &&
		currentPosition.x + 48 > position.x&&
		currentPosition.y < position.y + 48 &&
		currentPosition.y + 48 > position.y)
	{
		return true;
	}
	return false;
}
