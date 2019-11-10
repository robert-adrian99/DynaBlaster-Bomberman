#pragma once
#include <iostream>
#include "Map.h"
void Help()
{
	char option;
	Map map;

	std::cout << "Press 'h' for help" << std::endl;
	std::cout << "Press 's' to skip streight to the game." << std::endl;
	std::cin >> option;

	switch (option)
	{
	case 'h':
		std::cout << "The players use the following controls:" << std::endl;
		std::cout << "ARROW KEYS - Press to move Bomberman left,right,up and down." << std::endl;
		std::cout << "SPACE BUTTON - Press to place bombs." << std::endl;
		std::cout << "'d' KEY - Press to explode a bomb WHEN you have a detonator." << std::endl;
		std::cout << "'p' KEY - Press to pause the game. " << std::endl;
		std::cout << "'r' KEY - Press to resume the level." << std::endl;
		std::cout << "Press 's' to start the game." << std::endl;
		std::cin >> option;
	case 's':
		std::cout << map;
		break;
	default:
		break;
	}
}
