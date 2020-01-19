#include "Enemy.h"

int RandomGeneratorForMovement()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandom(0, 3);
	return rrandom(rng);
}

template <int numberOfLines=10,int numberOfColumns=12>
std::pair<int, int> RandomGeneratorForPosition()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rowRandom(1, numberOfLines);
	int randomLine = rowRandom(rng);
	std::uniform_int_distribution<std::mt19937::result_type> columnRandom(1, numberOfColumns);
	int randomColumn = columnRandom(rng);
	return std::make_pair(randomLine, randomColumn);
}

Enemy::Enemy(EnemyType enemyType, Map& map)
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	if (enemyType == EnemyType::Barom)
	{
		if (!m_enemyTexture.loadFromFile("Barom.png", { 0 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading BaromTexture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::Shashakin)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 1 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading Shashaking Texture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::Nagacham)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 2 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading Nagacham Texture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::Ojin)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 3 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading Ojin Texture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::Pontan)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 4 * 48, 0 * 48, 48 , 48 }))
		{ 
			logger.Log("Error loading Pontan Texture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::Boyon)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 5 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading Boyon Texture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::Telpio)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 6 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading Telpio Texture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::Parce)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 7 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading Parce Texture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::BigBoss)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 8 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading BigBoss Texture from file!", Logger::Level::Error);
		}
	}
	else if (enemyType == EnemyType::Arion)
	{
		if (!m_enemyTexture.loadFromFile("Enemy.png", { 9 * 48, 0 * 48, 48 , 48 }))
		{
			logger.Log("Error loading Arion Texture from file!", Logger::Level::Error);
		}
	}
	this->m_map = &map;
	m_rectangle.setTexture(&m_enemyTexture);
	m_rectangle.setSize({ 48,48 });
	std::vector<sf::Vector2f> rectPositions = this->m_map->GetIndestructibleWallVector();
	std::vector<sf::Vector2f> rectTempPositions = this->m_map->GetDestructibleWallVector();
	std::pair<int, int> randomPosition = RandomGeneratorForPosition();
	bool okPosition = true;
	do {
		okPosition = true;
		randomPosition = RandomGeneratorForPosition();
		for (const auto& rect : rectPositions)
		{
			if (rect.x == randomPosition.second * 48 && rect.y == randomPosition.first * 48 ||
				(rect.x == 48 && rect.y == 98) || (rect.x == 48 && rect.y == 146) || (rect.x == 96 && rect.y == 98))
			{
				okPosition = false;
				break;
			}
		}
		if (okPosition)
		{
			for (const auto& rect : rectTempPositions)
			{
				if (rect.x == randomPosition.second * 48 && rect.y == randomPosition.first * 48 ||
					(rect.x == 48 && rect.y == 48) || (rect.x == 48 && rect.y == 96) || (rect.x == 96 && rect.y == 48))
				{
					okPosition = false;
					break;
				}
			}
		}
	} while (okPosition == false);
	float posY = randomPosition.first * 48 + 50;
	float posX = randomPosition.second * 48;
	m_rectangle.setPosition({ posX,posY });
	m_movement = 0;
	m_lastPosition = m_rectangle.getPosition();
	m_currentPosition = m_rectangle.getPosition();
	m_allowToMove = false;
	m_active = true;
	m_enemyType = enemyType;
}

