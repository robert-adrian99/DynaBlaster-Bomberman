#include <SFML/Graphics.hpp>
#include <fstream>
#include "HelpButton.h"
#include "PlayButton.h"
#include "LevelsButton.h"
#include "BattleButton.h"
#include "BackButton.h"
#include "../Logging/Logger.h"

void HelpMenuWindow();

void Map();

void StartWindow()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	sf::RenderWindow startWindow(sf::VideoMode(850, 700), "Dyna Blaster - Bomberman", sf::Style::Close | sf::Style::Titlebar);

	logger.Log("Start window was rendered.", Logger::Level::Info);

	sf::Font colleged;
	colleged.loadFromFile("colleged.ttf");

	HelpButton help("Help", { 200,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	help.SetPosition({ 315,638 });
	help.SetFont(colleged);

	PlayButton play("Play", { 265,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	play.SetPosition({ 280,500 });
	play.SetFont(colleged);

	LevelsButton level("Levels", { 170,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	level.SetPosition({ 300,590 });
	level.SetFont(colleged);

	BattleButton battle("Battle", { 225,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	battle.SetPosition({ 295,550 });
	battle.SetFont(colleged);

	logger.Log("Buttons added to the window.", Logger::Level::Info);

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
					help.SetBgColor(sf::Color::Blue);
				}
				else
				{
					help.SetBgColor(sf::Color::Transparent);
				}
				if (play.IsMouseOver(startWindow))
				{
					play.SetBgColor(sf::Color::Blue);
				}
				else
				{
					play.SetBgColor(sf::Color::Transparent);
				}
				if (level.IsMouseOver(startWindow))
				{
					level.SetBgColor(sf::Color::Blue);
				}
				else
				{
					level.SetBgColor(sf::Color::Transparent);
				}
				if (battle.IsMouseOver(startWindow))
				{
					battle.SetBgColor(sf::Color::Blue);
				}
				else
				{
					battle.SetBgColor(sf::Color::Transparent);
				}
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && help.IsMouseOver(startWindow))
				{
					logger.Log("Help button was pressed.", Logger::Level::Info);
					startWindow.close();
					HelpMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && play.IsMouseOver(startWindow))
				{
					logger.Log("Play button was pressed.", Logger::Level::Info);
					startWindow.close();
					Map();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && level.IsMouseOver(startWindow))
				{
					logger.Log("Levels button was pressed.", Logger::Level::Info);
					std::cout << "Levels button was pressed" << "\n";
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && battle.IsMouseOver(startWindow))
				{
					logger.Log("Battle button was pressed.", Logger::Level::Info);
					std::cout << "Battle button was pressed" << "\n";
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
}

void HelpMenuWindow()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);

	sf::RenderWindow helpWindow(sf::VideoMode(850, 700), "Help Menu", sf::Style::Close | sf::Style::Titlebar);

	logger.Log("Help window was rendered.", Logger::Level::Info);

	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	BackButton back("Back", { 100,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	back.SetPosition({ 50,638 });
	back.SetFont(arial);

	logger.Log("Displayed the information about the game.", Logger::Level::Info);

	while (helpWindow.isOpen())
	{
		sf::Event event;
		sf::Texture HelpImage;
		HelpImage.loadFromFile("HelpMenu v1.png");

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
					back.SetBgColor(sf::Color::Blue);
				}
				else
				{
					back.SetBgColor(sf::Color::Transparent);
				}
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && back.IsMouseOver(helpWindow))
				{
					logger.Log("Back button was pressed. Going back to the start page.", Logger::Level::Info);
					helpWindow.close();
					StartWindow();
				}
			}

			helpWindow.clear();
			helpWindow.draw(sprite);
			back.DrawTo(helpWindow);
			helpWindow.display();
		}
	}
}