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
	enum Direction { Up = 8, Left, Down, Right };
	sf::Vector2i source = { 0, Up };
	sf::Texture pTexture;
	sf::Sprite playerImage;
	float bottom, left, right, top;
	bool ok = true;
public:
	sf::RectangleShape rect;
	PlayerSFML();
	void Movement();
	void Update();
};

