#include "Enemy.h"
#include <random>
#include <vector>
#include "Player.h"
#include <array>


Enemy::Enemy(int xPosision, int yPosision, EnemyType enemyType, Map& map)
{

	m_enemyPosition = std::make_pair(xPosision, yPosision);
	switch (enemyType)
	{
	case EnemyType::Barom:
		m_enemySign = 'B';
		break;
	case EnemyType::Shashakin:
		m_enemySign = 'S';
		break;
	case EnemyType::Nagacham:
		m_enemySign = 'N';
		break;
	case EnemyType::Ojin:
		m_enemySign = 'O';
		break;
	case EnemyType::Pontan:
		m_enemySign = 'P';
		break;
	case EnemyType::Boyon:
		m_enemySign = 'B';
		break;
	case EnemyType::Telpio:
		m_enemySign = 'T';
		break;
	case EnemyType::Parce:
		m_enemySign = 'P';
		break;
	case EnemyType::BigBoss:
		break;
	case EnemyType::Arion:
		break;
	}
	map[m_enemyPosition] = m_enemySign;
	m_enemyType = enemyType;
	m_map = map;
	m_lastEnemyPosition = m_enemyPosition;
}

Enemy::Enemy(Map& map)
{
	m_enemyPosition = std::make_pair(3, 3);
	m_enemyType = EnemyType::Barom;
	m_map = map;
	m_lastEnemyPosition = m_enemyPosition;
	m_enemySign = 'B';
	map[m_enemyPosition] = m_enemySign;
}

Enemy::Position Enemy::GetEnemyPosition() const
{
	return m_enemyPosition;
}

uint16_t Enemy::GetX() const
{
	const auto& [xPosition, yPosition] = m_enemyPosition;
	return xPosition;
}

uint16_t Enemy::GetY() const
{
	const auto& [xPosition, yPosition] = m_enemyPosition;
	return yPosition;
}

int Enemy::RandomMovement(int number)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandom(0, number);
	return rrandom(rng);
}
void Enemy::basicCoordinatesPossible(Map& map, std::array<int, 4>& posiblePosition)
{
	auto& [xPosition, yPosition] = m_enemyPosition;

	Position enemyPositionN = std::make_pair(xPosition - 1, yPosition);
	Position enemyPositionS = std::make_pair(xPosition + 1, yPosition);
	Position enemyPositionE = std::make_pair(xPosition, yPosition + 1);
	Position enemyPositionV = std::make_pair(xPosition, yPosition - 1);

	char N = map[enemyPositionN];
	char S = map[enemyPositionS];
	char E = map[enemyPositionE];
	char V = map[enemyPositionV];

	if (N == ' ') posiblePosition[0] = 1;
	else posiblePosition[0] = 0;
	if (S == ' ') posiblePosition[1] = 1;
	else posiblePosition[1] = 0;
	if (E == ' ') posiblePosition[2] = 1;
	else posiblePosition[2] = 0;
	if (V == ' ') posiblePosition[3] = 1;
	else posiblePosition[3] = 0;
}
void Enemy::basicMovement(Map& map)
{

	auto& [xPosition, yPosition] = m_enemyPosition;
	std::array<int, 4> posiblePosition;
	basicCoordinatesPossible(map, posiblePosition);
	int move = NULL;
	move = RandomMovement(posiblePosition.size() - 1);
	while (posiblePosition[move] != 1)
		move = RandomMovement(posiblePosition.size() - 1);
	map[m_enemyPosition] = ' ';
	switch (move)
	{
	case 0:
		--xPosition;
		break;
	case 1:
		++xPosition;
		break;
	case 2:
		++yPosition;
		break;
	case 3:
		--yPosition;
	default:
		break;
	}

	m_enemyPosition = std::make_pair(xPosition, yPosition);
	map[m_enemyPosition] = m_enemySign;
}
void Enemy::noWallCoordinatesPossible(Map& map, std::array<int, 4>& posiblePosition)
{
	auto& [xPosition, yPosition] = m_enemyPosition;
	for (int index = 0; index < 4; index++)
		posiblePosition[index] = 0;

	Position enemyPositionN = std::make_pair(xPosition - 1, yPosition);
	Position enemyPositionS = std::make_pair(xPosition + 1, yPosition);
	Position enemyPositionE = std::make_pair(xPosition, yPosition + 1);
	Position enemyPositionV = std::make_pair(xPosition, yPosition - 1);

	char N = map[enemyPositionN];
	char S = map[enemyPositionS];
	char E = map[enemyPositionE];
	char V = map[enemyPositionV];

	if (N != (char)219 && N != 'O' && N != (char)254) posiblePosition[0] = 1;
	if (S != (char)219 && S != 'O' && S != (char)254) posiblePosition[1] = 1;
	if (E != (char)219 && E != 'O' && E != (char)254) posiblePosition[2] = 1;
	if (V != (char)219 && V != 'O' && V != (char)254) posiblePosition[3] = 1;
}

