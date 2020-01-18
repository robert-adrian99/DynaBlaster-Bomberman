#include "DynaBlasterGame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "Button.h"
#include "../Logging/Logger.h"
#include "PlayerSFML.h"
#include <iostream>
#include <chrono>
#include <array>
#include <sstream>

void DynaBlasterGame::LevelsMenuWindow()
{

	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	m_window.setTitle("Levels Menu");

	logger.Log("Levels window was rendered", Logger::Level::Info);

	m_collegedFont.loadFromFile("colleged.ttf");

	std::vector<Button> levelButtons;

	int nrLevel = 1;

	for (auto line = 0; line < 4; line++)
	{
		for (auto column = 0; column < 4; column++)
		{
			char chrLvl = nrLevel + '0';
			std::string levelString = "Level ";
			levelString += chrLvl;
			Button levelButton(levelString, { 200,40 }, m_fontSize, sf::Color::Transparent, sf::Color::Red);
			int positionX = 200 * line + 100;
			int positionY = 50 * column + 30;
			sf::Vector2f position(positionX, positionY);
			levelButton.SetPosition(position);
			levelButton.SetFont(m_collegedFont);
			levelButtons.push_back(levelButton);
			++nrLevel;
		}
	}

	logger.Log("Displayed the levels of the game.", Logger::Level::Info);

	while (m_window.isOpen())
	{
		sf::Event event;
		sf::Texture LevelsImage;
		LevelsImage.loadFromFile("levels.png");

		sf::Sprite sprite(LevelsImage);

		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseMoved:
				for (int index = 0; index < 8; index++)
				{
					if (levelButtons[index].IsMouseOver(m_window))
					{
						levelButtons[index].SetFontSize(m_fontSize + 3);
					}
					else
					{
						levelButtons[index].SetFontSize(m_fontSize);
					}
				}
			case sf::Event::MouseButtonPressed:
				for (int index = 0; index < 8; index++)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && levelButtons[index].IsMouseOver(m_window))
					{
						logger.Log("Level button was pressed. Going back to start page.", Logger::Level::Info);
						GameWindow();
					}
				}
			}
		}
		m_window.clear();
		m_window.draw(sprite);
		for (int index = 0; index < 8; index++)
		{
			levelButtons[index].DrawTo(m_window);
		}
		m_window.display();
	}
}

void DynaBlasterGame::HelpMenuWindow()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);


	m_window.setTitle("Help Menu");

	logger.Log("Help window was rendered.", Logger::Level::Info);

	m_collegedFont.loadFromFile("colleged.ttf");

	Button back("Back", { 100,35 }, m_fontSize, sf::Color::Transparent, sf::Color::Black);
	back.SetPosition({ 50,638 });
	back.SetFont(m_collegedFont);

	logger.Log("Displayed the information about the game.", Logger::Level::Info);

	while (m_window.isOpen())
	{
		sf::Event event;
		sf::Texture HelpImage;
		HelpImage.loadFromFile("HelpMenu.png");

		sf::Sprite sprite(HelpImage);

		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseMoved:
				if (back.IsMouseOver(m_window))
				{
					back.SetFontSize(m_fontSize + 3);
				}
				else
				{
					back.SetFontSize(m_fontSize);
				}
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && back.IsMouseOver(m_window))
				{
					logger.Log("Back button was pressed. Going back to the start page.", Logger::Level::Info);
					StartWindow();
				}
			}
		}
		m_window.clear();
		m_window.draw(sprite);
		back.DrawTo(m_window);
		m_window.display();
	}
}

