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
		enum Direction { Up = 8, Left, Down, Right };
		sf::Vector2i source = { 0, Up };
		sf::Texture pTexture;
		sf::Sprite playerImage;
		float bottom, left, right, top;
		bool ok = true;
	public:
		sf::RectangleShape rect;
		Player()
		{
			if (!pTexture.loadFromFile("TestPlayer.png", { 1 * 64,64,64,64 }))
				std::cout << "Error" << std::endl;
			playerImage.setTexture(pTexture);
			rect.setTexture(playerImage.getTexture());
			rect.setSize({ 32,32 });
			rect.setFillColor(sf::Color::White);
			rect.setOutlineColor(sf::Color::Black);
			rect.setOutlineThickness(1.0f);
			top = rect.getPosition().y;
			left = rect.getPosition().x;
			bottom = rect.getPosition().y + 64;
			right = rect.getPosition().x + 64;
			std::cout << "TLBR: " << " " << top << " " << left << " " << bottom << " " << right << "\n\n\n";
		}
		void Movement()
		{
			float speed = 0.2;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				source.y = Up;
				rect.move(0, -speed);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				source.y = Down;
				rect.move(0, speed);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				source.y = Right;
				rect.move(speed, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				source.y = Left;
				rect.move(-speed, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				std::cout << "TLBR: " << " " << top << " " << left << " " << bottom << " " << right << "\n\n\n";

			}
			//playerImage.setTextureRect(sf::IntRect(source.x * 64, source.y * 64, 64, 64));
			//rect.setTexture(playerImage.getTexture());

		}
		void Update()
		{
			top = rect.getPosition().y;
			left = rect.getPosition().x;
			bottom = rect.getPosition().y + 32;
			right = rect.getPosition().x + 32;
		}
	};
	Player player;
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 600), "Test SFML");
	Window.setKeyRepeatEnabled(true);

	const int level[] =
	{
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
	};
	// create the tilemap from the level definition
	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 15, 13))
		std::cout << "Error" << std::endl;


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
		Window.draw(map);
		Window.draw(player.rect);
		Window.display();
		Window.clear();
	}

}
