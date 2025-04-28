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
		TEST_METHOD(CopyConstructor)
		{
			Logger::WriteMessage("CopyConstructor");
			vector<int>pazymiai = { 1,2,3,4,5 };
			std::wstring name = L"name";
			std::wstring surname = L"surname";
			Student st(L"name", L"surname", pazymiai, 10);
			Student st2(st);
			Assert::AreEqual(st2.getName(), name);
			Assert::AreEqual(st2.getSurname(), surname);
			Assert::AreEqual(static_cast<int>(st2.getMarks().size()), 5);
			Assert::AreEqual(st2.getExamMark(), 10);
			Assert::AreEqual(st.output(), st2.output());
		}
		TEST_METHOD(CopyAssignment)
		{
			Logger::WriteMessage("CopyAssignment");
			vector<int>pazymiai = { 1,2,3,4,5 };
			std::wstring name = L"name";
			std::wstring surname = L"surname";
			Student st(L"name", L"surname", pazymiai, 10);
			Student st2 = st;
			Assert::AreEqual(st2.getName(), name);
			Assert::AreEqual(st2.getSurname(), surname);
			Assert::AreEqual(static_cast<int>(st2.getMarks().size()), 5);
			Assert::AreEqual(st2.getExamMark(), 10);
			Assert::AreEqual(st.output(), st2.output());
		}
		TEST_METHOD(MoveConstructor)
		{
			Logger::WriteMessage("MoveConstructor");
			vector<int>pazymiai = { 1,2,3,4,5 };
			std::wstring name = L"name";
			std::wstring surname = L"surname";
			Student st(L"name", L"surname", pazymiai, 10);
			Student st2(std::move(st));
			Assert::AreEqual(st2.getName(), name);
			Assert::AreEqual(st2.getSurname(), surname);
			Assert::AreEqual(static_cast<int>(st2.getMarks().size()), 5);
			Assert::AreEqual(st2.getExamMark(), 10);
			Assert::AreNotEqual(st.output(), st2.output());
		}
		TEST_METHOD(MoveAssignment)
		{
			Logger::WriteMessage("MoveAssignment");
			vector<int>pazymiai = { 1,2,3,4,5 };
			std::wstring name = L"name";
			std::wstring surname = L"surname";
			Student st(L"name", L"surname", pazymiai, 10);
			Student st2 = std::move(st);
			Assert::AreEqual(st2.getName(), name);
			Assert::AreEqual(st2.getSurname(), surname);
			Assert::AreEqual(static_cast<int>(st2.getMarks().size()), 5);
			Assert::AreEqual(st2.getExamMark(), 10);
			Assert::AreNotEqual(st.output(), st2.output());
		}
		TEST_METHOD(Destructor)
		{
			Logger::WriteMessage("Destructor");
			vector<int>pazymiai = { 1,2,3,4,5 };
			std::wstring name = L"name";
			std::wstring surname = L"surname";
			Student st(L"name", L"surname", pazymiai, 10);
			st.~Student();
			Assert::AreNotEqual(st.getName(), name);
			Assert::AreNotEqual(st.getSurname(), surname);
			Assert::AreNotEqual(static_cast<int>(st.getMarks().size()), 5);
			Assert::AreNotEqual(st.getExamMark(), 10);
			wstring test = L"";
			Assert::AreEqual(st.getName(), test);
			Assert::AreEqual(st.getSurname(), test);
			Assert::AreEqual(static_cast<int>(st.getMarks().size()), 0);
			Assert::AreEqual(st.getExamMark(), 0);
		}
		TEST_METHOD(Getters)
		{
			Logger::WriteMessage("Getters");
			vector<int>pazymiai = { 1,2,3,4,5 };
			std::wstring name = L"name";
			std::wstring surname = L"surname";
			Student st(L"name", L"surname", pazymiai, 10);
			Assert::AreEqual(st.getName(), name);
			Assert::AreEqual(st.getSurname(), surname);
			Assert::AreEqual(static_cast<int>(st.getMarks().size()), 5);
			Assert::AreEqual(st.getExamMark(), 10);
		}
		TEST_METHOD(Setters)
		{
			Logger::WriteMessage("Setters");
			vector<int>pazymiai = { 1,2,3,4,5 };
			vector<int>newpazymiai = { 1,2,3,4,5,6,7,8 };
			Student st(L"name", L"surname", pazymiai, 10);
			std::wstring newname = L"newName";
			std::wstring newsurname = L"newSurname"; 
			st.setName(newname);
			st.setSurname(newsurname);
			st.setMarks(newpazymiai);
			st.setExamMark(1);
			Assert::AreEqual(st.getName(), newname);
			Assert::AreEqual(st.getSurname(), newsurname);
			Assert::AreEqual(static_cast<int>(st.getMarks().size()), 8);
			Assert::AreEqual(st.getExamMark(), 1);
		}
	};
}