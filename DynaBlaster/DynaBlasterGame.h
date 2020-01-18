#pragma once
#include "TileMap.h"
#include "EnemySFML.h"
#include "PlayerSFML.h"

struct TemporarVector
{
	std::vector<sf::Vector2f> blocks;
	std::vector<bool> blocksType;
};

class DynaBlasterGame
{
public:
	enum class Directions
	{
		Up,
		Down,
		Left,
		Right
	};

public:
	void Run();
	DynaBlasterGame();

private:
	void LevelsMenuWindow();
	void HelpMenuWindow();
	void StartWindow();
	void GameWindow();
	void DrawBombExplosion(std::vector<EnemySFML>& enemiesVector, PlayerSFML& player, std::vector<sf::RectangleShape>& grassRectangleVector);
	void Collision(const Directions direction, const sf::Vector2f& temporarVec, const TemporarVector& blocks, std::vector<sf::RectangleShape>& grass);
	sf::View CameraMovement(const sf::Vector2f& position) const;
	void LoadingFromFile();

private:
	TileMap m_map;

	sf::RenderWindow m_window;
	sf::View m_view;
	sf::Vector2f m_cameraPosition;

	sf::RectangleShape m_bombRectangle;
	sf::RectangleShape m_bombExplosion;
	sf::RectangleShape m_rewardRectangle;
	sf::RectangleShape m_portalRectangle;
	sf::RectangleShape m_wallFlickerRectangle;
	sf::RectangleShape m_grassRectangle;

	sf::Texture m_rewardTexture;
	sf::Texture m_portalTexture;
	sf::Texture m_wallFlickerTexture;
	sf::Texture m_wallTexture;
	sf::Texture m_grassTexture;
	sf::Texture m_scoreBarTexture;
	sf::Texture m_explosionTexture;
	sf::Texture m_smallBombTexture;
	sf::Texture m_bigBombTexture;

	sf::Music m_music;

	PlayerSFML m_player;

	std::vector<EnemySFML> m_enemyVector;

	sf::Sprite m_scoreBarSprite;

	sf::Font m_collegedFont;
	uint16_t m_fontSize;

	std::vector<sf::RectangleShape> m_grassRectangleVector;
	std::vector<sf::Vector2f> m_explosionPositionVector;

	sf::Vector2u m_windowDimensions;
	uint16_t m_mapNumberOfLines;
	uint16_t m_mapNumberOfColumns;
	uint16_t m_tileDimension = 48;
	float m_scoreBarDimension;

	sf::Text m_livesText;
	sf::Text m_scoreText;
	sf::Text m_timeText;
	sf::Text m_highScoreText;

	sf::Clock m_clock;
	int m_minutes;
	int m_seconds;
	int m_score;

	int m_index;
	bool m_isActive = false;
	bool m_justExplosion;
};