#pragma once
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <iostream>
#include <iomanip>
#include <algorithm>

using std::vector;
using std::wcout;
using std::endl;
using std::wstring;
using std::left;
using std::setprecision;
using std::setw;
using std::fixed;
using std::wcerr;

class Human {
protected:
    std::wstring name_;
    std::wstring surname_;
};

class Student {
private:
    std::wstring name_;
    std::wstring surname_;
    std::vector<int>marks_;
    int examMark_;
public:
    Student() : name_(L""), surname_(L""), marks_(1), examMark_(1){}
    Student(int pazymiuSk);
    Student(wstring name, wstring surname, int pazymiuSk);
    Student(wstring name, wstring surname, vector<int> marks, int examMark);
    
    Student(const Student& orig); //copy constructor
	Student& operator=(const Student& orig); //copy assignment operator
    Student(Student&& orig);
    Student& operator=(Student&& orig);

    friend std::wostream& operator<<(std::wostream& out, const Student& st);
    friend std::wistream& operator>>(std::wistream& in, Student& st);


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
};
int InputMark();
int InputExamMark();
