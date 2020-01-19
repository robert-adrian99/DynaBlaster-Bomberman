#pragma once
#include "Map.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void Move();
	sf::Vector2f GetPosition() const;
	bool GetActive() const;
	uint16_t GetLives() const;
	bool AllowToMove() const;
	void SetAllowToMove(const bool allowToMove);
	void SetLives(const uint16_t lives);
	void SetMap(Map& map);
	void SetBombRect(const sf::Vector2f& position);
	void SetPosition(const sf::Vector2f& position);
	void Die();
	bool Intersects(const sf::Vector2f& position);
	void IncreaseBombExplosionRange();
	uint16_t GetBombExplosionRange() const;
	void CollisionWithWalls(const std::vector<sf::Vector2f>& walls);
	void CollisionWithBomb(const std::vector<sf::Vector2f>& bombsVector);

public:
	std::vector<sf::Vector2f> m_bombsVector;
	sf::RectangleShape m_rectangle;

private:
	sf::Vector2f m_lastPosition;
	sf::Vector2f m_currentPosition;
	sf::Texture m_playerTexture;
	Map* m_map;
	bool m_active;
	uint16_t m_lives;
	bool m_allowToMove;
	uint16_t m_bombExplosionRange;
};

