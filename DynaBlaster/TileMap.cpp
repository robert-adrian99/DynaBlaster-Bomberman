#include "TileMap.h"
#include "Button.h"
#include <vector>
#include <fstream>
#include <random>
#include "../Logging/Logger.h"
#include <SFML/Audio.hpp>

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{
	// load the tileset texture
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width];

			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
}

int TileMap::RandomColumn(int random)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandomColumn(2, random - 3);
	return rrandomColumn(rng);
}

int TileMap::RandomLine(int random)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandomLine(1, random - 2);
	return rrandomLine(rng);
}

void TileMap::Map()
{
	uint16_t linesNumber = 13;
	uint16_t columnsNumber = 15;

	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	logger.Log("Tilemap window was rendered.", Logger::Level::Info);

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	Button back("Back", { 100,35 }, 20, sf::Color::Green, sf::Color::Black);
	back.SetPosition({ 50,638 });
	back.SetFont(colleged);

	
	// define the level with an array of tile indices
	std::vector<int> level;
	for (size_t line = 0; line < linesNumber; ++line)
	{
		for (size_t column = 0; column < columnsNumber; ++column)
		{
			if (line == 0 || line == linesNumber - 1 || column == 0 || column == columnsNumber - 1)
			{
				level.push_back(1);
			}
			else if (line % 2 == 0 && column % 2 == 0)
			{
				level.push_back(1);
			}
			else
				level.push_back(0);
		}
	}
	int NoWall = 32;
	srand(time(NULL)); //initialize the random seed
	int RandIndex = rand() % level.size(); //generates a random number between 0 and 3
	for (int index = 0; index < level.size(); index++)
	{
		RandIndex = rand() % level.size();
		if (level[RandIndex] == 0 && NoWall != 0 && RandIndex != columnsNumber + 1
			&& RandIndex != columnsNumber + 2 && RandIndex != (columnsNumber * 2 + 1))
		{
			level[RandIndex] = 2;
			--NoWall;
		}
	}
	// create the tilemap from the level definition
	if (load("tileset.png", sf::Vector2u(48, 48), level, 15, 13))
		return;

	logger.Log("Map was loaded.", Logger::Level::Info);

	
}