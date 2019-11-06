#include "Player.h"

Player::Player()
{
	m_lives = 2;
	m_speed = 1;
	m_powerUps = { false };
}

uint8_t Player::getLives() const
{
	return m_lives;
}

uint8_t Player::getSpeed() const
{
	return m_speed;
}

std::array<bool, 8> Player::getPowerUps() const
{
	return m_powerUps;
}

