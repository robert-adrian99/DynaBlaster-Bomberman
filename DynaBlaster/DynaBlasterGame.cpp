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

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	std::vector<Button> levelButtons;

	int nrLevel = 1;

	for (auto line = 0; line < 4; line++)
	{
		for (auto column = 0; column < 4; column++)
		{
			char chrLvl = nrLevel + '0';
			std::string levelString = "Level ";
			levelString += chrLvl;
			Button levelButton(levelString, { 200,40 }, 20, sf::Color::Transparent, sf::Color::Red);
			int positionX = 200 * line + 100;
			int positionY = 50 * column + 30;
			sf::Vector2f position(positionX, positionY);
			levelButton.SetPosition(position);
			levelButton.SetFont(colleged);
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
						levelButtons[index].SetFontSize(23);
					}
					else
					{
						levelButtons[index].SetFontSize(20);
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

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	Button back("Back", { 100,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	back.SetPosition({ 50,638 });
	back.SetFont(colleged);

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
					back.SetFontSize(23);
				}
				else
				{
					back.SetFontSize(20);
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

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	Button play("Play", { 265,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	play.SetPosition({ 275,480 });
	play.SetFont(colleged);

	Button battle("Battle", { 225,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	battle.SetPosition({ 270,525 });
	battle.SetFont(colleged);

	Button level("Levels", { 170,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	level.SetPosition({ 285,570 });
	level.SetFont(colleged);

	Button help("Help", { 200,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	help.SetPosition({ 290,618 });
	help.SetFont(colleged);

	logger.Log("Buttons added to the window.", Logger::Level::Info);


	sf::Music startSong;
	if (!startSong.openFromFile("StartSong.ogg"))
		logger.Log("Couldn't play the song.", Logger::Level::Error);
	startSong.play();
	startSong.setLoop(true);

	int contor = 0;
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
					help.SetFontSize(23);
				}
				else
				{
					help.SetFontSize(20);
				}
				if (play.IsMouseOver(m_window))
				{
					play.SetFontSize(23);
				}
				else
				{
					play.SetFontSize(20);
				}
				if (level.IsMouseOver(m_window))
				{
					level.SetFontSize(23);
				}
				else
				{
					level.SetFontSize(20);
				}
				if (battle.IsMouseOver(m_window))
				{
					battle.SetFontSize(23);
				}
				else
				{
					battle.SetFontSize(20);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && help.IsMouseOver(m_window))
				{
					logger.Log("Help button was pressed.", Logger::Level::Info);
					startSong.pause();
					HelpMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && play.IsMouseOver(m_window))
				{
					logger.Log("Play button was pressed.", Logger::Level::Info);
					startSong.pause();
					GameWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && level.IsMouseOver(m_window))
				{
					logger.Log("Levels button was pressed.", Logger::Level::Info);
					startSong.pause();
					LevelsMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && battle.IsMouseOver(m_window))
				{
					logger.Log("Battle button was pressed.", Logger::Level::Info);
					startSong.pause();
					GameWindow();
				}
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::M)
				{
					contor++;
					if (contor % 2 == 1)
					{
						startSong.pause();
					}
					else
					{
						startSong.play();
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

	std::vector<int> bombVector = { 0, 1, 2, 3 };

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	m_window.setKeyRepeatEnabled(true);

	sf::Texture scoreBarTxt;
	scoreBarTxt.loadFromFile("ScoreBar.png");

	sf::Sprite scoreBar;
	scoreBar.setTexture(scoreBarTxt);

	lives.setPosition(433, 13);
	lives.setFont(colleged);
	lives.setCharacterSize(22);
	lives.setString("3");
	lives.setOutlineColor(sf::Color::White);

	score.setPosition(145, 13);
	score.setFont(colleged);
	score.setCharacterSize(22);
	score.setString("0");
	score.setOutlineColor(sf::Color::White);

	highScore.setPosition(600, 13);
	highScore.setFont(colleged);
	highScore.setCharacterSize(22);
	highScore.setString("0");
	highScore.setOutlineColor(sf::Color::White);


	time.setPosition(310, 13);
	time.setFont(colleged);
	time.setCharacterSize(22);
	time.setOutlineColor(sf::Color::White);

	map.Map();
	map.setPosition(0.0f, 50.0f);
	PlayerSFML player;
	EnemySFML enemy(EnemyType::Barom, map);
	EnemySFML enemy2(EnemyType::Barom, map);
	std::vector<EnemySFML> enemyVector;
	enemyVector.push_back(enemy);
	enemyVector.push_back(enemy2);
	player.SetMap(map);



	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rowRandom(1, map.GetRectVecTemporar().size() - 1);
	int randomPositionForReward = rowRandom(rng);
	rewardRectangle.setPosition({ map.GetRectVecTemporar()[randomPositionForReward] });

	Button back("Back", { 100,35 }, 20, sf::Color::Transparent, sf::Color::White);
	back.SetFont(colleged);
	back.SetPosition({ 50, 678 });


	sf::Music mapSong;
	mapSong.openFromFile("MapDisplay.ogg");
	if (!mapSong.openFromFile("MapDisplay.ogg"))
		logger.Log("Couldn't play the song.", Logger::Level::Error);
	mapSong.play();
	mapSong.setLoop(true);
	int contor = 0;
	bool spacePressed = false;
	bool bombIsActive = false;
	bool bigOrSmall = true;
	bool explosionReady = false;
	int wait = 100;
	sf::Vector2f pPosition;
	sf::Vector2f bombPosition;
	std::chrono::steady_clock::time_point bombTimer = std::chrono::steady_clock::now() + std::chrono::seconds(6);

	m_minutes = 3;
	m_seconds = 0;

	sf::Texture bombTexture;
	sf::Texture explosionTexture;
	if (!explosionTexture.loadFromFile("Explosion1.png", { 0 * 48, 0 * 48, 48 , 48 }))
		std::cout << "Error" << std::endl;

	if (!rewardTexture.loadFromFile("1-Up.png", { 0 * 48, 0 * 48, 48 , 48 }))
		std::cout << "Error" << std::endl;
	rewardRectangle.setSize({ 48,48 });
	//rewardRectangle.setPosition({ 48,98 });
	rewardRectangle.setTexture(&rewardTexture);

	while (m_window.isOpen())
	{
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
					back.SetFontSize(23);
				}
				else
				{
					back.SetFontSize(20);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && back.IsMouseOver(m_window))
				{
					logger.Log("Back button was pressed. Going back to start page.", Logger::Level::Info);
					map.ResetMap();
					mapSong.stop();
					StartWindow();
				}
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::M)
				{
					contor++;
					if (contor % 2 == 1)
					{
						mapSong.pause();
					}
					else
					{
						mapSong.play();
					}
				}
				if (event.key.code == sf::Keyboard::Escape)
					m_window.close();
				if (event.key.code == sf::Keyboard::Space)
				{
					if (bombIsActive == false)
					{
						bombTimer = std::chrono::steady_clock::now() + std::chrono::seconds(6);
						pPosition = player.GetPosition();

						int xP = (pPosition.x + 24.f) / 48.00;
						pPosition.x = xP * 48;
						int yP = (pPosition.y - 50.f + 24.f) / 48.f;
						pPosition.y = (yP * 48) + 50;

						player.allowToMove = true;
						for (auto& enemy : enemyVector)
						{
							enemy.allowToMove = true;
						}
						pPosition.y -= 50.f;
						if (!player.bombRect.empty())
							player.bombRect.pop_back();
						player.SetBombRect(pPosition);
						for (auto& enemy : enemyVector)
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

		int timer = clock.getElapsedTime().asSeconds();
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
				time.setString(std::to_string(m_minutes) + ":" + "0" + std::to_string(m_seconds));
			else
				time.setString(std::to_string(m_minutes) + ":" + std::to_string(m_seconds));
			clock.restart();
		}
		m_window.draw(scoreBar);
		m_window.draw(lives);
		m_window.draw(score);
		m_window.draw(time);
		m_window.draw(highScore);
		m_window.draw(map);
		
		player.Move();
		for (auto& enemy : enemyVector)
		{
			enemy.Movement();
		}
		for (auto grass : grassRectangle)
			m_window.draw(grass);

		if (spacePressed == true && std::chrono::steady_clock::now() < bombTimer - std::chrono::seconds(1))
		{

			if (bigOrSmall == true)
			{
				if (!bombTexture.loadFromFile("Bomb.png", { 0 * 48, 0 * 48, 48 , 48 }))
					std::cout << "Error" << std::endl;
			}
			else
			{
				if (!bombTexture.loadFromFile("BigBomb.png", { 0 * 48, 0 * 48, 48 , 48 }))
					std::cout << "Error" << std::endl;
			}
			bombRect.setSize({ 48,48 });
			bombRect.setPosition(pPosition);
			bombPosition = bombRect.getPosition();
			bombRect.setTexture(&bombTexture);
			m_window.draw(bombRect);
			if (wait >= 0)
			{
				wait--;
			}
			else
			{
				bigOrSmall = !bigOrSmall;
				wait = 100;
			}
		}
		if (spacePressed == true && std::chrono::steady_clock::now() > bombTimer - std::chrono::seconds(1))
		{
			spacePressed = false;
			bombIsActive = false;
			bombRect.setTexture(&bombTexture);
			explosionReady = true;
			justExplosion = false;
		}
		if (explosionReady == true && justExplosion == false && std::chrono::steady_clock::now() < bombTimer)
		{
			justExplosion = true;
			bombExplosion.setSize({ 48,48 });
			bombExplosion.setPosition(bombPosition);
			bombExplosion.setTexture(&explosionTexture);
			m_window.draw(bombExplosion);
			DrawBombExplosion(enemyVector, player, grassRectangle);
		}
		if (explosionReady == true && std::chrono::steady_clock::now() < bombTimer)
		{
			/*bombExplosion.setSize({ 48,48 });
			bombExplosion.setPosition(bombPosition);
			bombExplosion.setTexture(&explosionTexture);
			m_window.draw(bombExplosion);
			DrawBombExplosion(enemy, grassRectangle);*/
			for (auto& explosion : explosionPositions)
			{
				bombExplosion.setPosition(explosion);
				m_window.draw(bombExplosion);
			}
		}
		if (explosionReady == true && std::chrono::steady_clock::now() > bombTimer)
		{
			if (!player.bombRect.empty())
				player.bombRect.pop_back();

			if (!enemy.bombRect.empty())
				enemy.bombRect.pop_back();

			if (!enemy2.bombRect.empty())
				enemy2.bombRect.pop_back();

			explosionReady = false;
			spacePressed = false;
			isActive = false;
			explosionPositions.clear();

		}
		if (player.GetActive())
			m_window.draw(player.player);
		for (auto& enemy : enemyVector)
		{
			if (enemy.GetActive())
				m_window.draw(enemy.enemy);
		}
		back.DrawTo(m_window);
		m_window.display();
		m_window.clear();
	}
}

void DynaBlasterGame::Collision(const Directions direction, const sf::Vector2f& temporarVec, const TemporarVector& blocks, PlayerSFML& player, std::vector<EnemySFML>& enemies, std::vector<sf::RectangleShape>& grass)
{
	int dimension = 2;
	sf::Vector2f tempExplosion;
	sf::RectangleShape grassRectangle;
	grassRectangle.setSize({ 48,48 });
	grassRectangle.setTexture(&grassTexture);

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
		tempExplosion.x = bombRect.getPosition().x + modifyX * (48 * index);
		tempExplosion.y = bombRect.getPosition().y + modifyY * (48 * index);

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
			explosionPositions.push_back(tempExplosion);
		}
		else
		{
			if (blocks.blocksType[m_index] == 1 && blocks.blocks[m_index] == rewardRectangle.getPosition())
			{
				rewardRectangle.setPosition({ rewardRectangle.getPosition().x, rewardRectangle.getPosition().y + 50 });
				rewardRectangle.setTexture(&rewardTexture);
				grass.push_back(rewardRectangle);
				map.SetRectVecTemp(blocks.blocks[m_index]);
				explosionPositions.push_back(tempExplosion);
			}
			else 
				if (blocks.blocksType[m_index] == 1)
				{
					grassRectangle.setPosition({ blocks.blocks[m_index].x, blocks.blocks[m_index].y + 50 });
					grass.push_back(grassRectangle);
					map.SetRectVecTemp(blocks.blocks[m_index]);
					explosionPositions.push_back(tempExplosion);
				}
		}

		for (auto& enemy : enemies)
		{
			if (tempExplosion.x < enemy.enemy.getPosition().x + 48 &&
				tempExplosion.x + 48 > enemy.enemy.getPosition().x&&
				tempExplosion.y < enemy.enemy.getPosition().y + 98 &&
				tempExplosion.y + 48 > enemy.enemy.getPosition().y + 50)
			{
				enemy.EnemyDie();
				m_score += 200;
				score.setString(std::to_string(m_score));
			}
		}
		if (tempExplosion.x < player.player.getPosition().x + 48 &&
			tempExplosion.x + 48 > player.player.getPosition().x&&
			tempExplosion.y < player.player.getPosition().y + 98 &&
			tempExplosion.y + 48 > player.player.getPosition().y + 50)
		{
			player.PlayerDie();
			lives.setString(std::to_string(player.GetLives()));
		}
	}
}

void DynaBlasterGame::DrawBombExplosion(std::vector<EnemySFML>& enemies, PlayerSFML& player, std::vector<sf::RectangleShape>& grass)
{
	sf::Vector2f tempExplosion;

	sf::RectangleShape grassRectangle;
	grassRectangle.setSize({ 48,48 });
	grassRectangle.setTexture(&grassTexture);
	
	rewardRectangle.setSize({ 48,48 });
	rewardRectangle.setTexture(&rewardTexture);

	TemporarVector blocks;
	blocks.blocks = map.GetRectVec();
	for (int index = 0; index < blocks.blocks.size(); index++)
		blocks.blocksType.push_back(0);

	for (int index = 0; index < map.GetRectVecTemporar().size(); index++)
	{
		blocks.blocks.push_back(map.GetRectVecTemporar()[index]);
		blocks.blocksType.push_back(1);
	}
	explosionPositions.push_back(bombRect.getPosition());
	

	int dimension = 3;
	okDown = okLeft = okRight = okUp = true;
	tempExplosion.x = bombRect.getPosition().x;
	tempExplosion.y = bombRect.getPosition().y;

	Collision(Directions::Up, tempExplosion, blocks, player, enemies, grass);
	Collision(Directions::Down, tempExplosion, blocks, player, enemies, grass);
	Collision(Directions::Left, tempExplosion, blocks, player, enemies, grass);
	Collision(Directions::Right, tempExplosion, blocks, player, enemies, grass);
}

void DynaBlasterGame::Run()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	m_window.create(sf::VideoMode(720, 698), "Dyna Blaster - Bomberman", sf::Style::Close | sf::Style::Titlebar);

	logger.Log("Start window was rendered.", Logger::Level::Info);

	if (!grassTexture.loadFromFile("tileset.png", { 0 * 48, 0 * 48, 48 , 48 }))
		std::cout << "Error" << std::endl;

	StartWindow();
}

DynaBlasterGame::DynaBlasterGame()
{
	
}
