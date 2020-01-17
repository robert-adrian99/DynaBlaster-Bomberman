#pragma once
#include "TileMap.h"
#include "EnemySFML.h"
#include "PlayerSFML.h"

struct TemporarVector
{
	std::vector<sf::Vector2f> blocks;
	std::vector<bool> blocksType;
};
class DynaBlasterGame
{
public:
	enum class Directions
	{
		Up,
		Down,
		Left,
		Right
	};

public:
	void Run();
	DynaBlasterGame();
private:
	void LevelsMenuWindow();
	void HelpMenuWindow();
	void StartWindow();
	void GameWindow();
	void DrawBombExplosion(std::vector<EnemySFML>& enemies, PlayerSFML& player, std::vector<sf::RectangleShape>& grassRectangle);
	void Collision(const Directions direction, const sf::Vector2f& temporarVec, const TemporarVector& blocks, PlayerSFML& player, std::vector<EnemySFML>& enemies, std::vector<sf::RectangleShape>& grass);

private:
	TileMap map;
	sf::RenderWindow m_window;
	sf::RectangleShape bombRect;
	sf::RectangleShape bombExplosion;
	std::vector<sf::RectangleShape> grassRectangle;

private:
	bool okUp;
	bool okDown;
	bool okLeft;
	bool okRight;

	sf::Text lives;
	sf::Text score;
	sf::Text time;
	sf::Text highScore;

	sf::Clock clock;
	int m_minutes;
	int m_seconds;
	int m_score;

	int m_index;
	sf::Texture grassTexture;
	bool isActive = false;
	std::vector<sf::Vector2f> explosionPositions;
	bool justExplosion;

	sf::RectangleShape rewardRectangle;
	sf::Texture rewardTexture;
};