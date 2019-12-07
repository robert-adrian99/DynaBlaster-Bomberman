#include "MainTest.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "TileMap.h"

void MainTest::Execute()
{
	class Player
	{
	private:
		float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
		bool updateFrame = true;
		enum Direction { Up = 8, Left, Down, Right };
		sf::Vector2i source = { 0, Up };
		sf::Texture pTexture;
		sf::Sprite playerImage;
		sf::Clock clock;
		float bottom, left, right, top;
		bool ok = true;
	public:
		Player()
		{
			if (!pTexture.loadFromFile("TestPlayer.png"))
				std::cout << "Error" << std::endl;
			playerImage.setTexture(pTexture);
			playerImage.setScale(sf::Vector2f(0.5, 0.5));
			playerImage.setPosition(30, 30);
		}

		sf::Sprite GetSprite()
		{
			return playerImage;
		}
		void Movement()
		{
			float speed = 0.2;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				source.y = Up;
				//std::cout << "UP";
				playerImage.move(0, -speed);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				source.y = Down;
				//std::cout << "Down";
				playerImage.move(0, speed);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				source.y = Right;
				//std::cout << "Right";
				playerImage.move(speed, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				source.y = Left;
				//std::cout << "Left";
				playerImage.move(-speed, 0);
			}
			playerImage.setTextureRect(sf::IntRect(source.x * 64, source.y * 64, 64, 64));

		}
	};
	Player player;
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 600), "Test SFML");
	Window.setKeyRepeatEnabled(true);

	while (Window.isOpen())
	{
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Escape)
					Window.close();
				break;
			}
		}
		player.Movement();
		Window.draw(player.GetSprite());
		Window.display();
		Window.clear();
	}

}
