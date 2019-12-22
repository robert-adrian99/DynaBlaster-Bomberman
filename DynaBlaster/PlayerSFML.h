#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "TileMap.h"
#include <random>
#include <math.h>

class PlayerSFML
{
public:
	PlayerSFML();
	void Move();
	sf::Vector2f GetPosition();

public:
	sf::RectangleShape player;

private:
	sf::Vector2f lastPosition;
	sf::Vector2f currentPosition;
	sf::Texture playerTexture;
	TileMap map;
};

