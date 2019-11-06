#include "Map.h"


std::ostream& operator<<(std::ostream& out, const Map& map)
{
	for (auto& line : map.m_map)
	{
		for (auto& elements : line)
			std::cout << elements;
		std::cout << std::endl;
	}
	return out;
}

Map::Map(uint16_t linesNumber, uint16_t columnsNumber)
{
	m_linesNumber = linesNumber;
	m_columnsNumber = columnsNumber;
	for (uint16_t index = 0; index < m_linesNumber; ++index)
	{
		std::vector<char> temp;
		for (uint16_t index2 = 0; index2 < m_columnsNumber; ++index2)
		{
			temp.push_back(' ');
		}
		m_map.push_back(temp);
		temp.clear();
	}
	for (uint8_t line = 0; line < m_linesNumber; ++line)
	{
		for (uint8_t column = 0; column < m_columnsNumber; ++column)
		{
			if (column == 0 || column == m_columnsNumber - 1)
			{
				m_map[line][column] = '|';
			}
			if (line == 0 || line == m_linesNumber - 1)
			{
				m_map[line][column] = '_';
			}
			if ((line == m_linesNumber - 1 && column == 0) || (line == m_linesNumber - 1 && column == m_columnsNumber - 1))
			{
				m_map[line][column] = '|';
			}
			if (line != 0 && line != m_linesNumber - 1 && line % 2 == 0 && column != 0 && column != m_columnsNumber - 1 && column % 2 == 0)
			{
				m_map[line][column] = '-';
			}
		}
	}
}

uint16_t Map::getLinesNumber() const
{
	return m_linesNumber;
}

uint16_t Map::getColumnsNumber() const
{
	return m_columnsNumber;
}
