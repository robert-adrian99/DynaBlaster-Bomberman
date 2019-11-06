#include <iostream>
#include "PowerUps.h"
#include "Player.h"
#include <vector>
#include "Map.h"

int main()
{
	Player player;
	std::cout << "These are the default values for player lives and speed:" << std::endl;
	std::cout << "- number of lives: " << (uint16_t)player.getLives() << std::endl;
	std::cout << "- speed: " << (uint16_t)player.getSpeed() << std::endl;
	Map map;
	std::cout << map;
	return 0;
}