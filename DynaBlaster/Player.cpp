#include "Player.h"

Player::Player()
{
	m_lives = 2;
	m_speed = 1;
	m_score = 0;
	m_highScore = 0;
	m_explosionRange = 1;
	m_numberOfBombs = 1;
	m_powerUps = { false };
}

uint8_t Player::GetLives() const
{
	return m_lives;
}

uint8_t Player::GetSpeed() const
{
	return m_speed;
}

uint32_t Player::GetScore() const
{
	return m_score;
}

uint32_t Player::GetHighScore() const
{
	return m_highScore;
}

uint8_t Player::GetExplosionRange() const
{
	return m_explosionRange;
}

uint8_t Player::GetNumberOfBombs() const
{
	return m_numberOfBombs;
}

bool Player::GetPowerUp(PowerUps powerUp) const
{
	switch (powerUp)
	{
	case PowerUps::Flame:
		if (m_powerUps[firstPowerUp] == true)
			return true;
		break;
	case PowerUps::Bomb:
		if (m_powerUps[firstPowerUp + 1] == true)
			return true;
		break;
	case PowerUps::RollerSkates:
		if (m_powerUps[firstPowerUp + 2] == true)
			return true;
		break;
	case PowerUps::RemoteControl:
		if (m_powerUps[firstPowerUp + 3] == true)
			return true;
		break;
	case PowerUps::PaintedBomb:
		if (m_powerUps[firstPowerUp + 4] == true)
			return true;
		break;
	case PowerUps::Character:
		if (m_powerUps[firstPowerUp + 5] == true)
			return true;
		break;
	case PowerUps::PaintedWall:
		if (m_powerUps[firstPowerUp + 6] == true)
			return true;
		break;
	case PowerUps::Jacket:
		if (m_powerUps[firstPowerUp+ 7] == true)
			return true;
		break;
	default:
		break;
	}
	return false;
}

bool Player::Die()
{
	if (m_lives == 0)
	{
		return true;
	}
	--m_lives;
	m_powerUps = { false };
	return false;
}

void Player::SetPowerUp(PowerUps powerUp)
{
	switch (powerUp)
	{
	case PowerUps::Flame:
		m_powerUps[firstPowerUp] = true;
		break;
	case PowerUps::Bomb:
		m_powerUps[firstPowerUp + 1] = true;
		break;
	case PowerUps::RollerSkates:
		m_powerUps[firstPowerUp + 2] = true;
		break;
	case PowerUps::RemoteControl:
		m_powerUps[firstPowerUp + 3] = true;
		break;
	case PowerUps::PaintedBomb:
		m_powerUps[firstPowerUp + 4] = true;
		break;
	case PowerUps::Character:
		m_powerUps[firstPowerUp + 5] = true;
		break;
	case PowerUps::PaintedWall:
		m_powerUps[firstPowerUp + 6] = true;
		break;
	case PowerUps::Jacket:
		m_powerUps[firstPowerUp + 7] = true;
		break;
	default:
		break;
	}
}