void DynaBlasterGame::StartWindow()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	Button play("Play", { 265,35 }, m_fontSize, sf::Color::Transparent, sf::Color::Black);
	play.SetPosition({ 275,480 });
	play.SetFont(m_collegedFont);

	Button battle("Battle", { 225,35 }, m_fontSize, sf::Color::Transparent, sf::Color::Black);
	battle.SetPosition({ 270,525 });
	battle.SetFont(m_collegedFont);

	Button level("Levels", { 170,35 }, m_fontSize, sf::Color::Transparent, sf::Color::Black);
	level.SetPosition({ 285,570 });
	level.SetFont(m_collegedFont);

	Button help("Help", { 200,35 }, m_fontSize, sf::Color::Transparent, sf::Color::Black);
	help.SetPosition({ 290,618 });
	help.SetFont(m_collegedFont);

	logger.Log("Buttons added to the window.", Logger::Level::Info);

	m_music.play();
	m_music.setLoop(true);

	bool musicPlays = true;

	while (m_window.isOpen())
	{
		sf::Event event;
		sf::Texture StartImage;
		StartImage.loadFromFile("StartPage.png");

		sf::Sprite sprite(StartImage);
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseMoved:
				if (help.IsMouseOver(m_window))
				{
					help.SetFontSize(m_fontSize + 3);
				}
				else
				{
					help.SetFontSize(m_fontSize);
				}
				if (play.IsMouseOver(m_window))
				{
					play.SetFontSize(m_fontSize + 3);
				}
				else
				{
					play.SetFontSize(m_fontSize);
				}
				if (level.IsMouseOver(m_window))
				{
					level.SetFontSize(m_fontSize + 3);
				}
				else
				{
					level.SetFontSize(m_fontSize);
				}
				if (battle.IsMouseOver(m_window))
				{
					battle.SetFontSize(m_fontSize + 3);
				}
				else
				{
					battle.SetFontSize(m_fontSize);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && help.IsMouseOver(m_window))
				{
					logger.Log("Help button was pressed.", Logger::Level::Info);
					m_music.pause();
					HelpMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && play.IsMouseOver(m_window))
				{
					logger.Log("Play button was pressed.", Logger::Level::Info);
					m_music.pause();
					GameWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && level.IsMouseOver(m_window))
				{
					logger.Log("Levels button was pressed.", Logger::Level::Info);
					m_music.pause();
					LevelsMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && battle.IsMouseOver(m_window))
				{
					logger.Log("Battle button was pressed.", Logger::Level::Info);
					m_music.pause();
					GameWindow();
				}
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::M)
				{
					musicPlays = !musicPlays;
					if (musicPlays == false)
					{
						m_music.pause();
					}
					else
					{
						m_music.play();
					}
				}
				break;
			}
		}
		m_window.clear();
		m_window.draw(sprite);
		help.DrawTo(m_window);
		play.DrawTo(m_window);
		level.DrawTo(m_window);
		battle.DrawTo(m_window);
		m_window.display();
	}
}

