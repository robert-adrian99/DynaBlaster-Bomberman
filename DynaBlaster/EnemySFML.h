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
	EnemySFML(EnemyType enemyType);
	void Movement();
	sf::Vector2f GetPosition();
	void EnemyDie();

public:
	sf::RectangleShape enemy;

private:
	sf::Vector2f lastPosition;
	sf::Vector2f currentPosition;
	sf::Texture enemyTexture;
	TileMap map;
	int m_movement;
};

