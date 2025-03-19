#pragma once
#include <string>
#include <vector>

class Student {
private:
    std::wstring name_;
    std::wstring surname_;
    std::vector<int>marks_;
    int examMark_ = 0;
    float median_ = 0;
    float vid_ = 0;
public:
    Student() : egzaminas_(0) {}  // default konstruktorius
    Student(std::istream& is);
    inline std::wstring vardas() const { return name_; }    // get'eriai, inline
    inline std::wstring pavarde() const { return surname_; }  // get'eriai, inline
    double galBalas(double (*) (vector<double>) = mediana) const;  // get'eriai
    std::istream& readStudent(std::istream&);  // set'eriai
};
};