#include "DynaBlasterGame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "Button.h"
#include "../Logging/Logger.h"
#include "PlayerSFML.h"
#include <chrono>

void DynaBlasterGame::LevelsMenuWindow()
{

	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	sf::RenderWindow levelsWindow(sf::VideoMode(564, 286), "Levels Menu", sf::Style::Close | sf::Style::Titlebar);

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

	while (levelsWindow.isOpen())
	{
		sf::Event event;
		sf::Texture LevelsImage;
		LevelsImage.loadFromFile("levels.png");

		sf::Sprite sprite(LevelsImage);

		while (levelsWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				levelsWindow.close();
				break;
			case sf::Event::MouseMoved:
				for (int index = 0; index < 8; index++)
				{
					if (levelButtons[index].IsMouseOver(levelsWindow))
					{
						levelButtons[index].SetBgColor(sf::Color::Blue);
					}
					else
					{
						levelButtons[index].SetBgColor(sf::Color::Transparent);
					}
				}
				break;
			case sf::Event::MouseButtonPressed:
				for (int index = 0; index < 8; index++)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && levelButtons[index].IsMouseOver(levelsWindow))
					{
						logger.Log("Level button was pressed. Going back to start page.", Logger::Level::Info);
						levelsWindow.close();
						GameWindow();
					}
				}
				break;
			}
		}
		levelsWindow.clear();
		levelsWindow.draw(sprite);
		for (int index = 0; index < 8; index++)
		{
			levelButtons[index].DrawTo(levelsWindow);
		}
		levelsWindow.display();
	}
}

void DynaBlasterGame::HelpMenuWindow()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	sf::RenderWindow helpWindow(sf::VideoMode(850, 700), "Help Menu", sf::Style::Close | sf::Style::Titlebar);

	logger.Log("Help window was rendered.", Logger::Level::Info);

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	Button back("Back", { 100,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	back.SetPosition({ 50,638 });
	back.SetFont(colleged);

	logger.Log("Displayed the information about the game.", Logger::Level::Info);

	while (helpWindow.isOpen())
	{
		sf::Event event;
		sf::Texture HelpImage;
		HelpImage.loadFromFile("HelpMenu.png");

		sf::Sprite sprite(HelpImage);

		while (helpWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				helpWindow.close();
				break;
			case sf::Event::MouseMoved:
				if (back.IsMouseOver(helpWindow))
				{
					back.SetFontSize(23);
				}
				else
				{
					back.SetFontSize(20);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && back.IsMouseOver(helpWindow))
				{
					logger.Log("Back button was pressed. Going back to the start page.", Logger::Level::Info);
					helpWindow.close();
					StartWindow();
				}
				break;
			}
		}
		helpWindow.clear();
		helpWindow.draw(sprite);
		back.DrawTo(helpWindow);
		helpWindow.display();
	}
}

