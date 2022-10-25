#include "pch.h"
#include "CppUnitTest.h"
#include "../game.h"
#include "../game.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{

	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(funFonGame() == true);
		}
	};
}
