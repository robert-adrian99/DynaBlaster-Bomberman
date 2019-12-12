#include "DynaBlasterGame.h"


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
		sf::Texture HelpImage;
		HelpImage.loadFromFile("levels.png");

		sf::Sprite sprite(HelpImage);

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
}

void DynaBlasterGame::HelpMenuWindow()
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

void DynaBlasterGame::StartWindow()
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
					GameWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && level.IsMouseOver(startWindow))
				{
					logger.Log("Levels button was pressed.", Logger::Level::Info);
					startWindow.close();
					LevelsMenuWindow();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && battle.IsMouseOver(startWindow))
				{
					logger.Log("Battle button was pressed.", Logger::Level::Info);
					startWindow.close();
					GameWindow();
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

void DynaBlasterGame::GameWindow()
{
	sf::RenderWindow window(sf::VideoMode(850, 700), "Dyna Blaster - Bomberman");
	map.Map();
	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	// run the main loop
	
	BackButton back("Back", { 100,35 }, 20, sf::Color::Blue, sf::Color::White);
	back.SetFont(arial);
	back.SetPosition({ 50,638 });

	while (window.isOpen())
	{
		// handle events
		sf::Event event;
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
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && back.IsMouseOver(window))
				{
					//logger.Log("Back button was pressed. Going back to start page.", Logger::Level::Info);
					window.close();
					StartWindow();
				}
			}

			// draw the map
			window.clear();
			window.draw(map);
			window.display();
		}
	}
}

void DynaBlasterGame::Run()
{
	StartWindow();
}
