#include "pch.h"
#include "CppUnitTest.h"
#include "../DynaBlaster/Enemy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaBlasterTests
{
	TEST_CLASS(EnemyTest)
	{
	public:
		
		TEST_METHOD(Constructor)
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
		TEST_METHOD(SameEnemy)
		{
			Map map;
			Enemy enemy1(EnemyType::Barom, map);
			Enemy enemy2(EnemyType::Barom, map);
			Assert::IsTrue(enemy1.AllowToMove() == enemy2.AllowToMove());
			Assert::IsTrue(enemy1.GetPosition() != enemy2.GetPosition());
			Assert::IsTrue(enemy1.m_bombsVector == enemy2.m_bombsVector);
			Assert::IsTrue(enemy1.GetRectangle().getPosition() != enemy2.GetRectangle().getPosition());
			Assert::IsTrue(enemy1.IsActive() == enemy2.IsActive());
		}
		TEST_METHOD(RectangleEqualsPosstion)
		{
			Map map;
			Enemy enemy(EnemyType::Barom, map);
			Assert::IsTrue(enemy.GetRectangle().getPosition() == enemy.GetPosition());
		}
	};
}
