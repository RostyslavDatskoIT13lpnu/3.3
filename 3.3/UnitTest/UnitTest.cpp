#include "pch.h"
#include "CppUnitTest.h"
#include "../3.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int d = 4;
			Assert::AreEqual(true, menu_check(d));
		}
	};
}
