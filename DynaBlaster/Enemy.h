#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Map.h"
#include <random>
#include <math.h>
#include "EnemyType.h"

class Enemy
{
public:
	Enemy(EnemyType enemyType, Map& map);
	void Movement();
	sf::Vector2f GetPosition();
	void EnemyDie();
	bool GetActive() const;

public:
	sf::RectangleShape enemy;
	std::vector<sf::Vector2f> bombRect;
	bool allowToMove;

private:
	sf::Vector2f lastPosition;
	sf::Vector2f currentPosition;
	sf::Texture enemyTexture;
	Map* map;
	int m_movement;
	bool m_active = true;
};
