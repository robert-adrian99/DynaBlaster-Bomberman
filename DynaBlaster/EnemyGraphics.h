#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "EnemyType.h"

void EnemyGraphics(Enemy enemy)
{
	sf::RenderWindow window(sf::VideoMode(720, 720), "Enemy");
	sf::Texture enemyTexture;
	sf::Sprite sprite;
	if(enemy.GetEnemyType() == EnemyType::Barom)
		if (!enemyTexture.loadFromFile("Barom.jpg"))
			return;
	enemyTexture.setSmooth(true);
	sprite.setTexture(enemyTexture);
	sprite.setTextureRect(sf::IntRect(100, 100, 100, 100));
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}

}