void Enemy::noWallMovement(Map& map)
{
	auto& [xPosition, yPosition] = m_enemyPosition;

	m_lastEnemyPosition = m_enemyPosition;

	std::array<int, 4> posiblePosition;
	noWallCoordinatesPossible(map, posiblePosition);
	map[m_enemyPosition] = ' ';
	int move = NULL;
	move = RandomMovement(posiblePosition.size() - 1);
	while (posiblePosition[move] != 1)
		move = RandomMovement(posiblePosition.size() - 1);

	map[m_enemyPosition] = ' ';

	switch (move)
	{
	case 0:
		--xPosition;
		break;
	case 1:
		++xPosition;
		break;
	case 2:
		++yPosition;
		break;
	case 3:
		--yPosition;
		break;
	default:
		break;
	}
	m_enemyPosition = std::make_pair(xPosition, yPosition);
	map[m_enemyPosition] = m_enemySign;
	if (m_enemyPosition != m_lastEnemyPosition)
		if (m_map[m_lastEnemyPosition] == (char)176)
			map[m_lastEnemyPosition] = (char)176;
}
void Enemy::smartMovement(Map& map)
{
	const auto& [xPosition, yPosition] = m_enemyPosition;
	std::array<int, 4> posiblePosition;
	//basicCoordinatesPossible(map,posiblePosition);

	Player player;
	const auto& [xPlayerPosition, yPlayerPosition] = player.GetPlayerPosition();

	int xMinPosition = 0;
	int yMinPosition = 0;
	int min = map.GetColumnsNumber() + map.GetLinesNumber();

	for (auto& iterator : posiblePosition)
	{
		if (iterator == 'N')
			if (((xPosition - 1 + yPosition) - (xPlayerPosition + yPlayerPosition)) < min)
			{
				min = ((xPosition - 1 + yPosition) - (xPlayerPosition + yPlayerPosition));
				xMinPosition = xPosition - 1;
				yMinPosition = yPosition;
			}
			else if (iterator == 'S')
				if (((xPosition + 1 + yPosition) - (xPlayerPosition + yPlayerPosition)) < min)
				{
					min = ((xPosition + 1 + yPosition) - (xPlayerPosition + yPlayerPosition));
					xMinPosition = xPosition + 1;
					yMinPosition = yPosition;
				}
				else if (iterator == 'E')
					if (((xPosition + yPosition + 1) - (xPlayerPosition + yPlayerPosition)) < min)
					{
						min = ((xPosition + yPosition + 1) - (xPlayerPosition + yPlayerPosition));
						xMinPosition = xPosition;
						yMinPosition = yPosition + 1;
					}
					else if (iterator == 'V')
						if (((xPosition + yPosition - 1) - (xPlayerPosition + yPlayerPosition)) < min)
						{
							min = ((xPosition + yPosition - 1) - (xPlayerPosition + yPlayerPosition));
							xMinPosition = xPosition;
							yMinPosition = yPosition - 1;
						}
	}
	m_enemyPosition = std::make_pair(xMinPosition, yMinPosition);
}
void Enemy::Move(Map& map)
{
	switch (m_enemyType)
	{
	case EnemyType::Barom:
	{
		basicMovement(map);
		break;
	}
	case EnemyType::Shashakin:
	{
		basicMovement(map);
		break;
	}
	case EnemyType::Nagacham:
	{
		basicMovement(map);
		break;
	}
	case EnemyType::Ojin:
	{
		noWallMovement(map);
		break;
	}
	case EnemyType::Pontan:
	{
		noWallMovement(map);
		break;
	}
	case EnemyType::Boyon:
	{
		noWallMovement(map);
		break;
	}
	case EnemyType::Telpio:
	{
		noWallMovement(map);
		break;
	}
	case EnemyType::Parce:
	{
		smartMovement(map);
		break;
	}
	case EnemyType::BigBoss:
		break;
	case EnemyType::Arion:
		break;
	default:
		break;
	}
}

uint32_t Enemy::Die(Map& map)
{
	m_enemyPosition = std::make_pair(0, 0);
	//map[m_enemyPosition] = (char)219;

	switch (m_enemyType)
	{
	case EnemyType::Barom:
		return 100;
	case EnemyType::Shashakin:
		return 400;
	case EnemyType::Nagacham:
		return 100;
	case EnemyType::Ojin:
		return 400;
	case EnemyType::Pontan:
		return 200;
	case EnemyType::Boyon:
		return 1000;
	case EnemyType::Telpio:
		return 1000;
	case EnemyType::Parce:
		return 2000;
	case EnemyType::BigBoss:
		return 20000;
	case EnemyType::Arion:
		return 20000;
	default:
		break;
	}
}

EnemyType Enemy::GetEnemyType() const
{
	return m_enemyType;
}


