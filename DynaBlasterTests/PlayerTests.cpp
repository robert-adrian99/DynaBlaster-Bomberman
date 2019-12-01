#include "pch.h"
#include "CppUnitTest.h"
#include "../DynaBlaster/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaBlasterTests
{
	TEST_CLASS(PlayerTests)
	{
	public:
		
		TEST_METHOD(Constuctor)
		{
			Player player;
			Assert::IsTrue(player.GetLives() == 2);
			Assert::IsTrue(player.GetSpeed() == 1);
			Assert::IsTrue(player.GetScore() == 0);
			Assert::IsTrue(player.GetHighScore() == 0);
			Assert::IsTrue(player.GetNumberOfBombs() == 1);
		}
	};
}
