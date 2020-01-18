#pragma once
#include "../Logging/Logger.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <random>
#include <string>

class Map :public sf::Drawable, public sf::Transformable
{
public:
	template <uint16_t numberOfLines = 13, uint16_t numberOfColumns = 15, uint16_t numberOfWalls = 32>
	void LoadMap()
	{
		int noWalls = numberOfWalls;
		std::ofstream logFile("log.log", std::ios::app);
		Logger logger(logFile, Logger::Level::Info);

		logger.Log("Tilemap window was rendered.", Logger::Level::Info);

		std::vector<int> level;

		for (size_t line = 0; line < numberOfLines; ++line)
		{
			for (size_t column = 0; column < numberOfColumns; ++column)
			{
				if (line == 0 || line == numberOfLines - 1 || column == 0 || column == numberOfColumns - 1)
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

		srand(time(NULL));
		int RandIndex = rand() % level.size();
		for (int index = 0; index < level.size(); index++)
		{
			RandIndex = rand() % level.size();
			if (level[RandIndex] == 0 && noWalls != 0 && RandIndex != numberOfColumns + 1
				&& RandIndex != numberOfColumns + 2 && RandIndex != (numberOfColumns * 2 + 1))
			{
				level[RandIndex] = 2;
				--noWalls;
			}
		}

		int k = 0;
		for (int index = 0; index < numberOfLines; index++)
		{
			std::vector<int> tempVect;
			for (int index1 = 0; index1 < numberOfColumns; index1++)
			{
				tempVect.push_back(level[k++]);
			}
			maps.push_back(tempVect);
		}

		if (load("tileset.png", sf::Vector2u(48, 48), level, numberOfColumns, numberOfLines))
			return;

		logger.Log("Map was loaded.", Logger::Level::Info);
	}
	bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);
	std::vector<sf::Vector2f> GetIndestructibleWallVector() const;
	std::vector<sf::Vector2f> GetDestructibleWallVector() const;
	void SetIndestructibleWallVector(const sf::Vector2f& positionRect);
	void SetIndestructibleWallVector(const std::vector<sf::Vector2f> positions);
	void ResetIndestructibleWallVector();
	void SetDestructibleWallVector(const sf::Vector2f& positionRect);
	void ResetMap();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	int RandomColumn(int random);
	int RandomLine(int random);
	std::vector<std::vector<int>> maps;

private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	std::vector<sf::Vector2f> m_indestructibleWallVecor;
	std::vector<sf::Vector2f> m_destructibleWallVector;
};