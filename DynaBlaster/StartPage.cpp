#include <SFML/Graphics.hpp>
#include "HelpButton.h"
#include "PlayButton.h"
#include "LevelsButton.h"
#include "BattleButton.h"
#include "BackButton.h"


void HelpMenuWindow();

void Map();

void StartWindow()
{
	sf::RenderWindow startWindow(sf::VideoMode(850, 700), "Dyna Blaster - Bomberman", sf::Style::Close | sf::Style::Titlebar);

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
					startWindow.close();
					HelpMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && play.IsMouseOver(startWindow))
				{
					startWindow.close();
					Map();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && level.IsMouseOver(startWindow))
				{
					std::cout << "Levels button was pressed" << "\n";
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && battle.IsMouseOver(startWindow))
				{
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
	sf::RenderWindow helpWindow(sf::VideoMode(850, 700), "Help Menu", sf::Style::Close | sf::Style::Titlebar);

	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	BackButton back("Back", { 100,35 }, 20, sf::Color::Transparent, sf::Color::Black);
	back.SetPosition({ 50,638 });
	back.SetFont(arial);

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