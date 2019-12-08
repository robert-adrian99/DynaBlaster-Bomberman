#include "pch.h"
#include "CppUnitTest.h"
#include "../DynaBlaster/Enemy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaBlasterTests
{
	TEST_CLASS(EnemyTests)
	{
	public:

		TEST_METHOD(Constuctor)
		{
			Map map;
			Enemy enemy(0, 0, EnemyType::Barom, map);
			Assert::IsTrue(enemy.GetEnemyType() == EnemyType::Barom);
			Assert::IsTrue(enemy.GetX() == 0);
			Assert::IsTrue(enemy.GetY() == 0);
		}
	};
}
