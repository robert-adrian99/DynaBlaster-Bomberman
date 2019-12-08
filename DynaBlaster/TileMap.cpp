#include "TileMap.h"
#include "BackButton.h"
#include <vector>
#include <fstream>
#include "../Logging/Logger.h"

void StartWindow();

void Map()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	sf::RenderWindow window(sf::VideoMode(850, 700), "Dyna Blaster - Bomberman");

	logger.Log("Tilemap window was rendered.", Logger::Level::Info);

	// define the level with an array of tile indices
	std::vector<int> level =
	{
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
	};

	int NoWall = 32;
	srand(time(NULL)); //initialize the random seed
	int RandIndex = rand() % level.size(); //generates a random number between 0 and 3
	for (int index = 0; index < level.size(); index++)
	{
		RandIndex = rand() % level.size();
		if (level[RandIndex] == 0 && NoWall != 0)
		{
			level[RandIndex] = 2;
			--NoWall;
		}
	}
	// create the tilemap from the level definition
	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 15, 13))
		return;

	logger.Log("Map was loaded.", Logger::Level::Info);

	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	BackButton back("Back", { 100,35 }, 20, sf::Color::Blue, sf::Color::White);
	back.SetPosition({ 50,638 });
	back.SetFont(arial);

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				if (back.IsMouseOver(window))
				{
					back.SetBgColor(sf::Color::Green);
				}
				else
				{
					back.SetBgColor(sf::Color::Blue);
				}
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && back.IsMouseOver(window))
				{
					logger.Log("Back button was pressed. Going back to start page.", Logger::Level::Info);
					window.close();
					StartWindow();
				}
			}

			// draw the map
			window.clear();
			window.draw(map);
			window.display();
		}
	}
}