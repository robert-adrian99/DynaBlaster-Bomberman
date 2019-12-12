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
		TEST_METHOD(Die)
		{
			Map map;
			std::vector<Enemy> enemies{
			(0,0,EnemyType::Barom, map),
			(0,0,EnemyType::Shashakin, map),
			(0,0,EnemyType::Nagacham, map),
			(0,0,EnemyType::Ojin, map),
			(0,0,EnemyType::Pontan, map),
			(0,0,EnemyType::Boyon, map),
			(0,0,EnemyType::Telpio, map),
			(0,0,EnemyType::Parce, map),
			(0,0,EnemyType::BigBoss, map),
			(0,0,EnemyType::Arion, map),
			};
			std::vector<int> points{
			100,
			400,
			100,
			400,
			200,
			1000,
			1000,
			2000,
			20000,
			20000,
			};
			Assert::IsTrue(enemies[0].Die(map) == points[0]);
			Assert::IsTrue(enemies[1].Die(map) == points[1]);
			Assert::IsTrue(enemies[2].Die(map) == points[2]);
			Assert::IsTrue(enemies[3].Die(map) == points[3]);
			Assert::IsTrue(enemies[4].Die(map) == points[4]);
			Assert::IsTrue(enemies[5].Die(map) == points[5]);
			Assert::IsTrue(enemies[6].Die(map) == points[6]);
			Assert::IsTrue(enemies[7].Die(map) == points[7]);
			Assert::IsTrue(enemies[8].Die(map) == points[8]);
			Assert::IsTrue(enemies[9].Die(map) == points[9]);
		}
	};
}
