#include <iostream>
#include <fstream>
#include "Map.h"
#include "PowerUps.h"
#include <SFML/Graphics.hpp>
#include "GrassGraphics.h"
#include "UndestructibleWallGraphics.h"
#include "../Logging/Logger.h"

void GrassGraphics();
void UndestructibleWallGraphics();

int main()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Start Application", Logger::Level::Info);

	UndestructibleWallGraphics();
	return 0;
}