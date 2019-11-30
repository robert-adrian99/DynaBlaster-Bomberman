#pragma once
#include <SFML/Graphics.hpp>

void GrassGraphics()
{
	sf::RenderWindow window(sf::VideoMode(512, 256), "Grass");
	sf::Texture grassTexture;
	sf::Sprite sprite;
	if (!grassTexture.loadFromFile("Grass2.jpg"))
		return;
	grassTexture.setSmooth(true);
	sprite.setTexture(grassTexture);
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