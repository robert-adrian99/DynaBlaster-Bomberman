#include "Enemy.h"
#include <random>
#include <vector>


Enemy::Enemy(int xPosision, int yPosision, EnemyType enemyType)
{
	m_map[xPosision][yPosision] = 'X';
	m_enemyPosition = std::make_pair(xPosision, yPosision);
	m_enemyType = enemyType;
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
void Enemy::basicMovement(Enemy& enemy)
{
	auto [xPosition, yPosition] = enemy.m_enemyPosition;

	char N = enemy.m_map[xPosition - 1][yPosition];
	char S = enemy.m_map[xPosition + 1][yPosition];
	char E = enemy.m_map[xPosition][yPosition + 1];
	char V = enemy.m_map[xPosition][yPosition - 1];
	std::vector<char> posiblePos;
	if (N == ' ') posiblePos.push_back(N);
	if (S == ' ') posiblePos.push_back(S);
	if (E == ' ') posiblePos.push_back(E);
	if (V == ' ') posiblePos.push_back(V);
	int move = RandomMovement(posiblePos.size());
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
	enemy.m_enemyPosition = std::make_pair(xPosition, yPosition);
}
void Enemy::Move(Enemy& enemy)
{
	auto [xPosition, yPosition] = enemy.m_enemyPosition;
	switch (m_enemyType)
	{
	case EnemyType::Barom:
	{
		basicMovement(enemy);
		break;
	}
	case EnemyType::Shashakin:
	{
		basicMovement(enemy);
		break;
	}
	case EnemyType::Nagacham:
	{
		char N = m_map[xPosition - 1][yPosition];
		char S = m_map[xPosition + 1][yPosition];
		char E = m_map[xPosition][yPosition + 1];
		char V = m_map[xPosition][yPosition - 1];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int move = RandomMovement(posiblePos.size());
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
		break;
	}
	case EnemyType::Ojin:
	{
		char N = m_map[xPosition - 1][yPosition];
		char S = m_map[xPosition + 1][yPosition];
		char E = m_map[xPosition][yPosition + 1];
		char V = m_map[xPosition][yPosition - 1];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int move = RandomMovement(posiblePos.size());
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
		break;
	}
	case EnemyType::Pontan:
	{
		char N = m_map[xPosition - 1][yPosition];
		char S = m_map[xPosition + 1][yPosition];
		char E = m_map[xPosition][yPosition + 1];
		char V = m_map[xPosition][yPosition - 1];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int move = RandomMovement(posiblePos.size());
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
		break;
	}
	case EnemyType::Boyon:
	{
		char N = m_map[xPosition - 1][yPosition];
		char S = m_map[xPosition + 1][yPosition];
		char E = m_map[xPosition][yPosition + 1];
		char V = m_map[xPosition][yPosition - 1];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int move = RandomMovement(posiblePos.size());
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
		break;
	}
	case EnemyType::Telpio:
	{
		char N = m_map[xPosition - 1][yPosition];
		char S = m_map[xPosition + 1][yPosition];
		char E = m_map[xPosition][yPosition + 1];
		char V = m_map[xPosition][yPosition - 1];
		std::vector<char> posiblePos;
		if (N != (char)'254') posiblePos.push_back(N);
		if (S != (char)'254') posiblePos.push_back(S);
		if (E != (char)'254') posiblePos.push_back(E);
		if (V != (char)'254') posiblePos.push_back(V);
		int move = RandomMovement(posiblePos.size());
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
		break;
	}
	case EnemyType::Parce:
	{
		char N = m_map[xPosition - 1][yPosition];
		char S = m_map[xPosition + 1][yPosition];
		char E = m_map[xPosition][yPosition + 1];
		char V = m_map[xPosition][yPosition - 1];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int move = RandomMovement(posiblePos.size());
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

uint32_t Enemy::Die()
{
	m_enemyPosition = std::make_pair(0, 0);
	m_map[0][0] = (char)219;

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

EnemyType Enemy::GetEnemyType()
{
	return m_enemyType;
}


