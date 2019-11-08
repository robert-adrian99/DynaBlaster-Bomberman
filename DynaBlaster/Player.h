#pragma once
#include "PowerUps.h"
#include "Map.h"
#include <cstdint>
#include <array>

class Player : Map
{
public:
	using Position = std::pair<uint16_t, uint16_t>;

public:
	enum class PlayerMovementType
	{
		Up,
		Down,
		Left,
		Right,
		None
	};

public:
	Player();
	uint8_t GetLives() const;
	uint8_t GetSpeed() const;
	uint32_t GetScore() const;
	uint32_t GetHighScore() const;
	uint8_t GetExplosionRange() const;
	uint8_t GetNumberOfBombs() const;
	bool GetPowerUp(PowerUps powerUp) const;
	void SetPowerUp(PowerUps powerUp);
	bool Die();
	void Move(PlayerMovementType playerMovement);

private:
	char m_playerSymbol;
	uint8_t m_lives;
	uint8_t m_speed;
	uint32_t m_score;
	uint32_t m_highScore;
	uint8_t m_explosionRange;
	uint8_t m_numberOfBombs;
	std::array<bool, 8> m_powerUps;
	static const uint8_t firstPowerUp = 0;
	Position m_playerPosition;
};

