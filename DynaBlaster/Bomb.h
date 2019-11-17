#pragma once
#include <iostream>
class Bomb
{
public:
	using Position = std::pair<uint16_t, uint16_t>;

public:
	Bomb();

	Bomb(const Bomb& other);
	Bomb(Bomb&& other);
	Bomb& operator=(const Bomb& other);
	Bomb& operator=(Bomb&& other);
	~Bomb();

	uint8_t GetExplosionRange() const;
	void PlaceBomb(Position position);

private:
	Position m_bombPosition;
	uint8_t m_explosionRange;
	char m_bombSymbol;
};

