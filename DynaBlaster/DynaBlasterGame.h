#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "HelpButton.h"
#include "PlayButton.h"
#include "LevelsButton.h"
#include "BattleButton.h"
#include "BackButton.h"
#include "Button.h"
#include "../Logging/Logger.h"
#include "TileMap.h"

class DynaBlasterGame
{
public:
	void Run();

private:
	void LevelsMenuWindow();
	void HelpMenuWindow();
	void StartWindow();
	void GameWindow();

private:
	TileMap map;
};

