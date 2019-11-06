#pragma once
#include "PowerUps.h"
#include <cstdint>
#include <array>

class Player
{
public:
	Player();
	uint8_t getLives() const;
	uint8_t getSpeed() const;
	std::array<bool, 8> getPowerUps() const;

private:
	uint8_t m_lives;
	uint8_t m_speed;
	std::array<bool, 8> m_powerUps;
};

