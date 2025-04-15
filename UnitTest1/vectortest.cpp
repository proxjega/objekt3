#include "pch.h"
#include "CppUnitTest.h"
#include "../vector/include/myvector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace vectortest
{
	TEST_CLASS(vectortest)
	{
	public:
		
		TEST_METHOD(DefaulConstructor)
		{
			Logger::WriteMessage("Default Constructor");
			myVector<int> v1;
			std::vector<int> v2;
			Assert::AreEqual(v1.output(), ToString(v2.size()));
			Assert::AreEqual(v1.size(), 0);
			Assert::AreEqual(v1.capacity(), 10);
			Assert::AreEqual(v1.begin(), v1.end());
		}
		TEST_METHOD(FillConstructor)
		{
			Logger::WriteMessage("FillConstructor");
			myVector<int> v1(11,11);
			std::vector<int> v2(11,11);
			myVector<int> v3;
			for (int i = 1; i <= 11; i++) {
				v3.push_back(11);
			}
			std::wstring test;
			for (auto it : v2) {
				test += ToString(it);
			}
			Assert::AreEqual(v1.output(), ToString(v2.size()) + ToString(*v2.begin()) + ToString(*(v2.end() - 1)) + test);
			Assert::AreEqual(v1.output(), v3.output());
		}
		TEST_METHOD(Getters)
		{
			Logger::WriteMessage("Getters");
			myVector<int> v1(10, 10);
			Assert::AreEqual(v1.size(), 10);
			Assert::AreEqual(v1.capacity(), 10);
		}
		TEST_METHOD(Iterators)
		{
			Logger::WriteMessage("Iterators");
			myVector<int> v1(10, 10);
			std::vector<int> v2(10, 10);
			Assert::AreEqual(*(v1.end() - 1), *(v2.end() - 1));
			Assert::AreEqual(*(v1.cend()-1), *(v2.cend()-1));
			Assert::AreEqual(*v1.begin(), *v2.begin());
			Assert::AreEqual(*v1.cbegin(), *v2.cbegin());
			Assert::AreEqual(v1.front(), v2.front());
			Assert::AreEqual(v1.back(), v2.back());

		}
		TEST_METHOD(OperatorSquareBracket)
		{
			Logger::WriteMessage("OperatorSquareBracket");
			myVector<int> v1;
			std::vector<int> v2;
			for (int i = 0; i < 12; i++) {
				v1.push_back(i);
				v2.push_back(i);
			}
			for (int i = 0; i < v1.size(); i++) {
				Assert::AreEqual(v1[i], v2[i]);
				Assert::AreEqual(v1.at(i), v2.at(i));
			}
			Assert::AreEqual(v1[7], 7);
			Assert::AreEqual(v1.at(3), 3);
			Assert::AreEqual(v1.at(8), 8);
			Assert::AreEqual(v1[2], 2);
		}
		TEST_METHOD(PushBackAndPopBack)
		{
			Logger::WriteMessage("PushBackAndPopBack");
			myVector<int> v1;
			std::vector<int> v2;
			myVector<int> v3;
			myVector<int> v4;
			for (int i = 0; i < 12; i++) {
				v1.push_back(i);
				v2.push_back(i);
				v3.push_back(i);
				v4.push_back(i);
			}
			Assert::AreEqual(v1[3], v2[3]);
			Assert::AreEqual(v1.output(), v3.output());
			Assert::AreEqual(v1.output(), v4.output());
			Assert::AreEqual(v1[11], v2[11]);
			Assert::AreEqual(v1.back(), v2.back());
			Assert::AreEqual(v1.back(), v3.back());
			Assert::AreEqual(v1.back(), v4.back());
			v3.pop_back();
			v4.push_back(100);
			Assert::AreNotEqual(v1.back(), v3.back());
			Assert::AreNotEqual(v1.back(), v4.back());
			Assert::AreNotEqual(v1.output(), v3.output());
			Assert::AreNotEqual(v1.output(), v4.output());
		}
		TEST_METHOD(EmptyAndClear)
		{
			Logger::WriteMessage("EmptyAndClear");
			myVector<int> v1;
			myVector<int> v2(12,12);
			std::vector<int> v3;
			Assert::AreEqual(v1.empty(), true);
			Assert::AreEqual(v1.empty(), v3.empty());
			Assert::AreNotEqual(v2.empty(), true);
			Assert::AreNotEqual(v1.empty(), v2.empty());
			v2.clear();
			Assert::AreEqual(v2.empty(), true);
			Assert::AreEqual(v1.empty(), v2.empty());
			Assert::AreEqual(v2.size(), 0);
			Assert::AreEqual(v2.begin(), v2.end());
		}
		TEST_METHOD(Reserve)
		{
			Logger::WriteMessage("Reserve");
			myVector<int> v1;
			std::vector<int> v2;
			v1.reserve(20);
			v2.reserve(20);
			Assert::AreEqual(v1.capacity(), 20);
			Assert::AreEqual(static_cast<int>(v2.capacity()), v1.capacity());
			Assert::AreEqual(v1.size(), 0);
			Assert::AreEqual(static_cast<int>(v2.size()), v1.size());
		}
		TEST_METHOD(ShrinkToFit)
		{
			Logger::WriteMessage("ShrinkToFit");
			myVector<int> v1, v3;
			v3.push_back(1);
			v3.push_back(2);
			v3.shrink_to_fit();
			Assert::AreEqual(v3.capacity(), 2);
			std::vector<int> v2;
			v1.reserve(20);
			v2.reserve(20);
			Assert::AreEqual(v1.capacity(), 20);
			Assert::AreEqual(static_cast<int>(v2.capacity()), v1.capacity());
			v1.shrink_to_fit();
			v2.shrink_to_fit();
			Assert::AreEqual(v1.capacity(), 0);
			Assert::AreEqual(static_cast<int>(v2.capacity()), v1.capacity());
		}
		TEST_METHOD(MoveConstructor)
		{
			Logger::WriteMessage("MoveConstructor");
			myVector<int> v1(10, 10);
			myVector<int> v2(std::move(v1));
			myVector<int> v3(10, 10);
			Assert::AreEqual(v2.size(), 10);
			Assert::AreEqual(v2.capacity(), 10);
			Assert::AreEqual(v2.output(), v3.output());
			Assert::AreEqual(v1.size(), 0);
			Assert::AreEqual(v1.capacity(), 0);
		}
		TEST_METHOD(CopyConstructor)
		{
			Logger::WriteMessage("CopyConstructor");
			myVector<int> v1(10, 10);
			myVector<int> v2(v1);
			Assert::AreEqual(v2.size(), 10);
			Assert::AreEqual(v2.capacity(), 10);
			Assert::AreEqual(v1.output(), v2.output());
		}
	};
}
