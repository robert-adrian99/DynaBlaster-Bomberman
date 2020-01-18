#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "TileMap.h"
#include <random>
#include <math.h>
#include "EnemyType.h"

class EnemySFML
{
public:
	EnemySFML(EnemyType enemyType, TileMap& map);
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
	TileMap* map;
	int m_movement;
	bool m_active = true;
};
