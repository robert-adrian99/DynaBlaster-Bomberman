#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "TileMap.h"
#include <random>
#include <math.h>

class PlayerSFML
{
private:
	enum Direction
	{ 
		Up = 8,
		Left,
		Down,
		Right
	};

public:
	PlayerSFML();
	void Movement();
	void Update();

public:
	sf::RectangleShape rect;

private:
	sf::Vector2i source = { 0, Up };
	sf::Vector2f lastPosition;
	sf::Vector2f currentPosition;
	sf::Texture pTexture;
	sf::Sprite playerImage;
	TileMap map;
	float bottom, left, right, top;
};

