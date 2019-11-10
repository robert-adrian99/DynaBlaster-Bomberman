#include "Map.h"
#include "Player.h"
#include <iostream>

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
void Map::VerifyRewardUnderWall()
{
	for (auto& element : positionForRewards)
		for (auto& elem : positionForWalls)
			if (element == elem)
				m_map[elem.first][elem.second] = '+';
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
			if (column == 0 || column == m_columnsNumber - 2)
			{
				m_map[line][column] = 219;
				m_map[line][column + 1] = 219;
			}
			if (line == 0 || line == m_linesNumber - 1)
			{
				m_map[line][column] = 219;
			}
			if ((line == m_linesNumber - 1 && column == 0) || (line == m_linesNumber - 1 && column == m_columnsNumber - 1))
			{
				m_map[line][column] = 219;
			}
			if (line != 0 && line != m_linesNumber - 1 && line % 2 == 0 && column != 1 && column != m_columnsNumber - 2 && column % 2 != 0)
			{
				m_map[line][column] = 254;
			}
		}
	}

	int numberWalls;
	if (m_linesNumber == 29)
		numberWalls = 66;
	else
		if (m_columnsNumber == 31)
			numberWalls = 60;
		else
			numberWalls = 32;

	for (int number = 0; number < numberWalls; ++number)
	{
		uint16_t m_xPosition = 0, m_yPosition = 0;
		do {
			m_xPosition = RandomLine(m_linesNumber);
			m_yPosition = RandomColumn(m_columnsNumber);
		} while (m_xPosition % 2 == 0 && m_yPosition % 2 != 0 || (m_xPosition == 2 && m_yPosition == 2) || (m_xPosition == 2 && m_yPosition == 3) || (m_xPosition == 3 && m_yPosition == 2));
		m_map[m_xPosition][m_yPosition] = 176;
		positionForWalls.push_back(std::make_pair(m_xPosition, m_yPosition));
	}

	for (int number = 0; number < 10; ++number)
	{
		int m_xPosition1 = 0, m_yPosition1 = 0;
		do {
			m_xPosition1 = RandomLine(m_linesNumber);
			m_yPosition1 = RandomColumn(m_columnsNumber);
		} while (m_xPosition1 % 2 == 0 && m_yPosition1 % 2 != 0 || m_map[m_xPosition1][m_yPosition1] == ' ' || (m_xPosition1 == 2 && m_yPosition1 == 2) || (m_xPosition1 == 2 && m_yPosition1 == 3) || (m_xPosition1 == 3 && m_yPosition1 == 2));
		//m_map[m_xPosition][m_yPosition] = '+';
		std::cout << m_xPosition1 << "-" << m_yPosition1 << std::endl;
		positionForRewards.push_back(std::make_pair(m_xPosition1, m_yPosition1));
	}
	m_map[1][2] = 'P';


}

uint16_t Map::GetLinesNumber() const
{
	return m_linesNumber;
}

uint16_t Map::GetColumnsNumber() const
{
	return m_columnsNumber;
}




