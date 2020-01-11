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
#include "EnemySFML.h"

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
			case::sf::Event::MouseMoved:
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

	bool playMusic = false;
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
					playMusic = !playMusic;
					if (playMusic == true)
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

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	m_window.setKeyRepeatEnabled(true);

	sf::Texture scoreBarTxt;
	scoreBarTxt.loadFromFile("ScoreBar.png");

	sf::Sprite scoreBar;
	scoreBar.setTexture(scoreBarTxt);

	map.Map();
	map.setPosition(0.0f, 50.0f);
	PlayerSFML player;
	EnemySFML enemy(EnemyType::Barom, map);
	player.SetMap(map);

	Button back("Back", { 100,35 }, 20, sf::Color::Transparent, sf::Color::White);
	back.SetFont(colleged);
	back.SetPosition({ 50, 678 });

	sf::Music mapSong;
	mapSong.openFromFile("MapDisplay.ogg");
	if (!mapSong.openFromFile("MapDisplay.ogg"))
		logger.Log("Couldn't play the song.", Logger::Level::Error);
	mapSong.play();
	mapSong.setLoop(true);

	bool playMusic = false;
	bool spacePressed = false;
	bool bombIsActive = false;
	bool bigOrSmall = true;
	bool explosionReady = false;
	int wait = 100;
	sf::Vector2f pPosition;
	sf::Vector2f bombPosition;
	std::chrono::steady_clock::time_point bombTimer = std::chrono::steady_clock::now() + std::chrono::seconds(6);

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
					StartWindow();
				}
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::M)
				{
					playMusic = !playMusic;
					if (playMusic == true)
					{
						mapSong.pause();
					}
					else
					{
						mapSong.play();
					}
				}
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

						player.ok = true;
						pPosition.y -= 50.f;
						if (!player.bombRect.empty())
							player.bombRect.pop_back();
						player.SetBombRect(pPosition);
						if (!enemy.bombRect.empty())
							enemy.bombRect.pop_back();
						enemy.bombRect.push_back(pPosition);
						pPosition.y += 50.f;
						bombIsActive = true;
						explosionReady = false;
					}
					spacePressed = true;
				}
				break;
			}
		}
		m_window.draw(map);
		m_window.draw(scoreBar);
		player.Move();
		enemy.Movement();

		sf::Texture bombTexture;
		sf::Texture explosionTexture;
		if (!explosionTexture.loadFromFile("Explosion1.png", { 0 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
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
		}
		if (explosionReady == true && std::chrono::steady_clock::now() < bombTimer)
		{
			bombExplosion.setSize({ 48,48 });
			bombExplosion.setPosition(bombPosition);
			bombExplosion.setTexture(&explosionTexture);
			DrawBombExplosion(enemy);
		}
		if (explosionReady == true && std::chrono::steady_clock::now() > bombTimer)
		{
			if (!player.bombRect.empty())
				player.bombRect.pop_back();

			explosionReady = false;
			spacePressed = false;
		}
		m_window.draw(player.player);
		if (enemy.GetActive())
			m_window.draw(enemy.enemy);
		back.DrawTo(m_window);
		m_window.display();
		m_window.clear();
	}
}
struct TemporarVector
{
	std::vector<sf::Vector2f> blocks;
	std::vector<bool> blocksType;
};
void DynaBlasterGame::DrawBombExplosion(EnemySFML& enemy)
{
	//prima pozitie = bomba actual;
	//pe a 2-a pozitie = bomba.x + 48;
	std::vector<sf::Vector2f> explosionPositions;
	sf::Vector2f tempExplosion;
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
	int explosionRange = 2;
	okDown = okLeft = okRight = okUp = true;
	for (int index = 0; index < explosionRange; index++)
	{

		tempExplosion.x = bombRect.getPosition().x + 48 * index;
		tempExplosion.y = bombRect.getPosition().y;

		for (const auto& wallrect : blocks.blocks)
		{
			if (tempExplosion.x < wallrect.x + 48 &&
				tempExplosion.x + 48 > wallrect.x&&
				tempExplosion.y < wallrect.y + 98 &&
				tempExplosion.y + 48 > wallrect.y + 50)
			{
				okRight = false;
				break;
			}
			if (okRight == true)
			{

				explosionPositions.push_back(tempExplosion);
			}
		}
		if (tempExplosion.x < enemy.enemy.getPosition().x + 48 &&
			tempExplosion.x + 48 > enemy.enemy.getPosition().x&&
			tempExplosion.y < enemy.enemy.getPosition().y + 98 &&
			tempExplosion.y + 48 > enemy.enemy.getPosition().y + 50)
		{
			enemy.EnemyDie();
		}
	}
	for (int index = 0; index < explosionRange; index++)
	{

		tempExplosion.x = bombRect.getPosition().x - 48 * index;
		tempExplosion.y = bombRect.getPosition().y;

		for (const auto& wallrect : blocks.blocks)
		{
			if (tempExplosion.x < wallrect.x + 48 &&
				tempExplosion.x + 48 > wallrect.x&&
				tempExplosion.y < wallrect.y + 98 &&
				tempExplosion.y + 48 > wallrect.y + 50)
			{
				okLeft = false;
			}
			if (okLeft == true)
			{
				explosionPositions.push_back(tempExplosion);
			}
		}
		if (tempExplosion.x < enemy.enemy.getPosition().x + 48 &&
			tempExplosion.x + 48 > enemy.enemy.getPosition().x&&
			tempExplosion.y < enemy.enemy.getPosition().y + 98 &&
			tempExplosion.y + 48 > enemy.enemy.getPosition().y + 50)
		{
			enemy.EnemyDie();
		}
	}
	for (int index = 0; index < explosionRange; index++)
	{
		tempExplosion.x = bombRect.getPosition().x;
		tempExplosion.y = bombRect.getPosition().y + 48 * index;

		for (const auto& wallrect : blocks.blocks)
		{
			if (tempExplosion.x < wallrect.x + 48 &&
				tempExplosion.x + 48 > wallrect.x&&
				tempExplosion.y < wallrect.y + 98 &&
				tempExplosion.y + 48 > wallrect.y + 50)
			{
				okDown = false;
				break;
			}
			if (okDown == true)
			{
				explosionPositions.push_back(tempExplosion);
			}
		}
		if (tempExplosion.x < enemy.enemy.getPosition().x + 48 &&
			tempExplosion.x + 48 > enemy.enemy.getPosition().x&&
			tempExplosion.y < enemy.enemy.getPosition().y + 98 &&
			tempExplosion.y + 48 > enemy.enemy.getPosition().y + 50)
		{
			enemy.EnemyDie();
		}
	}

	for (int index = 0; index < explosionRange; index++)
	{
		tempExplosion.x = bombRect.getPosition().x;
		tempExplosion.y = bombRect.getPosition().y - 48 * index;

		for (const auto& wallrect : blocks.blocks)
		{
			if (tempExplosion.x < wallrect.x + 48 &&
				tempExplosion.x + 48 > wallrect.x&&
				tempExplosion.y < wallrect.y + 98 &&
				tempExplosion.y + 48 > wallrect.y + 50)
			{
				okUp = false;
				break;
			}
			if (okUp == true)
			{
				explosionPositions.push_back(tempExplosion);
			}
		}
		if (tempExplosion.x < enemy.enemy.getPosition().x + 48 &&
			tempExplosion.x + 48 > enemy.enemy.getPosition().x&&
			tempExplosion.y < enemy.enemy.getPosition().y + 98 &&
			tempExplosion.y + 48 > enemy.enemy.getPosition().y + 50)
		{
			enemy.EnemyDie();
		}
	}
	for (auto& explosion : explosionPositions)
	{
		bombExplosion.setPosition(explosion);
		m_window.draw(bombExplosion);
	}
}


void DynaBlasterGame::Run()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	m_window.create(sf::VideoMode(720, 698), "Dyna Blaster - Bomberman", sf::Style::Close | sf::Style::Titlebar);

	logger.Log("Start window was rendered.", Logger::Level::Info);

	StartWindow();
}