void DynaBlasterGame::GameWindow()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	m_map.Map();
	m_map.setPosition(0.0f, 50.0f);
	m_player.SetMap(m_map);

	m_window.setKeyRepeatEnabled(true);

	m_scoreBarSprite.setTexture(m_scoreBarTexture);

	Button back("Back", { 100,35 }, 20, sf::Color::Transparent, sf::Color::White);
	back.SetFont(m_collegedFont);
	back.SetPosition({ 50, 678 });

	if (!m_music.openFromFile("MapDisplay.ogg"))
		logger.Log("Couldn't play the song.", Logger::Level::Error);
	m_music.play();
	m_music.setLoop(true);

	sf::Vector2f pPosition;
	sf::Vector2f bombPosition;
	std::chrono::steady_clock::time_point bombTimer = std::chrono::steady_clock::now() + std::chrono::seconds(6);

	m_minutes = 4;
	m_seconds = 0;

	EnemySFML enemy(EnemyType::Barom, m_map);
	EnemySFML enemy2(EnemyType::Barom, m_map);
	EnemySFML enemy3(EnemyType::Barom, m_map);

	m_enemyVector.emplace_back(enemy);
	m_enemyVector.emplace_back(enemy2);
	m_enemyVector.emplace_back(enemy3);

	int numberOfEnemies = m_enemyVector.size();
	bool musicPlays = true;
	bool spacePressed = false;
	bool bombIsActive = false;
	bool explosionReady = false;
	bool bigOrSmall = true;
	bool flickerOrNot = true;
	int waitToFlickerBomb = 100;
	int waitToFlickerWall = 100;

	while (m_window.isOpen())
	{
		m_window.draw(m_scoreBarSprite);
		m_window.draw(m_livesText);
		m_window.draw(m_scoreText);
		m_window.draw(m_timeText);
		m_window.draw(m_highScoreText);

		m_view.reset(sf::FloatRect(m_cameraPosition.x, m_cameraPosition.y, m_windowDimensions.x, m_windowDimensions.y));
		m_window.setView(CameraMovement(m_player.GetPosition()));

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseMoved:
				if (back.IsMouseOver(m_window))
				{
					back.SetFontSize(m_fontSize + 3);
				}
				else
				{
					back.SetFontSize(m_fontSize);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && back.IsMouseOver(m_window))
				{
					logger.Log("Back button was pressed. Going back to start page.", Logger::Level::Info);
					m_map.ResetMap();
					m_enemyVector.clear();
					m_music.stop();
					if (!m_music.openFromFile("StartSong.ogg"))
						logger.Log("Couldn't play the song.", Logger::Level::Error);
					StartWindow();
				}
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::M)
				{
					musicPlays = !musicPlays;
					if (musicPlays == false)
					{
						m_music.pause();
					}
					else
					{
						m_music.play();
					}
				}
				if (event.key.code == sf::Keyboard::Escape)
					m_window.close();
				if (event.key.code == sf::Keyboard::Space)
				{
					if (bombIsActive == false)
					{
						bombTimer = std::chrono::steady_clock::now() + std::chrono::seconds(6);
						pPosition = m_player.GetPosition();

						int xP = (pPosition.x + 24.f) / 48.00;
						pPosition.x = xP * 48;
						int yP = (pPosition.y - 50.f + 24.f) / 48.f;
						pPosition.y = (yP * 48) + 50;

						m_player.allowToMove = true;
						for (auto& enemy : m_enemyVector)
						{
							enemy.allowToMove = true;
						}
						pPosition.y -= 50.f;
						if (!m_player.bombRect.empty())
							m_player.bombRect.pop_back();
						m_player.SetBombRect(pPosition);
						for (auto& enemy : m_enemyVector)
						{
							if (!enemy.bombRect.empty())
								enemy.bombRect.pop_back();
							enemy.bombRect.push_back(pPosition);
						}
						pPosition.y += 50.f;
						bombIsActive = true;
						explosionReady = false;
					}
					spacePressed = true;
				}
				break;
			}
		}

		int timer = m_clock.getElapsedTime().asSeconds();
		if (timer > 0)
		{
			if (m_seconds == 00) {

				m_minutes--;
				m_seconds = 60;
			}
			m_seconds--;
			if (m_minutes == 0 && m_seconds == 0)
				break;
			if (m_seconds < 10)
				m_timeText.setString(std::to_string(m_minutes) + ":" + "0" + std::to_string(m_seconds));
			else
				m_timeText.setString(std::to_string(m_minutes) + ":" + std::to_string(m_seconds));
			m_clock.restart();
		}
		m_window.draw(m_map);
		m_player.Move();
		for (auto& enemy : m_enemyVector)
		{
			enemy.Movement();
			if (m_player.Intersects(enemy.enemy.getPosition()))
			{
				//player.PlayerDie();
				std::cout << "INA";
			}
		}
		for (auto grass : m_grassRectangleVector)
			m_window.draw(grass);

		if (spacePressed == true && std::chrono::steady_clock::now() < bombTimer - std::chrono::seconds(1))
		{

			if (bigOrSmall == true)
			{
				m_bombRectangle.setTexture(&m_smallBombTexture);
			}
			else
			{
				m_bombRectangle.setTexture(&m_bigBombTexture);
			}
			m_bombRectangle.setSize({ 48,48 });
			m_bombRectangle.setPosition(pPosition);
			bombPosition = m_bombRectangle.getPosition();
			m_window.draw(m_bombRectangle);
			if (waitToFlickerBomb >= 0)
			{
				waitToFlickerBomb--;
			}
			else
			{
				bigOrSmall = !bigOrSmall;
				waitToFlickerBomb = 100;
			}
		}
		if (spacePressed == true && std::chrono::steady_clock::now() > bombTimer - std::chrono::seconds(1))
		{
			spacePressed = false;
			bombIsActive = false;
			m_bombRectangle.setTexture(&m_smallBombTexture);
			explosionReady = true;
			m_justExplosion = false;
		}
		if (explosionReady == true && m_justExplosion == false && std::chrono::steady_clock::now() < bombTimer)
		{
			m_justExplosion = true;
			m_bombExplosion.setSize({ 48,48 });
			m_bombExplosion.setPosition(bombPosition);
			m_bombExplosion.setTexture(&m_explosionTexture);
			m_window.draw(m_bombExplosion);
			DrawBombExplosion(m_enemyVector, m_player, m_grassRectangleVector);
		}
		if (explosionReady == true && std::chrono::steady_clock::now() < bombTimer)
		{
			for (auto& explosion : m_explosionPositionVector)
			{
				m_bombExplosion.setPosition(explosion);
				m_window.draw(m_bombExplosion);
			}
			for (auto& enemy : m_enemyVector)
			{
				for (auto& tempExplosion : m_explosionPositionVector)
				{
					if (tempExplosion.x < enemy.enemy.getPosition().x + 48 &&
						tempExplosion.x + 48 > enemy.enemy.getPosition().x&&
						tempExplosion.y < enemy.enemy.getPosition().y + 48 &&
						tempExplosion.y + 48 > enemy.enemy.getPosition().y)
					{
						enemy.EnemyDie();
						m_score += 200;
						m_scoreText.setString(std::to_string(m_score));
						--numberOfEnemies;
					}
				}
			}
			for (auto& tempExplosion : m_explosionPositionVector)
			{
				if (m_player.Intersects(tempExplosion)) {
					std::cout << "BUM";
					//player.PlayerDie();
					m_livesText.setString(std::to_string(m_player.GetLives()));
				}
			}
		}
		if (explosionReady == true && std::chrono::steady_clock::now() > bombTimer)
		{
			if (!m_player.bombRect.empty())
				m_player.bombRect.pop_back();

			for (auto& enemy : m_enemyVector)
			{
				if (!enemy.bombRect.empty())
					enemy.bombRect.pop_back();
			}

			explosionReady = false;
			spacePressed = false;
			m_isActive = false;
			m_explosionPositionVector.clear();

		}

		if (numberOfEnemies == 0 && flickerOrNot == true)
		{
			m_wallFlickerRectangle.setTexture(&m_wallFlickerTexture);
		}
		else
		{
			m_wallFlickerRectangle.setTexture(&m_wallTexture);
		}
		m_window.draw(m_wallFlickerRectangle);
		if (waitToFlickerWall >= 0)
		{
			waitToFlickerWall--;
		}
		else
		{
			flickerOrNot = !flickerOrNot;
			waitToFlickerWall = 100;
		}

		if (m_player.GetActive())
			m_window.draw(m_player.player);

		for (auto& enemy : m_enemyVector)
		{
			if (enemy.GetActive())
				m_window.draw(enemy.enemy);
		}
		back.DrawTo(m_window);
		m_window.display();
		m_window.clear();
	}
}

