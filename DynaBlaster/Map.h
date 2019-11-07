#pragma once
#include <random>

class Map
{
public:
	Map(uint16_t linesNumber = 13, uint16_t columnsNumber = 17);
	friend std::ostream& operator <<(std::ostream& out, const Map& map);
	uint16_t getLinesNumber() const;
	uint16_t getColumnsNumber() const;

protected:
	int randomColumn(int random);
	int randomLine(int random);

protected:
	uint16_t m_linesNumber, m_columnsNumber;
	std::vector<std::vector<char>> m_map;
};

