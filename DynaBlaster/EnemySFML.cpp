#include "EnemySFML.h"

int random()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandom(0, 3);
	return rrandom(rng);
}

EnemySFML::EnemySFML(EnemyType enemyType)
{
	if (enemyType == EnemyType::Barom)
	{
		if (!enemyTexture.loadFromFile("Barom.png", { 0 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Shashakin)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 1 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Nagacham)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 2 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Ojin)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 3 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Pontan)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 4 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Boyon)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 5 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Telpio)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 6 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Parce)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 7 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::BigBoss)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 8 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Arion)
	{
		if (!enemyTexture.loadFromFile("EnemySFML.png", { 9 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	enemy.setTexture(&enemyTexture);
	enemy.setSize({ 48,48 });
	enemy.setPosition({ 1 *48, 8 * 48 + 50 });
	map.Map();
	map.setPosition(0.0f, 50.0f);
	m_movement = 0;
	
}
void EnemySFML::Movement()
{
	float speed = 0.1;
	currentPosition = enemy.getPosition();
	for (const auto& wallrect : map.GetRectVec())
	{
		if (enemy.getPosition().x < wallrect.x + 42 &&
			enemy.getPosition().x + 42 > wallrect.x&&
			enemy.getPosition().y < wallrect.y + 92 &&
			enemy.getPosition().y + 42 > wallrect.y + 50)
		{
			currentPosition = lastPosition;
			enemy.setPosition(currentPosition);
			m_movement = random();
			break;
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
sf::Vector2f EnemySFML::GetPosition()
{
	return enemy.getPosition();
}
void EnemySFML::EnemyDie()
{
	//Destroy the enemy. Work in progress.
}


