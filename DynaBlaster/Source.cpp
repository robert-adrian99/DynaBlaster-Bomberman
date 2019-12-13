#include <fstream>
#include <SFML/Graphics.hpp>
#include "../Logging/Logger.h"
#include "DynaBlasterGame.h"

int main()
{
	DynaBlasterGame dyna;

	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Start Application.", Logger::Level::Info);

	dyna.Run();

	return 0;
}