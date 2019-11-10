#include <iostream>
#include "Map.h"
#include "PowerUps.h"

int main()
{
	Map map;
	std::cout << map;
	map.VerifyRewardUnderWall();
	std::cout << map;
	return 0;
}