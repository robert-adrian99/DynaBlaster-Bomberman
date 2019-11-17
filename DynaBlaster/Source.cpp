#include <iostream>
#include "Map.h"
#include "PowerUps.h"
#include <SFML/Graphics.hpp>
#include "Grass.h"
#include "UndestructibleWall.h"
#include "EnemyGraphics.h"
#include "Enemy.h"
#include "EnemyType.h"
//void UndestructibleWallGraphic();

int main()
{
	Enemy enemy(1, 1, EnemyType::Barom);
	EnemyGraphics(enemy);
	//UndestructibleWallGraphic();
	return 0;
}