#include "pch.h"
#include "CppUnitTest.h"
#include "../DynaBlaster/Player.h"
#include "SFML/Graphics.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaBlasterTests
{
	TEST_CLASS(PlayerTests)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Player player;
			Assert::IsTrue(player.GetLives() == 3);
			Assert::IsTrue(player.GetActive() == true);
			Assert::IsTrue(player.GetPosition() == sf::Vector2f(48, 98));
			Assert::IsTrue(player.GetBombExplosionRange() == 2);
		}

		TEST_METHOD(GetPosition)
		{
			Player player;
			Assert::IsTrue(player.GetPosition().x < 13 * 48);
			Assert::IsTrue(player.GetPosition().y < 15 * 48);
		}

		TEST_METHOD(GetBombRange)
		{
			Player player;
			Assert::IsTrue(player.GetBombExplosionRange() != 0);
		}

	};
}