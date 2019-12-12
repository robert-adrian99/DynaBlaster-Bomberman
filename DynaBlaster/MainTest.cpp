#include "MainTest.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "TileMap.h"
#include <random>
#include <math.h>

int GetXRandom()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandomColumn(2, 13);
	return rrandomColumn(rng);
}
int GetYRandom()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandomColumn(2, 11);
	return rrandomColumn(rng);
}

void MainTest::Execute()
{
	class Wall
	{
	public:
		sf::RectangleShape rect;
	private:
		sf::Texture wallTexture;
		sf::Sprite wallImage;
		float bottom, top, right, left;
	public:
		Wall(int x, int y)
		{
			if (!wallTexture.loadFromFile("tileset.png", sf::IntRect(1 * 32, 0, 32, 32)))
				std::cout << "Error" << std::endl;
			wallImage.setTexture(wallTexture);
			rect.setTexture(wallImage.getTexture());
			rect.setSize({ 32,32 });
			rect.setFillColor(sf::Color::White);
			rect.setPosition(x, y);
			rect.setOutlineThickness(1.0f);
			top = rect.getPosition().y;
			left = rect.getPosition().x;
			bottom = rect.getPosition().y + 32;
			right = rect.getPosition().x + 32;
			std::cout << "TLBR: " << " " << top << " " << left << " " << bottom << " " << right << "\n\n\n";
		}
		float GetBottom() { return bottom; }
		float GetLeft() { return left; }
		float GetRight() { return right; }
		float GetTop() { return top; }
	};


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
			if (!pTexture.loadFromFile("TestPlayer.png", { 1 * 64,10 * 64,64,64 }))
				std::cout << "Error" << std::endl;
			playerImage.setTexture(pTexture);
			rect.setTexture(playerImage.getTexture());
			rect.setSize({ 32,32 });
			rect.setPosition({ 32,32 });
			rect.setFillColor(sf::Color::White);
			rect.setOutlineColor(sf::Color::Black);
			rect.setOutlineThickness(1.0f);
			rect.setScale({ 0.8,0.8 });
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
				if (rect.getPosition().y > 1 * 32)
				{
					source.y = Up;
					rect.move(0, -speed);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				if (rect.getPosition().y < 11 * 32)
				{
					source.y = Down;
					rect.move(0, speed);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (rect.getPosition().x < 13 * 32)
				{
					source.y = Right;
					rect.move(speed, 0);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (rect.getPosition().x > 1 * 32)
				{
					source.y = Left;
					rect.move(-speed, 0);
				}
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
			bottom = rect.getPosition().y + rect.getScale().y * rect.getSize().y;
			right = rect.getPosition().x + rect.getScale().x * rect.getSize().x;
		}

		bool Collision(Wall wall)
		{
			if (right > wall.GetLeft() && left < wall.GetRight() && top < wall.GetBottom() && bottom > wall.GetTop())
			{
				std::cout << "WALL: RLBT " << wall.GetRight() << " " << wall.GetLeft() << " " << wall.GetBottom() << " " << wall.GetTop();
				std::cout << std::endl;
				std::cout << "Player: RLBT " << right << " " << left << " " << bottom << " " << top << std::endl;
				return true;
			}
			return false;
		}

	};
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 600), "Test SFML");
	Window.setKeyRepeatEnabled(true);

	std::vector<int> level =
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
	Player player;
	std::vector<Wall> walls;
	for (int index = 0; index < 30; index++)
	{
		int x = 0, y = 0;
		while (x % 2 == 0)
			x = GetXRandom();
		y = GetYRandom();

		walls.emplace_back(x * 32, y * 32);

	}

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
		player.Update();
		for ( auto wall : walls)
			if (player.Collision(wall))
			{
				std::cout << "Collision! " << std::endl << std::endl;
			}
		player.Movement();
		Window.draw(map);
		Window.draw(player.rect);
		for (const auto& wall : walls)
			Window.draw(wall.rect);
		Window.display();
		Window.clear();
	}

}
