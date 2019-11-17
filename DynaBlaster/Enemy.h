#pragma once
#include <iostream>
#include <cstdint>
#include "Map.h"
#include "EnemyType.h"

class Enemy : Map
{
public:
	using Position = std::pair<uint16_t, uint16_t>;

public:
	Enemy(int xPosision, int yPosision, EnemyType enemyType);
	Position GetEnemyPosition() const;
	uint16_t GetX() const;
	uint16_t GetY() const;
	EnemyType GeyEnemyType() const;
	void Move();
	uint32_t Die();

private:
	int RandomMovement(int number);

private:
	Position m_enemyPosition;
	EnemyType m_enemyType;
};

