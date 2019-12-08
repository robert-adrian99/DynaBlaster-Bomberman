#include "TileMap.h"
#include "BackButton.h"
#include <vector>

void StartWindow();

void Map()
{
	sf::RenderWindow window(sf::VideoMode(850, 700), "Dyna Blaster - Bomberman");

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