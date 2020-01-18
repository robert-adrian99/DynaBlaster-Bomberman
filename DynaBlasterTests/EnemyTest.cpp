#include "pch.h"
#include "CppUnitTest.h"
#include "../DynaBlaster/Enemy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaBlasterTests
{
	TEST_CLASS(EnemyTest)
	{
	public:
		
		TEST_METHOD(Constuctor)
		{
			Map map;
			Enemy enemy(EnemyType::Barom,map);
			Assert::IsTrue(enemy.AllowToMove() == false);
			Assert::IsTrue(enemy.GetRectangle().getSize() == sf::Vector2f(48,48));
			Assert::IsTrue(enemy.IsActive() == true);
		}
		TEST_METHOD(Die)
		{
			Map map;
			Enemy enemy(EnemyType::Barom,map);
			enemy.Die();
			Assert::IsTrue(enemy.IsActive() == false);
			Assert::IsTrue(enemy.GetPosition() == sf::Vector2f(0, 0));
		}
	};
}
