#pragma once
#include "TileMap.h"

class DynaBlasterGame
{
public:
	void Run();

private:
	void LevelsMenuWindow(sf::RenderWindow& window);
	void HelpMenuWindow(sf::RenderWindow& window);
	void StartWindow(sf::RenderWindow& window);
	void GameWindow(sf::RenderWindow& window);

private:
	TileMap map;
};