void Enemy::Move()
{
	const int enemyDimension = 42;
	float speed = 1.f;
	m_currentPosition = m_rectangle.getPosition();
	for (const auto& wallrect : m_map->GetIndestructibleWallVector())
	{
		if (m_rectangle.getPosition().x < wallrect.x + enemyDimension &&
			m_rectangle.getPosition().x + enemyDimension > wallrect.x&&
			m_rectangle.getPosition().y < wallrect.y + 50 + enemyDimension &&
			m_rectangle.getPosition().y + enemyDimension > wallrect.y + 50)
		{
			m_currentPosition = m_lastPosition;
			m_rectangle.setPosition(m_currentPosition);
			m_movement = RandomGeneratorForMovement();
			break;
		}
	}

	for (const auto& wallrect : m_map->GetDestructibleWallVector())
	{
		if (m_rectangle.getPosition().x < wallrect.x + enemyDimension &&
			m_rectangle.getPosition().x + enemyDimension > wallrect.x&&
			m_rectangle.getPosition().y < wallrect.y + enemyDimension + 50 &&
			m_rectangle.getPosition().y + enemyDimension > wallrect.y + 50)
		{
			m_currentPosition = m_lastPosition;
			m_rectangle.setPosition(m_currentPosition);
			m_movement = RandomGeneratorForMovement();
			break;
		}
	}
	
	for (const auto& wallrect : bombRect)
	{
		if (m_rectangle.getPosition().x < wallrect.x + enemyDimension &&
			m_rectangle.getPosition().x + enemyDimension > wallrect.x&&
			m_rectangle.getPosition().y < wallrect.y + enemyDimension + 50 &&
			m_rectangle.getPosition().y + enemyDimension > wallrect.y + 50 && m_allowToMove == false)
		{
			m_currentPosition = m_lastPosition;
			m_rectangle.setPosition(m_currentPosition);
			m_movement = RandomGeneratorForMovement();
			break;
		}

		if (!(m_rectangle.getPosition().x < wallrect.x + enemyDimension &&
			m_rectangle.getPosition().x + enemyDimension > wallrect.x&&
			m_rectangle.getPosition().y < wallrect.y + enemyDimension + 50 &&
			m_rectangle.getPosition().y + enemyDimension > wallrect.y + 50) && m_allowToMove == true)
		{
			m_allowToMove = false;
		}
	}

	switch (m_movement)
	{
	case 0:
	{
		m_lastPosition = m_rectangle.getPosition();
		m_rectangle.move(0, -speed);
	}
	break;
	case 1:

	{
		m_lastPosition = m_rectangle.getPosition();
		m_rectangle.move(0, speed);
	}
	break;
	case 2:

	{
		m_lastPosition = m_rectangle.getPosition();
		m_rectangle.move(speed, 0);
	}
	break;
	case 3:

	{
		m_lastPosition = m_rectangle.getPosition();
		m_rectangle.move(-speed, 0);
	}
	break;
	default:
		break;
	}
}

sf::Vector2f Enemy::GetPosition() const
{
	return m_rectangle.getPosition();
}

sf::RectangleShape Enemy::GetRectangle() const
{
	return m_rectangle;
}

void Enemy::Die()
{
	m_active = false;
	m_rectangle.setPosition({ 0,0 });
}

uint64_t Enemy::GetScore() const
{
	switch (m_enemyType)
	{
	case EnemyType::Barom:
		return 100;
	case EnemyType::Shashakin:
		return 400;
	case EnemyType::Nagacham:
		return 100;
	case EnemyType::Ojin:
		return 400;
	case EnemyType::Pontan:
		return 200;
	case EnemyType::Boyon:
		return 1000;
	case EnemyType::Telpio:
		return 1000;
	case EnemyType::Parce:
		return 2000;
	case EnemyType::BigBoss:
		return 20000;
	case EnemyType::Arion:
		return 20000;
	default:
		break;
	}
}

bool Enemy::IsActive() const
{
	return m_active;
}

bool Enemy::AllowToMove() const
{
	return m_allowToMove;
}

void Enemy::SetAllowToMove(bool allowToMove)
{
	m_allowToMove = allowToMove;
}

bool Enemy::Intersects(const sf::Vector2f& position)
{
	if (m_currentPosition.x < position.x + 32 &&
		m_currentPosition.x + 32 > position.x&&
		m_currentPosition.y < position.y + 32 &&
		m_currentPosition.y + 32 > position.y)
	{
		return true;
	}
	return false;
}
