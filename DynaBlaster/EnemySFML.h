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
private:
	enum Direction
	{
		First = 0,
		Second
	};

public:
	EnemySFML(EnemyType enemyType);
	void Movement();
	void Update();
	sf::Vector2f GetPosition();

public:
	sf::RectangleShape rect;

private:
	sf::Vector2i source = { 0, First };
	sf::Vector2f lastPosition;
	sf::Vector2f currentPosition;
	sf::Texture eTexture;
	sf::Sprite enemyImage;
	TileMap map;
	float bottom, left, right, top;
};

