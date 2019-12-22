#include "EnemySFML.h"

EnemySFML::EnemySFML(EnemyType enemyType)
{
	if (enemyType == EnemyType::Barom)
	{
		if (!eTexture.loadFromFile("Barom.jpg", { 0 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Shashakin)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 1 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Nagacham)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 2 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Ojin)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 3 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Pontan)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 4 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Boyon)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 5 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Telpio)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 6 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Parce)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 7 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::BigBoss)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 8 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}
	else if (enemyType == EnemyType::Arion)
	{
		if (!eTexture.loadFromFile("EnemySFML.png", { 9 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
	}

	enemyImage.setTexture(eTexture);
	rect.setTexture(enemyImage.getTexture());
	rect.setSize({ 48,48 });
	rect.setPosition({ 5 * 48, 7* 48 });
	rect.setFillColor(sf::Color::White);
	rect.setOutlineColor(sf::Color::Transparent);
	rect.setOutlineThickness(1.0f);
	top = rect.getPosition().y;
	left = rect.getPosition().x;
	bottom = rect.getPosition().y + 48;
	right = rect.getPosition().x + 48;
	std::cout << "TLBR: " << " " << top << " " << left << " " << bottom << " " << right << "\n\n\n";
	map.Map();
}
void EnemySFML::Movement()
{
	float speed = 0.2;
	currentPosition = rect.getPosition();

	for (const auto& wallrect : map.GetRectVec())
	{
		if (rect.getPosition().x < wallrect.x + 42 &&
			rect.getPosition().x + 42 > wallrect.x&&
			rect.getPosition().y < wallrect.y + 42 &&
			rect.getPosition().y + 42 > wallrect.y)
		{
			currentPosition = lastPosition;
			rect.setPosition(currentPosition);
			break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		if (!eTexture.loadFromFile("Barom.jpg", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		enemyImage.setTexture(eTexture);
		rect.setTexture(enemyImage.getTexture());
		if (rect.getPosition().y > 1 * 48)
		{
			lastPosition = rect.getPosition();
			//source.y = Up;
			rect.move(0, -speed);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		if (!eTexture.loadFromFile("Barom.jpg", { 0 * 48, 0 * 48, 48 , 48 }))
			std::cout << "Error" << std::endl;
		enemyImage.setTexture(eTexture);
		rect.setTexture(enemyImage.getTexture());
		if (rect.getPosition().y < 11 * 48)
		{
			lastPosition = rect.getPosition();
			//source.y = Down;
			rect.move(0, speed);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		if (!eTexture.loadFromFile("Barom.jpg", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		enemyImage.setTexture(eTexture);
		rect.setTexture(enemyImage.getTexture());
		if (rect.getPosition().x < 13 * 48)
		{
			lastPosition = rect.getPosition();
			//source.y = Right;
			rect.move(speed, 0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		if (!eTexture.loadFromFile("Barom.jpg", { 0 * 48 , 0 * 48, 48, 48 }))
			std::cout << "Error" << std::endl;
		enemyImage.setTexture(eTexture);
		rect.setTexture(enemyImage.getTexture());
		if (rect.getPosition().x > 1 * 48)
		{
			lastPosition = rect.getPosition();
			//source.y = Left;
			rect.move(-speed, 0);
		}
	}
}

void EnemySFML::Update()
{
	top = rect.getPosition().y;
	left = rect.getPosition().x;
	bottom = rect.getPosition().y + rect.getScale().y * rect.getSize().y;
	right = rect.getPosition().x + rect.getScale().x * rect.getSize().x;
}

sf::Vector2f EnemySFML::GetPosition()
{
	return rect.getPosition();
}