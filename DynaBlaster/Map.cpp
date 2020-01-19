#include "Map.h"

bool Map::load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{
	if (!m_tileset.loadFromFile(tileset))
		return false;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int line = 0; line < width; ++line)
	{
		for (unsigned int column = 0; column < height; ++column)
		{
			int tileNumber = tiles[line + column * width];

			int textureCoordX = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int textureCoordY = tileNumber / (m_tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(line + column * width) * 4];

			quad[0].position = sf::Vector2f(line * tileSize.x, column * tileSize.y);
			quad[1].position = sf::Vector2f((line + 1) * tileSize.x, column * tileSize.y);
			quad[2].position = sf::Vector2f((line + 1) * tileSize.x, (column + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(line * tileSize.x, (column + 1) * tileSize.y);

			quad[0].texCoords = sf::Vector2f(textureCoordX * tileSize.x, textureCoordY * tileSize.y);
			quad[1].texCoords = sf::Vector2f((textureCoordX + 1) * tileSize.x, textureCoordY * tileSize.y);
			quad[2].texCoords = sf::Vector2f((textureCoordX + 1) * tileSize.x, (textureCoordY + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(textureCoordX * tileSize.x, (textureCoordY + 1) * tileSize.y);

			if (tileNumber == 1)
			{
				m_indestructibleWallVecor.push_back(quad[0].position);
			}

			if (tileNumber == 2)
			{
				m_destructibleWallVector.push_back(quad[0].position);
			}
		}
	}
}

std::vector<sf::Vector2f> Map::GetIndestructibleWallVector() const
{
	return m_indestructibleWallVecor;
}

std::vector<sf::Vector2f> Map::GetDestructibleWallVector() const
{
	return m_destructibleWallVector;
}

void Map::SetDestructibleWallVector(const sf::Vector2f& positionRect)
{
	for (int index = 0; index < m_destructibleWallVector.size(); index++)
		if (m_destructibleWallVector[index] == positionRect)
			m_destructibleWallVector[index] = { -48,-48 };
}

void Map::ResetMap()
{
	m_vertices.clear();
	m_tileset.~Texture();
	m_indestructibleWallVecor.clear();
	m_destructibleWallVector.clear();

}

void Map::SetIndestructibleWallVector(const sf::Vector2f& positionRect)
{
	m_indestructibleWallVecor.emplace_back(positionRect);
}

void Map::SetIndestructibleWallVector(const std::vector<sf::Vector2f> positions)
{
	m_indestructibleWallVecor.clear();
	m_indestructibleWallVecor.assign(positions.begin(), positions.end());
}

void Map::ResetIndestructibleWallVector()
{
	m_indestructibleWallVecor.pop_back();
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;

	target.draw(m_vertices, states);
}

int Map::RandomColumn(int random)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandomColumn(2, random - 3);
	return rrandomColumn(rng);
}

int Map::RandomLine(int random)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandomLine(1, random - 2);
	return rrandomLine(rng);
}