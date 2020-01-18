#include "Player.h"
#include "Enemy.h"

Player::Player()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	if (!m_playerTexture.loadFromFile("TestFront.png", { 0 * 48, 0 * 48, 48 , 48 }))
	{
		logger.Log("Error loading Player Texture from file!", Logger::Level::Error);
	}
	m_rectangle.setTexture(&m_playerTexture);
	m_rectangle.setSize({ 48,48 });
	m_rectangle.setPosition({ 48,98 });
	m_allowToMove = false;
	m_active = true;
	m_lives = 3;
	m_bombExplosionRange = 2;
}

void Player::Move()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	float speed = 2.f;
	m_currentPosition = m_rectangle.getPosition();

	for (const auto& wallrect : m_map->GetIndestructibleWallVector())
	{
		if (m_rectangle.getPosition().x < wallrect.x + 42 &&
			m_rectangle.getPosition().x + 42 > wallrect.x&&
			m_rectangle.getPosition().y < wallrect.y + 92 &&
			m_rectangle.getPosition().y + 42 > wallrect.y + 50)
		{
			m_currentPosition = m_lastPosition;
			m_rectangle.setPosition(m_currentPosition);
			break;
		}
	}
	for (const auto& wallrect : m_map->GetDestructibleWallVector())
	{
		if (m_rectangle.getPosition().x < wallrect.x + 42 &&
			m_rectangle.getPosition().x + 42 > wallrect.x&&
			m_rectangle.getPosition().y < wallrect.y + 92 &&
			m_rectangle.getPosition().y + 42 > wallrect.y + 50)
		{
			m_currentPosition = m_lastPosition;
			m_rectangle.setPosition(m_currentPosition);
			break;
		}
	}
	for (const auto& bombrect : bombRect)
	{
		if (m_rectangle.getPosition().x < bombrect.x + 42 &&
			m_rectangle.getPosition().x + 42 > bombrect.x&&
			m_rectangle.getPosition().y < bombrect.y + 92 &&
			m_rectangle.getPosition().y + 42 > bombrect.y + 50 && m_allowToMove == false)
		{
			m_currentPosition = m_lastPosition;
			m_rectangle.setPosition(m_currentPosition);
			break;
		}

		if (!(m_rectangle.getPosition().x < bombrect.x + 42 &&
			m_rectangle.getPosition().x + 42 > bombrect.x&&
			m_rectangle.getPosition().y < bombrect.y + 92 &&
			m_rectangle.getPosition().y + 42 > bombrect.y + 50) && m_allowToMove == true)
		{
			m_allowToMove = false;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!m_playerTexture.loadFromFile("TestBack.png", { 0 * 48 , 0 * 48, 48, 48 }))
		{
			logger.Log("Error loading Player Texture from file!", Logger::Level::Error);
		}
		m_rectangle.setTexture(&m_playerTexture);
		m_lastPosition = m_rectangle.getPosition();
		m_rectangle.move(0, -speed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (!m_playerTexture.loadFromFile("TestFront.png", { 0 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading Player Texture from file!", Logger::Level::Error);
		}
		m_rectangle.setTexture(&m_playerTexture);
		m_lastPosition = m_rectangle.getPosition();
		m_rectangle.move(0, speed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!m_playerTexture.loadFromFile("TestRight.png", { 0 * 48 , 0 * 48, 48, 48 }))
		{
			logger.Log("Error loading Player Texture from file!", Logger::Level::Error);
		}
		m_rectangle.setTexture(&m_playerTexture);
		m_lastPosition = m_rectangle.getPosition();
		m_rectangle.move(speed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!m_playerTexture.loadFromFile("TestLeft.png", { 0 * 48 , 0 * 48, 48, 48 }))
		{
			logger.Log("Error loading Player Texture from file!", Logger::Level::Error);
		}
		m_rectangle.setTexture(&m_playerTexture);
		m_lastPosition = m_rectangle.getPosition();
		m_rectangle.move(-speed, 0);
	}
}

sf::Vector2f Player::GetPosition() const
{
	return m_rectangle.getPosition();
}


void Player::SetMap(Map& map)
{
	this->m_map = &map;
}

void Player::SetBombRect(const sf::Vector2f& position)
{
	bombRect.emplace_back(position);
}

void Player::SetPosition(const sf::Vector2f& position)
{
	m_rectangle.setPosition(position);
}

void Player::Die()
{
	if (m_lives > 0)
	{
		--m_lives;
	}
	if (m_lives == 0)
	{
		m_active = false;
		m_rectangle.setPosition({ 0,0 });
	}
}

bool Player::GetActive() const
{
	return m_active;
}

uint16_t Player::GetLives() const
{
	return m_lives;
}

bool Player::AllowToMove() const
{
	return m_allowToMove;
}

void Player::SetAllowToMove(bool allowToMove)
{
	m_allowToMove = allowToMove;
}

void Player::SetLives(uint16_t lives)
{
	m_lives = lives;
}

bool Player::Intersects(const sf::Vector2f& position)
{
	if (m_currentPosition.x < position.x + 24 &&
		m_currentPosition.x + 24 > position.x&&
		m_currentPosition.y < position.y + 24 &&
		m_currentPosition.y + 24 > position.y)
	{
		return true;
	}
	return false;
}
void Player::IncreaseBombExplosionRange()
{
	++m_bombExplosionRange;
}
uint16_t Player::GetBombExplosionRange() const
{
	return m_bombExplosionRange;
}