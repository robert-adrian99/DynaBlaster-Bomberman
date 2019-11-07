#include "Enemy.h"
#include <random>

Enemy::Enemy(int xPos, int yPos, EnemyType enemyType)
{
	m_map[xPos][yPos] = 'X';
	m_xPosition = xPos;
	m_yPosition = yPos;
	m_enemyType = enemyType;
}