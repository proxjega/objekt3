#include "pch.h"
#include "CppUnitTest.h"
#include "studentas.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace studenttest
{
	TEST_CLASS(studenttest)
	{
		TEST_METHOD(DefaultConstuctor)
		{
			Logger::WriteMessage("Default Constructor");
			Student st;
			wstring test = L"";
			Assert::AreEqual(st.getName(), test);
			Assert::AreEqual(st.getSurname(), test);
			Assert::AreEqual(static_cast<int>(st.getMarks().size()), 0);
			Assert::AreEqual(st.getExamMark(), 1);
		}
		TEST_METHOD(ConstructorWith4Params)
		{
			Logger::WriteMessage("ConstructorWith4Params");
			vector<int>pazymiai = { 1,2,3,4,5 };
			std::wstring name = L"name";
			std::wstring surname = L"surname";
			float mean = (1 + 2 + 3 + 4 + 5) / 5.0 * 0.4 + 0.6 * 10;
			float median = 3 * 0.4 + 0.6 * 10;
			Student st(L"name", L"surname", pazymiai, 10);
			Assert::AreEqual(st.getName(), name);
			Assert::AreEqual(st.getSurname(), surname);
			//Assert::AreEqual(st.getMarks(), pazymiai);
			Assert::AreEqual(st.getExamMark(), 10);
			Assert::AreEqual(st.calculateFinalMean(), mean);
			Assert::AreEqual(st.calculateFinalMedian(), median);
		}
	};
}