void DynaBlasterGame::StartWindow()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	sf::RenderWindow startWindow(sf::VideoMode(850, 700), "Dyna Blaster - Bomberman", sf::Style::Close | sf::Style::Titlebar);

	logger.Log("Start window was rendered.", Logger::Level::Info);

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	Button help("Help", { 200,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	help.SetPosition({ 315,638 });
	help.SetFont(colleged);

	Button play("Play", { 265,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	play.SetPosition({ 280,500 });
	play.SetFont(colleged);

	Button level("Levels", { 170,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	level.SetPosition({ 300,590 });
	level.SetFont(colleged);

	Button battle("Battle", { 225,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	battle.SetPosition({ 295,550 });
	battle.SetFont(colleged);

	logger.Log("Buttons added to the window.", Logger::Level::Info);


	sf::Music startSong;
	if (!startSong.openFromFile("StartSong.ogg"))
		logger.Log("Couldn't play the song.", Logger::Level::Error);
	startSong.play();
	startSong.setLoop(true);
	int contor = 0;
	while (startWindow.isOpen())
	{
		sf::Event event;
		sf::Texture StartImage;
		StartImage.loadFromFile("StartPage.png");

		sf::Sprite sprite(StartImage);
		while (startWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				startWindow.close();
				break;
			case::sf::Event::MouseMoved:
				if (help.IsMouseOver(startWindow))
				{
					help.SetFontSize(23);
				}
				else
				{
					help.SetFontSize(20);
				}
				if (play.IsMouseOver(startWindow))
				{
					play.SetFontSize(23);
				}
				else
				{
					play.SetFontSize(20);
				}
				if (level.IsMouseOver(startWindow))
				{
					level.SetFontSize(23);
				}
				else
				{
					level.SetFontSize(20);
				}
				if (battle.IsMouseOver(startWindow))
				{
					battle.SetFontSize(23);
				}
				else
				{
					battle.SetFontSize(20);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && help.IsMouseOver(startWindow))
				{
					logger.Log("Help button was pressed.", Logger::Level::Info);
					startSong.pause();
					startWindow.close();
					HelpMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && play.IsMouseOver(startWindow))
				{
					logger.Log("Play button was pressed.", Logger::Level::Info);
					startSong.pause();
					startWindow.close();
					GameWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && level.IsMouseOver(startWindow))
				{
					logger.Log("Levels button was pressed.", Logger::Level::Info);
					startSong.pause();
					startWindow.close();
					LevelsMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && battle.IsMouseOver(startWindow))
				{
					logger.Log("Battle button was pressed.", Logger::Level::Info);
					startSong.pause();
					startWindow.close();
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
		startWindow.clear();
		startWindow.draw(sprite);
		help.DrawTo(startWindow);
		play.DrawTo(startWindow);
		level.DrawTo(startWindow);
		battle.DrawTo(startWindow);
		startWindow.display();
	}
}

void DynaBlasterGame::GameWindow()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	sf::RenderWindow window(sf::VideoMode(720, 624), "Dyna Blaster - Bomberman");
	window.setKeyRepeatEnabled(true);
	map.Map();
	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");
	PlayerSFML player;
	Button back("Back", { 100,35 }, 20, sf::Color::Blue, sf::Color::White);
	back.SetFont(colleged);
	back.SetPosition({ 50,638 });

	sf::Music mapSong;
	if (!mapSong.openFromFile("MapDisplay.ogg"))
		logger.Log("Couldn't play the song.", Logger::Level::Error);
	mapSong.play();
	mapSong.setLoop(true);

	int contor = 0;
	bool spacePressed = false;
	bool bombIsActive = false;
	bool bigOrSmall = true;
	int wait = 100;
	sf::Vector2f pPosition;
	std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(5);

	while (window.isOpen())
	{
		sf::Event event;
		sf::RectangleShape bombRect;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				if (back.IsMouseOver(window))
				{
					back.SetBgColor(sf::Color::Green);
				}
				else
				{
					back.SetBgColor(sf::Color::Blue);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && back.IsMouseOver(window))
				{
					logger.Log("Back button was pressed. Going back to start page.", Logger::Level::Info);
					window.close();
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
					window.close();
				if (event.key.code == sf::Keyboard::Space)
				{
					if (bombIsActive == false)
					{
						pPosition = player.GetPosition();
						bombIsActive = true;
					}
					spacePressed = true;
				}
				break;
			}
		}
		window.draw(map);
		player.Update();
		player.Movement();
		if (spacePressed == true && std::chrono::steady_clock::now() < tend)
		{
			sf::Texture bombTexture;
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
			bombRect.setTexture(&bombTexture);
			bombRect.setPosition(pPosition);
			window.draw(bombRect);
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
		if (spacePressed == true && std::chrono::steady_clock::now() > tend)
		{
			tend = std::chrono::steady_clock::now() + std::chrono::seconds(6);
			spacePressed = false;
			bombIsActive = false;
		}
		window.draw(player.rect);
		window.display();
		window.clear();
	}
}

void DynaBlasterGame::Run()
{
	StartWindow();
}
