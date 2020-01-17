#include "pch.h"
#include "CppUnitTest.h"
#include "../DynaBlaster/EnemySFML.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaBlasterTests
{
	TEST_CLASS(EnemySFMLTest)
	{
	public:
		
		TEST_METHOD(Constuctor)
		{
			TileMap map;
			EnemySFML enemy(EnemyType::Barom,map);
			Assert::IsTrue(enemy.allowToMove == false);
			Assert::IsTrue(enemy.enemy.getSize() == sf::Vector2f(48,48));
			Assert::IsTrue(enemy.GetActive() == true);
		}
		TEST_METHOD(Die)
		{
			TileMap map;
			EnemySFML enemy(EnemyType::Barom,map);
			enemy.EnemyDie();
			Assert::IsTrue(enemy.GetActive() == false);
			Assert::IsTrue(enemy.GetPosition() == sf::Vector2f(0, 0));
		}
	};
}