void DynaBlasterGame::Collision(const Directions direction, const sf::Vector2f& temporarVec, const TemporarVector& blocks, std::vector<sf::RectangleShape>& grass)
{
	int dimension = 2;
	sf::Vector2f tempExplosion;
	
	m_grassRectangle.setSize({ 48,48 });
	m_grassRectangle.setTexture(&m_grassTexture);

	bool okDirection = true;
	int modifyX = 0;
	int modifyY = 0;
	switch (direction)
	{
	case DynaBlasterGame::Directions::Up:
		modifyY = -1;
		break;
	case DynaBlasterGame::Directions::Down:
		modifyY = 1;
		break;
	case DynaBlasterGame::Directions::Left:
		modifyX = -1;
		break;
	case DynaBlasterGame::Directions::Right:
		modifyX = 1;
		break;
	default:
		break;
	}

	for (int index = 1; index < dimension; index++)
	{
		tempExplosion.x = m_bombRectangle.getPosition().x + modifyX * (48 * index);
		tempExplosion.y = m_bombRectangle.getPosition().y + modifyY * (48 * index);

		for (int index1 = 0; index1 < blocks.blocks.size(); index1++)
		{
			if (tempExplosion.x < blocks.blocks[index1].x + 48 &&
				tempExplosion.x + 48 > blocks.blocks[index1].x&&
				tempExplosion.y < blocks.blocks[index1].y + 98 &&
				tempExplosion.y + 48 > blocks.blocks[index1].y + 50)
			{
				okDirection = false;
				m_index = index1;
				break;
			}
		}
		if (okDirection == true)
		{
			m_explosionPositionVector.push_back(tempExplosion);
		}
		else
		{
			if (blocks.blocksType[m_index] == 1 && blocks.blocks[m_index] == m_rewardRectangle.getPosition())
			{
				m_rewardRectangle.setPosition({ m_rewardRectangle.getPosition().x, m_rewardRectangle.getPosition().y + 50 });
				m_rewardRectangle.setTexture(&m_rewardTexture);
				grass.push_back(m_rewardRectangle);
				m_map.SetRectVecTemp(blocks.blocks[m_index]);
				m_explosionPositionVector.push_back(tempExplosion);
				m_wallFlickerRectangle.setPosition({ -48,-48 });
			}
			else if (blocks.blocksType[m_index] == 1 && blocks.blocks[m_index] == m_portalRectangle.getPosition())
			{
				m_portalRectangle.setPosition({ m_portalRectangle.getPosition().x, m_portalRectangle.getPosition().y + 50 });
				m_portalRectangle.setTexture(&m_portalTexture);
				grass.push_back(m_portalRectangle);
				m_map.SetRectVecTemp(blocks.blocks[m_index]);
				m_explosionPositionVector.push_back(tempExplosion);
			}
			else
				if (blocks.blocksType[m_index] == 1)
				{
					m_grassRectangle.setPosition({ blocks.blocks[m_index].x, blocks.blocks[m_index].y + 50 });
					grass.push_back(m_grassRectangle);
					m_map.SetRectVecTemp(blocks.blocks[m_index]);
					m_explosionPositionVector.push_back(tempExplosion);
				}
		}	
	}
}

