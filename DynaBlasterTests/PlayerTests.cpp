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

		TEST_METHOD(GetPowerUp)
		{
			Player player;
			Assert::IsTrue(player.GetPowerUp(PowerUps::Flame) == false);
			Assert::IsTrue(player.GetPowerUp(PowerUps::Bomb) == false);
			Assert::IsTrue(player.GetPowerUp(PowerUps::RollerSkates) == false);
			Assert::IsTrue(player.GetPowerUp(PowerUps::RemoteControl) == false);
			Assert::IsTrue(player.GetPowerUp(PowerUps::PaintedBomb) == false);
			Assert::IsTrue(player.GetPowerUp(PowerUps::Character) == false);
			Assert::IsTrue(player.GetPowerUp(PowerUps::PaintedWall) == false);
			Assert::IsTrue(player.GetPowerUp(PowerUps::Jacket) == false);
		}

		TEST_METHOD(SetPowerUp)
		{
			Player player;
			player.SetPowerUp(PowerUps::Flame);
			Assert::IsTrue(player.GetPowerUp(PowerUps::Flame) == true);
			player.SetPowerUp(PowerUps::Bomb);
			Assert::IsTrue(player.GetPowerUp(PowerUps::Bomb) == true);
			player.SetPowerUp(PowerUps::RollerSkates);
			Assert::IsTrue(player.GetPowerUp(PowerUps::RollerSkates) == true);
			player.SetPowerUp(PowerUps::RemoteControl);
			Assert::IsTrue(player.GetPowerUp(PowerUps::RemoteControl) == true);
			player.SetPowerUp(PowerUps::PaintedBomb);
			Assert::IsTrue(player.GetPowerUp(PowerUps::PaintedBomb) == true);
			player.SetPowerUp(PowerUps::Character);
			Assert::IsTrue(player.GetPowerUp(PowerUps::Character) == true);
			player.SetPowerUp(PowerUps::PaintedWall);
			Assert::IsTrue(player.GetPowerUp(PowerUps::PaintedWall) == true);
			player.SetPowerUp(PowerUps::Jacket);
			Assert::IsTrue(player.GetPowerUp(PowerUps::Jacket) == true);
		}

		TEST_METHOD(Die)
		{
			Player player;
			Assert::IsFalse(player.Die());
			Assert::IsFalse(player.Die());
			Assert::IsTrue(player.Die());
		}
	};
}
