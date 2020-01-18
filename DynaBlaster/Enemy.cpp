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
	if (enemyType == EnemyType::Barom)
	{
		if (!enemyTexture.loadFromFile("Barom.png", { 0 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Shashakin)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 1 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Nagacham)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 2 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Ojin)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 3 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Pontan)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 4 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Boyon)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 5 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Telpio)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 6 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Parce)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 7 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::BigBoss)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 8 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Arion)
	{
		if (!enemyTexture.loadFromFile("Enemy.png", { 9 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	this->map = &map;
	enemy.setTexture(&enemyTexture);
	enemy.setSize({ 48,48 });
	std::vector<sf::Vector2f> rectPositions = this->map->GetRectVec();
	std::vector<sf::Vector2f> rectTempPositions = this->map->GetRectVecTemporar();
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
	enemy.setPosition({ posX,posY });
	m_movement = 0;
	lastPosition = enemy.getPosition();
	currentPosition = enemy.getPosition();
	allowToMove = false;
}

const int enemyDimension = 42;

void Enemy::Movement()
{
	float speed = 0.3;
	currentPosition = enemy.getPosition();
	for (const auto& wallrect : map->GetRectVec())
	{
		if (enemy.getPosition().x < wallrect.x + enemyDimension &&
			enemy.getPosition().x + enemyDimension > wallrect.x&&
			enemy.getPosition().y < wallrect.y + 50 + enemyDimension &&
			enemy.getPosition().y + enemyDimension > wallrect.y + 50)
		{
			currentPosition = lastPosition;
			enemy.setPosition(currentPosition);
			m_movement = RandomGeneratorForMovement();
			break;
		}
	}

	for (const auto& wallrect : map->GetRectVecTemporar())
	{
		if (enemy.getPosition().x < wallrect.x + enemyDimension &&
			enemy.getPosition().x + enemyDimension > wallrect.x&&
			enemy.getPosition().y < wallrect.y + enemyDimension + 50 &&
			enemy.getPosition().y + enemyDimension > wallrect.y + 50)
		{
			currentPosition = lastPosition;
			enemy.setPosition(currentPosition);
			m_movement = RandomGeneratorForMovement();
			break;
		}
	}
	
	for (const auto& wallrect : bombRect)
	{
		if (enemy.getPosition().x < wallrect.x + enemyDimension &&
			enemy.getPosition().x + enemyDimension > wallrect.x&&
			enemy.getPosition().y < wallrect.y + enemyDimension + 50 &&
			enemy.getPosition().y + enemyDimension > wallrect.y + 50 && allowToMove == false)
		{
			currentPosition = lastPosition;
			enemy.setPosition(currentPosition);
			m_movement = RandomGeneratorForMovement();
			break;
		}

		if (!(enemy.getPosition().x < wallrect.x + enemyDimension &&
			enemy.getPosition().x + enemyDimension > wallrect.x&&
			enemy.getPosition().y < wallrect.y + enemyDimension + 50 &&
			enemy.getPosition().y + enemyDimension > wallrect.y + 50) && allowToMove == true)
		{
			allowToMove = false;
		}
	}

	switch (m_movement)
	{
	case 0:
	{
		lastPosition = enemy.getPosition();
		enemy.move(0, -speed);
	}
	break;
	case 1:

	{
		lastPosition = enemy.getPosition();
		enemy.move(0, speed);
	}
	break;
	case 2:

	{
		lastPosition = enemy.getPosition();
		enemy.move(speed, 0);
	}
	break;
	case 3:

	{
		lastPosition = enemy.getPosition();
		enemy.move(-speed, 0);
	}
	break;
	default:
		break;
	}
}
sf::Vector2f Enemy::GetPosition()
{
	return enemy.getPosition();
}
void Enemy::EnemyDie()
{
	m_active = false;
	enemy.setPosition({ 0,0 });
}

bool Enemy::GetActive() const
{
	return m_active;
}