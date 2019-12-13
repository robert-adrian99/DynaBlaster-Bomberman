#pragma once
#include <SFML/Graphics.hpp>

class TileMap:public sf::Drawable, public sf::Transformable
{
public:
	void Map();
	bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	int RandomColumn(int random);
	int RandomLine(int random);

private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};