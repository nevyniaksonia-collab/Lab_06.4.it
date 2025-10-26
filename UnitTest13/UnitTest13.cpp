#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06.4.it/Lab_06.4.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest13
{
	TEST_CLASS(UnitTest13)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a[] = { -2, 5, -3 };
			Assert::AreEqual(-5.0, sumNeg(a, 3), 1e-9);
		}
		TEST_METHOD(TestMethod2)
		{
			double a[] = { 1, 9, -5, 3 };
			Assert::AreEqual(1, findMaxIdx(a, 4));
			Assert::AreEqual(2, findMinIdx(a, 4));
		}
		TEST_METHOD(TestMethod3)
		{
			double a[] = { 2, -10, 3, 4, 20 };
			Assert::AreEqual(12.0, productMinMax(a, 5), 1e-9);
		}
		TEST_METHOD(TestMethod4)
		{
			double a[] = { 5, 4, 3, 2, 6 };
			sortEven(a, 5);
			double exp[] = { 5, 2, 3, 4, 6 };
			for (int i = 0; i < 5; i++)
			Assert::AreEqual(exp[i], a[i], 1e-9);
		}
	};
}


		