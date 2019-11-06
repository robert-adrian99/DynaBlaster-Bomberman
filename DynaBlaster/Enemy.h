#pragma once
#include <iostream>
#include <cstdint>
#include "Map.h"
#include "EnemyType.h"
class Enemy : Map
{
public:
	Enemy(int xPos, int yPosm, EnemyType enemyType);
	uint16_t getX() { return m_xPosition; }
	uint16_t getY() { return m_yPosition; }

private:
	uint16_t m_xPosition;
	uint16_t m_yPosition;
	EnemyType m_enemyType;
};

