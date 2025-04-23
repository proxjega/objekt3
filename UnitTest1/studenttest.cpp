#include "CppUnitTest.h"
#include "../vector/include/studentas.h"

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
	};
}