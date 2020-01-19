#pragma once
#include "Map.h"
#include "EnemyType.h"

class Enemy
{
public:
	Enemy(EnemyType enemyType, Map& map);
	void Move();
	sf::Vector2f GetPosition() const;
	sf::RectangleShape GetRectangle() const;
	bool IsActive() const;
	bool AllowToMove() const;
	void SetAllowToMove(const bool allowToMove);
	void Die();
	uint64_t GetScore() const;
	bool Intersects(const sf::Vector2f& position);
	void CollisionWithWalls(const std::vector<sf::Vector2f>& walls);
	void CollisionWithBomb(const std::vector<sf::Vector2f>& bombsVector);

public:
	std::vector<sf::Vector2f> m_bombsVector;

private:
	sf::RectangleShape m_rectangle;
	sf::Vector2f m_lastPosition;
	sf::Vector2f m_currentPosition;
	sf::Texture m_enemyTexture;
	Map* m_map;
	int m_movement;
	bool m_active;
	bool m_allowToMove;
	EnemyType m_enemyType;
	const int m_enemyDimension = 42;
};
