#include "TileMap.h"

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{
	if (!m_tileset.loadFromFile(tileset))
		return false;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileNumber = tiles[i + j * width];

			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

			if (tileNumber == 1)
			{
				rectVec.push_back(quad[0].position);
			}

			if (tileNumber == 2)
			{
				rectVecTemporar.push_back(quad[0].position);
			}
		}
	}
}

std::vector<sf::Vector2f> TileMap::GetRectVec() const
{
	return rectVec;
}

std::vector<sf::Vector2f> TileMap::GetRectVecTemporar() const
{
	return rectVecTemporar;
}

void TileMap::SetRectVecTemp(const sf::Vector2f& positionRect)
{
	for (int index = 0; index < rectVecTemporar.size(); index++)
		if (rectVecTemporar[index] == positionRect)
			rectVecTemporar[index] = { -48,-48 };
}

void TileMap::ResetMap()
{
	m_vertices.clear();
	m_tileset.~Texture();
	rectVec.clear();
	rectVecTemporar.clear();
}

void TileMap::SetRectVec(const sf::Vector2f& positionRect)
{
	rectVec.emplace_back(positionRect);
}

void TileMap::SetRectVec(const std::vector<sf::Vector2f> positions)
{
	rectVec.clear();
	rectVec.assign(positions.begin(), positions.end());
}

void TileMap::ResetRectVec()
{
	rectVec.pop_back();
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;

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