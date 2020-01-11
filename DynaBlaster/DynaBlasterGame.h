#pragma once
#include "TileMap.h"
#include "EnemySFML.h"

class DynaBlasterGame
{
public:
	void Run();

private:
	void LevelsMenuWindow();
	void HelpMenuWindow();
	void StartWindow();
	void GameWindow();
	void DrawBombExplosion(EnemySFML& enemy);

private:
	TileMap map;
	sf::RenderWindow m_window;
	sf::RectangleShape bombRect;
	sf::RectangleShape bombExplosion;

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
};