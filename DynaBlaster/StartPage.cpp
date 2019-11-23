#include <SFML/Graphics.hpp>


void StartWindow()
{
	sf::RenderWindow startWindow(sf::VideoMode(850, 700), "Dyna Blaster - Bomberman", sf::Style::Close | sf::Style::Titlebar);
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
			}
			startWindow.clear();
			startWindow.draw(sprite);
			startWindow.display();
		}
	}
}