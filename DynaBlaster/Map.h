#pragma once
#include <vector>
#include <iostream>

class Map
{
public:
	Map(uint16_t linesNumber = 13, uint16_t columnsNumber = 15);
	friend std::ostream& operator <<(std::ostream& out, const Map& map);
	uint16_t getLinesNumber() const;
	uint16_t getColumnsNumber() const;

private:
	uint16_t m_linesNumber, m_columnsNumber;
	std::vector<std::vector<char>> m_map;
};