sf::View DynaBlasterGame::CameraMovement(const sf::Vector2f& position) const
{
	sf::View view;
	view.reset(sf::FloatRect(0, 0, m_windowDimensions.x, m_windowDimensions.y));

	sf::Vector2f cameraPosition(0, 0);
	cameraPosition.x = position.x + m_tileDimension / 2 - (m_windowDimensions.x / 2);
	cameraPosition.y = position.y + m_tileDimension / 2 - (m_windowDimensions.y / 2);

	if (cameraPosition.x > m_mapNumberOfColumns* m_tileDimension - m_windowDimensions.x)
	{
		cameraPosition.x = m_mapNumberOfColumns * m_tileDimension - m_windowDimensions.x;
	}
	if (cameraPosition.y > m_mapNumberOfLines* m_tileDimension - m_windowDimensions.y + m_scoreBarDimension)
	{
		cameraPosition.y = m_mapNumberOfLines * m_tileDimension - m_windowDimensions.y + m_scoreBarDimension;
	}
	if (cameraPosition.x < 0)
	{
		cameraPosition.x = 0;
	}
	if (cameraPosition.y < 0)
	{
		cameraPosition.y = 0;
	}

	return view;
}

void DynaBlasterGame::DrawBombExplosion(std::vector<EnemySFML>& enemies, PlayerSFML& player, std::vector<sf::RectangleShape>& grassRectangleVector)
{
	sf::Vector2f tempExplosion;

	sf::RectangleShape grassRectangle;
	grassRectangle.setSize({ 48,48 });
	grassRectangle.setTexture(&m_grassTexture);

	m_rewardRectangle.setSize({ 48,48 });
	m_rewardRectangle.setTexture(&m_rewardTexture);

	TemporarVector blocks;
	blocks.blocks = m_map.GetRectVec();
	for (int index = 0; index < blocks.blocks.size(); index++)
		blocks.blocksType.push_back(0);

	for (int index = 0; index < m_map.GetRectVecTemporar().size(); index++)
	{
		blocks.blocks.push_back(m_map.GetRectVecTemporar()[index]);
		blocks.blocksType.push_back(1);
	}
	m_explosionPositionVector.push_back(m_bombRectangle.getPosition());
	int dimension = 3;

	tempExplosion.x = m_bombRectangle.getPosition().x;
	tempExplosion.y = m_bombRectangle.getPosition().y;

	Collision(Directions::Up, tempExplosion, blocks, grassRectangleVector);
	Collision(Directions::Down, tempExplosion, blocks, grassRectangleVector);
	Collision(Directions::Left, tempExplosion, blocks, grassRectangleVector);
	Collision(Directions::Right, tempExplosion, blocks, grassRectangleVector);
}

void DynaBlasterGame::Run()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	m_mapNumberOfLines = 27;
	m_mapNumberOfColumns = 29;

	m_window.create(sf::VideoMode(m_windowDimensions.x, m_windowDimensions.y), "Dyna Blaster - Bomberman", sf::Style::Close | sf::Style::Titlebar);

	logger.Log("Start window was rendered.", Logger::Level::Info);

	m_window.setFramerateLimit(500);

	StartWindow();
}

