#include "pch.h"
#include "CppUnitTest.h"
#include "../DynaBlaster/PlayButton.h"
#include "SFML/Graphics.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace TestBombermanTests
{

	TEST_CLASS(PlayButtonTests)
	{
	public:
		TEST_METHOD(Constructor)
		{
			PlayButton play("Play", { 265,35 }, 20, sf::Color::Transparent, sf::Color::Black);
			Assert::IsTrue(play.GetText() == "Play");
			Assert::IsTrue(play.GetTextColor() == sf::Color::Black);
			Assert::IsTrue(play.GetTextCharacterSize() == 20);
			Assert::IsTrue(play.GetPlayButtonBgColor() == sf::Color::Transparent);
		}
		TEST_METHOD(SetFont)
		{
			PlayButton play;
			sf::Font colleged;
			colleged.loadFromFile("colleged.ttf");
			Assert::IsTrue(play.GetTextFont() == colleged);
		}
		TEST_METHOD(SetBgColor)
		{
			PlayButton play;
			Assert::IsTrue(play.GetBgColor() == sf::Color::Blue);
		}
		TEST_METHOD(SetPosition)
		{
			PlayButton play;
			sf::Vector2f position;
			play.SetPosition(position);
			Assert::IsTrue(play.GetPosition() == position);
		}
	};
}