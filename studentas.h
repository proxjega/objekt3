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
    Student() : examMark_(0) {}  // default konstruktorius
    Student(std::istream& is);
    inline std::wstring vardas() const { return name_; }  
    inline std::wstring pavarde() const { return surname_; }  
    double galBalas(double (*) (vector<double>) = mediana) const;  
    std::istream& readStudent(std::istream&);
};

bool CompareByName(const Student a, const Student b);
bool CompareBySurname(const Student a, const Student b);
bool CompareByVid(const Student a, const Student b);
bool CompareByMed(const Student a, const Student b);