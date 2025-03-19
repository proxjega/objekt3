#pragma once
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <iostream>

using std::vector;
using std::wcout;
using std::endl;
using std::wstring;

class Student {
private:
    std::wstring name_;
    std::wstring surname_;
    std::vector<int>marks_;
    int examMark_;
	float finalMean_;
	float finalMedian_;
public:
    Student() : name_(L""), surname_(L""), marks_(1), examMark_(1), finalMean_(1), finalMedian_(1){}
    Student(int pazymiuSk);
    Student(wstring name, wstring surname, int pazymiuSk);
    Student(wstring name, wstring surname, vector<int> marks, int examMark);
    ~Student();

    inline std::wstring getName() const { return name_; }
    inline std::wstring getSurname() const { return surname_; }
    inline std::vector<int> getMarks() const { return marks_; }
    inline int getExamMark() const { return examMark_; }

    void setName(std::wstring name) { name_ = name; }
    void setSurname(std::wstring surname) { surname_ = surname; }
    void setMarks(std::vector<int> marks) { marks_ = marks; }
    void setExamMark(int examMark) { examMark_ = examMark; }

    float calculateFinalMean() const;
    float calculateFinalMedian() const;
    //std::istream& readStudent(std::istream&);
};

bool CompareByName(const Student &a, const Student &b);
bool CompareBySurname(const Student &a, const Student &b);
bool CompareByVid(const Student &a, const Student &b);
bool CompareByMed(const Student &a, const Student &b);