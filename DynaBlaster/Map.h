#pragma once
#include <random>

class Map
{
public:
	using Position = std::pair<uint16_t, uint16_t>;

public:
	class base_iterator
	{

	public:
		base_iterator(const Map& map, const Map::Position& initialPositions);
		//const std::optional<Piece>& operator *();
		//const std::optional<Piece>* operator ->();
		bool operator != (const base_iterator& other);

	protected:
		const Map& m_map;
		Map::Position m_currentPosition;
	};

	class line_iterator : public base_iterator
	{
	public:
		using base_iterator::base_iterator;

		line_iterator& operator ++();
		line_iterator operator ++(int);
	};

	class column_iterator : public base_iterator
	{
	public:
		using base_iterator::base_iterator;

		column_iterator& operator ++();
		column_iterator operator ++(int);
	};

public:
	Map(uint16_t linesNumber = 13, uint16_t columnsNumber = 17);
	friend std::ostream& operator <<(std::ostream& out, const Map& map);
	char& operator[](const Position& position);
	const char& operator[](const Position& position) const;
	uint16_t GetLinesNumber() const;
	uint16_t GetColumnsNumber() const;

protected:
	bool IsPowerUpUnderWall(Position wallPosition);

private:
	int RandomColumn(int random);
	int RandomLine(int random);
	std::vector<Position> InitializePowerUps(int level);

protected:
	uint16_t m_linesNumber;
	uint16_t m_columnsNumber;
	std::vector<std::vector<char>> m_map;
	std::vector<Position> positionsForPowerUps;
	std::vector<Position> positionsForWalls;
};

