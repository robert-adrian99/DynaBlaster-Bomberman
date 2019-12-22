#include "EnemySFML.h"

EnemySFML::EnemySFML(EnemyType enemyType)
{
	if (enemyType == EnemyType::Barom)
	{
		if (!enemyTexture.loadFromFile("Barom.jpg", { 0 * 48, 0 * 48, 48 , 48 }))
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
	enemy.setPosition({ 1 *48, 6 * 48 + 50 });
	map.Map();
	map.setPosition(0.0f, 50.0f);
	
}
void EnemySFML::EnemyDie()
{
	//Destroy the enemy.
}


