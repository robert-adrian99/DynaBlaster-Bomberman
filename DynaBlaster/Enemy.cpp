#include "Enemy.h"
#include <random>

Enemy::Enemy(int xPos, int yPos, EnemyType enemyType)
{
	m_map[xPos][yPos] = 'X';
	m_xPosition = xPos;
	m_yPosition = yPos;
	m_enemyType = enemyType;
}
int Enemy::getEnemyPoints(EnemyType enemy)
{
	switch (enemy)
	{
	case EnemyType::Barom:
		return 100;
	case EnemyType::Shashakin:
		return 400;
		break;
	case EnemyType::Nagacham:
		return 100;
		break;
	case EnemyType::Ojin:
		return 400;
		break;
	case EnemyType::Pontan:
		return 200;
		break;
	case EnemyType::Boyon:
		return 1000;
		break;
	case EnemyType::Telpio:
		return 1000;
		break;
	case EnemyType::Parce:
		return 2000;
		break;
	case EnemyType::BigBoss:
		return 20000;
		break;
	case EnemyType::Arion:
		return 20000;
		break;
	default:
		break;
	}
}

int randmovement(int number)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandom(0, number);
	return rrandom(rng);
}
void Enemy::enemyMovement(Enemy& enemy)
{
	switch (m_enemyType)
	{
	case EnemyType::Barom:
	{
		char N = m_map[enemy.m_xPosition--][enemy.m_yPosition], S = m_map[enemy.m_xPosition++][enemy.m_yPosition],
			E = m_map[enemy.m_xPosition][enemy.m_yPosition++], V = m_map[enemy.m_xPosition][enemy.m_yPosition--];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int ch = randmovement(posiblePos.size());
		switch (ch)
		{
		case 0:
			enemy.m_xPosition--;
			break;
		case 1:
			enemy.m_xPosition++;
			break;
		case 2:
			enemy.m_yPosition++;
			break;
		case 3:
			enemy.m_yPosition--;
			break;
		}
		break;
	}
	case EnemyType::Shashakin:
	{
		char N = m_map[enemy.m_xPosition--][enemy.m_yPosition], S = m_map[enemy.m_xPosition++][enemy.m_yPosition],
			E = m_map[enemy.m_xPosition][enemy.m_yPosition++], V = m_map[enemy.m_xPosition][enemy.m_yPosition--];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int ch = randmovement(posiblePos.size());
		switch (ch)
		{
		case 0:
			enemy.m_xPosition--;
			break;
		case 1:
			enemy.m_xPosition++;
			break;
		case 2:
			enemy.m_yPosition++;
			break;
		case 3:
			enemy.m_yPosition--;
			break;
		}
		break;
	}
	case EnemyType::Nagacham:
		break;
	case EnemyType::Ojin:
	{
		char N = m_map[enemy.m_xPosition--][enemy.m_yPosition], S = m_map[enemy.m_xPosition++][enemy.m_yPosition],
			E = m_map[enemy.m_xPosition][enemy.m_yPosition++], V = m_map[enemy.m_xPosition][enemy.m_yPosition--];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int ch = randmovement(posiblePos.size());
		switch (ch)
		{
		case 0:
			enemy.m_xPosition--;
			break;
		case 1:
			enemy.m_xPosition++;
			break;
		case 2:
			enemy.m_yPosition++;
			break;
		case 3:
			enemy.m_yPosition--;
			break;
		}
		break;
	}
	case EnemyType::Pontan:
	{
		char N = m_map[enemy.m_xPosition--][enemy.m_yPosition], S = m_map[enemy.m_xPosition++][enemy.m_yPosition],
			E = m_map[enemy.m_xPosition][enemy.m_yPosition++], V = m_map[enemy.m_xPosition][enemy.m_yPosition--];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int ch = randmovement(posiblePos.size());
		switch (ch)
		{
		case 0:
			enemy.m_xPosition--;
			break;
		case 1:
			enemy.m_xPosition++;
			break;
		case 2:
			enemy.m_yPosition++;
			break;
		case 3:
			enemy.m_yPosition--;
			break;
		}
		break;
	}
	case EnemyType::Boyon:
	{
		char N = m_map[enemy.m_xPosition--][enemy.m_yPosition], S = m_map[enemy.m_xPosition++][enemy.m_yPosition],
			E = m_map[enemy.m_xPosition][enemy.m_yPosition++], V = m_map[enemy.m_xPosition][enemy.m_yPosition--];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int ch = randmovement(posiblePos.size());
		switch (ch)
		{
		case 0:
			enemy.m_xPosition--;
			break;
		case 1:
			enemy.m_xPosition++;
			break;
		case 2:
			enemy.m_yPosition++;
			break;
		case 3:
			enemy.m_yPosition--;
			break;
		}
		break;
	}
	case EnemyType::Telpio:
	{
		char N = m_map[enemy.m_xPosition--][enemy.m_yPosition], S = m_map[enemy.m_xPosition++][enemy.m_yPosition],
			E = m_map[enemy.m_xPosition][enemy.m_yPosition++], V = m_map[enemy.m_xPosition][enemy.m_yPosition--];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int ch = randmovement(posiblePos.size());
		switch (ch)
		{
		case 0:
			enemy.m_xPosition--;
			break;
		case 1:
			enemy.m_xPosition++;
			break;
		case 2:
			enemy.m_yPosition++;
			break;
		case 3:
			enemy.m_yPosition--;
			break;
		}
		break;
	}
	case EnemyType::Parce:
	{
		char N = m_map[enemy.m_xPosition--][enemy.m_yPosition], S = m_map[enemy.m_xPosition++][enemy.m_yPosition],
			E = m_map[enemy.m_xPosition][enemy.m_yPosition++], V = m_map[enemy.m_xPosition][enemy.m_yPosition--];
		std::vector<char> posiblePos;
		if (N == ' ') posiblePos.push_back(N);
		if (S == ' ') posiblePos.push_back(S);
		if (E == ' ') posiblePos.push_back(E);
		if (V == ' ') posiblePos.push_back(V);
		int ch = randmovement(posiblePos.size());
		switch (ch)
		{
		case 0:
			enemy.m_xPosition--;
			break;
		case 1:
			enemy.m_xPosition++;
			break;
		case 2:
			enemy.m_yPosition++;
			break;
		case 3:
			enemy.m_yPosition--;
			break;
		}
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