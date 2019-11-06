#include <iostream>
#include "PowerUps.h"
#include "Player.h"

int main()
{
	Player player;
	std::cout << "These are the default values for player lives and speed:" << std::endl;
	std::cout << "- number of lives: " << player.getLives() << std::endl;
	std::cout << "- speed: " << player.getSpeed() << std::endl;
	return 0;
}