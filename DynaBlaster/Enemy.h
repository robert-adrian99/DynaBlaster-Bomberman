#pragma once
#include <iostream>
#include <cstdint>
#include "Map.h"
#include "EnemyType.h"

class Enemy
{
public:
	using Position = std::pair<uint16_t, uint16_t>;

public:
	Enemy(int xPosision, int yPosision, EnemyType enemyType, Map& map);
	Enemy(Map& map);
	Position GetEnemyPosition() const;
	uint16_t GetX() const;
	uint16_t GetY() const;
	void Move(Map& map);
	uint32_t Die(Map& map);
	EnemyType GetEnemyType() const;

private:
	void basicCoordinatesPossible(Map& map, std::array<int, 4>& posiblePosition);
	void basicMovement(Map& map);
	void noWallCoordinatesPossible(Map& map, std::array<int, 4>& posiblePosition);
	void noWallMovement(Map& map);
	void smartMovement(Map& map);
	int RandomMovement(int number);

private:
	Position m_enemyPosition;
	EnemyType m_enemyType;
	Map m_map;
	Position m_lastEnemyPosition;
	char m_enemySign;
};

