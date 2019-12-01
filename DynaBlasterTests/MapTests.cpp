#include "pch.h"
#include "CppUnitTest.h"
#include "../DynaBlaster/Map.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestBombermanTests
{
	TEST_CLASS(MapTests)
	{
	public:

		TEST_METHOD(LineMinusOneColumnOne)
		{
			Map map;
			Assert::ExpectException<std::out_of_range>([&map]() { map[{-1, 1}]; });
		}

		TEST_METHOD(LineMinusOneColumnOneConst)
		{
			const Map map;
			Assert::ExpectException<std::out_of_range>([&map]() { map[{-1, 1}]; });
		}
	};
}

