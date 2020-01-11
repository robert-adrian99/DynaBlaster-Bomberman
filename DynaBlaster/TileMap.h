#pragma once
#include <SFML/Graphics.hpp>

class TileMap :public sf::Drawable, public sf::Transformable
{
public:
	void Map();
	bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);
	std::vector<sf::Vector2f> GetRectVec() const;
	std::vector<sf::Vector2f> GetRectVecTemporar() const;
	std::vector<int> GetLevelVector() const;
	void SetRectVec(const sf::Vector2f& positionRect);
	void SetRectVec(const std::vector<sf::Vector2f> positions);
	void ResetRectVec();
	void SetRectVecTemp(const sf::Vector2f& positionRect);
	void ResetMap();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	int RandomColumn(int random);
	int RandomLine(int random);

private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	std::vector<sf::Vector2f> rectVec;
	std::vector<sf::Vector2f> rectVecTemporar;
};