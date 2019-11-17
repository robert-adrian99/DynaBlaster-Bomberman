#include "Bomb.h"

Bomb::Bomb()
{
	m_bombSymbol = 'O';
	m_explosionRange = 1;
	m_bombPosition.first = NULL;
	m_bombPosition.second = NULL;
}

uint8_t Bomb::GetExplosionRange() const
{
	return m_explosionRange;
}

void Bomb::PlaceBomb(Position position)
{
	m_bombPosition = position;
}
