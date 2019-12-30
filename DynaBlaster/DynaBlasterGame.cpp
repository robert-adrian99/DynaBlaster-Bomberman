#include "DynaBlasterGame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "Button.h"
#include "../Logging/Logger.h"
#include "PlayerSFML.h"
#include <iostream>
#include <chrono>
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
			case::sf::Event::MouseMoved:
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


	m_window.setKeyRepeatEnabled(true);
	sf::Texture scoreBarTxt;
	scoreBarTxt.loadFromFile("ScoreBar.png");
	sf::Sprite scoreBar;
	scoreBar.setTexture(scoreBarTxt);


	map.Map();
	map.setPosition(0.0f, 50.0f);

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	PlayerSFML player;
	EnemySFML enemy(EnemyType::Barom);

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
	
	while (m_window.isOpen())
	{
		sf::Event event;
		sf::RectangleShape bombRect;
		sf::RectangleShape bombExplosion;

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
						bombIsActive = true;
						explosionReady = false;
					}
					spacePressed = true;
				}
				break;
			}
		}
		m_window.draw(scoreBar);
		m_window.draw(map);
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
			bombRect.setTexture(&bombTexture, true);
			explosionReady = true;
		}
		if (explosionReady == true && std::chrono::steady_clock::now() < bombTimer)
		{
			bombExplosion.setSize({ 48,48 });
			bombExplosion.setPosition(bombPosition);
			bombExplosion.setTexture(&explosionTexture);
			m_window.draw(bombExplosion);
		}
		if (explosionReady == true && std::chrono::steady_clock::now() > bombTimer)
		{
			explosionReady = false;
			spacePressed = false;
		}
		m_window.draw(player.player);
		m_window.draw(enemy.enemy);
		back.DrawTo(m_window);
		m_window.display();
		m_window.clear();
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
