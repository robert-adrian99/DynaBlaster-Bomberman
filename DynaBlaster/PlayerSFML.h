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
	void SetMap(TileMap& map);
	void SetBombRect(const sf::Vector2f& position);
	bool allowToMove;
	std::vector<sf::Vector2f> bombRect;
	void PlayerDie();
	bool GetActive() const;
	int GetLives() const;
	void SetLives(int lives);
	bool Intersects(sf::Vector2f position);

public:
	sf::RectangleShape player;

private:
	sf::Vector2f lastPosition;
	sf::Vector2f currentPosition;
	sf::Texture playerTexture;
	TileMap* map;	
	bool m_active;
	int m_lives;
};

