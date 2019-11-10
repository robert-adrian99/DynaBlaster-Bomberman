#pragma once
#include <random>

class Map
{
public:
	Map(uint16_t linesNumber = 13, uint16_t columnsNumber = 17);
	friend std::ostream& operator <<(std::ostream& out, const Map& map);
	uint16_t GetLinesNumber() const;
	uint16_t GetColumnsNumber() const;
	void VerifyRewardUnderWall();

protected:
	int RandomColumn(int random);
	int RandomLine(int random);

protected:
	uint16_t m_linesNumber, m_columnsNumber;
	std::vector<std::vector<char>> m_map;
	std::vector<std::pair<uint16_t, uint16_t>> positionForRewards;
	std::vector<std::pair<uint16_t, uint16_t>> positionForWalls;
};