DynaBlasterGame::DynaBlasterGame()
{
	LoadingFromFile();

	m_windowDimensions.x = 720;
	m_windowDimensions.y = 698;

	m_scoreBarDimension = 50.0f;

	m_map.Map();
	m_map.setPosition(0.0f, m_scoreBarDimension);

	m_view.reset(sf::FloatRect(0, 0, m_windowDimensions.x, m_windowDimensions.y));
	m_cameraPosition = { 0,0 };

	m_fontSize = 20;

	m_livesText.setPosition(433, 13);
	m_livesText.setFont(m_collegedFont);
	m_livesText.setCharacterSize(22);
	m_livesText.setString("3");
	m_livesText.setOutlineColor(sf::Color::White);

	m_scoreText.setPosition(145, 13);
	m_scoreText.setFont(m_collegedFont);
	m_scoreText.setCharacterSize(22);
	m_scoreText.setString("0");
	m_scoreText.setOutlineColor(sf::Color::White);

	m_highScoreText.setPosition(600, 13);
	m_highScoreText.setFont(m_collegedFont);
	m_highScoreText.setCharacterSize(22);
	m_highScoreText.setString("0");
	m_highScoreText.setOutlineColor(sf::Color::White);

	m_timeText.setPosition(310, 13);
	m_timeText.setFont(m_collegedFont);
	m_timeText.setCharacterSize(22);
	m_timeText.setOutlineColor(sf::Color::White);

	m_player.SetMap(m_map);


	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rowRandom(0, m_map.GetRectVecTemporar().size() - 1);
	int randomPositionForReward = rowRandom(rng);

	m_rewardRectangle.setPosition({ m_map.GetRectVecTemporar()[randomPositionForReward] });

	m_wallFlickerRectangle.setSize({ 48,48 });
	m_wallFlickerRectangle.setPosition({ m_rewardRectangle.getPosition().x,m_rewardRectangle.getPosition().y + 50 });

	int randomPositionForPortal = rowRandom(rng);
	while (randomPositionForPortal == randomPositionForReward)
	{
		randomPositionForPortal = rowRandom(rng);
	}

	m_portalRectangle.setPosition({ m_map.GetRectVecTemporar()[randomPositionForPortal] });

	m_rewardRectangle.setSize({ 48,48 });
	m_rewardRectangle.setTexture(&m_rewardTexture);

	m_portalRectangle.setSize({ 48,48 });
	m_portalRectangle.setTexture(&m_portalTexture);
}

void DynaBlasterGame::LoadingFromFile()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	if (!m_collegedFont.loadFromFile("colleged.ttf"))
		logger.Log("Error loading the font from file!", Logger::Level::Error);

	if (!m_scoreBarTexture.loadFromFile("ScoreBar.png"))
		logger.Log("Error loading ScoreBarTexture from file!", Logger::Level::Error);

	if (!m_grassTexture.loadFromFile("tileset.png", { 0, 0, m_tileDimension , m_tileDimension }))
		logger.Log("Error loading GrassTexture from file!", Logger::Level::Error);

	if (!m_explosionTexture.loadFromFile("Explosion1.png"))
		logger.Log("Error loading ExplosionTexture from file!", Logger::Level::Error);

	if (!m_smallBombTexture.loadFromFile("Bomb.png"))
		logger.Log("Error loading SmallBombTexture from file!", Logger::Level::Error);

	if (!m_bigBombTexture.loadFromFile("BigBomb.png"))
		logger.Log("Error loading BigBombTexture from file!", Logger::Level::Error);

	if (!m_rewardTexture.loadFromFile("FireUp.png"))
		logger.Log("Error loading BigBombTexture from file!", Logger::Level::Error);
	
	if (!m_portalTexture.loadFromFile("Portal.png"))
		logger.Log("Error loading BigBombTexture from file!", Logger::Level::Error);

	if (!m_music.openFromFile("StartSong.ogg"))
		logger.Log("Couldn't play the song.", Logger::Level::Error);

	if (!m_wallFlickerTexture.loadFromFile("WallFlicker.png"))
		logger.Log("Error loading BigBombTexture from file!", Logger::Level::Error);

	if (!m_wallTexture.loadFromFile("Wall.png"))
		logger.Log("Error loading BigBombTexture from file!", Logger::Level::Error);
}
