#include "../include/studentas.h"
#include "../../UnitTest1/pch.h"

Human::~Human() {
	name_ = L"";
	surname_ = L"";
}


Student::Student(wstring name, wstring surname, vector<int> marks, int examMark) {
	name_ = name;
	surname_ = surname;
	marks_ = marks;
	examMark_ = examMark;
}

Student::Student(wstring name, wstring surname, int pazymiuSk) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 10);
	for (int i = 0; i < pazymiuSk; i++) {
		marks_.push_back(dist(mt));
		std::wcout << L"Generuotas pazymys: " << marks_[i] << std::endl;
	}
	examMark_ = dist(mt);
	std::wcout << L"Generuotas egzamino pazymys: " << examMark_ << std::endl;
	name_ = name;
	surname_ = surname;
}

Student::Student(int pazymiuSk) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
	for (int i = 0; i < pazymiuSk; i++) {
		marks_.push_back(dist(mt));
		std::wcout << L"Generuotas pazymys: " << marks_[i] << std::endl;
	}
	examMark_ = dist(mt);
	std::wcout << L"Generuotas egzamino pazymys: " << examMark_ << std::endl;
	name_ = L"name" + std::to_wstring(dist(mt));
	wcout << L"Generuotas vardas: " << name_ << endl;
	surname_ = L"surname" + std::to_wstring(dist(mt));
	wcout << L"Generuota pavarde: " << surname_ << endl;
}

Student::Student(const Student& orig) { //copy constructor
	name_ = orig.name_;
	surname_ = orig.surname_;
	marks_ = orig.marks_;
	examMark_ = orig.examMark_;
}
Student& Student::operator=(const Student& orig) { //copy assignment operator
	if (this != &orig) {
		name_ = orig.name_;
		surname_ = orig.surname_;
		marks_ = orig.marks_;
		examMark_ = orig.examMark_;
	}
	return *this;
}

Student::Student(Student&& orig) { //move constructor
	name_ = orig.name_;
	surname_ = orig.surname_;
	marks_ = std::move(orig.marks_);
	examMark_ = orig.examMark_;
	orig.name_ = L"";
	orig.surname_ = L"";
	orig.marks_.clear();
	orig.examMark_ = 0;
}

Student& Student::operator=(Student&& orig) { //move assignment operator
	if (&orig == this) return *this;
	name_ = orig.name_;
	surname_ = orig.surname_;
	marks_ = std::move(orig.marks_);
	examMark_ = orig.examMark_;
	orig.name_ = L"";
	orig.surname_ = L"";
	orig.marks_.clear();
	orig.examMark_ = 0;
}

std::wostream& operator<<(std::wostream& output, const Student& st) {
	output << setw(17) << left << st.getSurname() << setw(17) << left
		<< st.getName() << setw(20) << left << setprecision(2) << fixed
		<< st.calculateFinalMean() << setw(15) << left << setprecision(2) << fixed << st.calculateFinalMedian() << L"\n";
	return output;
}

std::wistream& operator>>(std::wistream& in, Student& st) {
	wcout << L"Iveskite vardą, pavardę\n";
	in >> st.name_ >> st.surname_;
	wcout << L"Iveskite pažymius (0 - pabaigti)\n";
	while (true) {
		try {
			int mark = InputMark();
			if (mark == 0) {
				if (st.marks_.size() != 0) {
					break;
				}
				else throw L"\007Įveskite bent vieną pažymį";
				continue;
			}
			st.marks_.push_back(mark);
		}
		catch (const wchar_t* e) {
			wcerr << e << endl;
			continue;
		}
		catch (...) {
			wcerr << L"\007Nežinoma klaida" << endl;
			continue;
		}
	}
	wcout << L"Įveskite egzamino pažymį:\n";
	while (true) {
		try {
			st.examMark_ = InputExamMark();
			break;
		}
		catch (const wchar_t* e) {
			wcerr << e << endl;
			continue;
		}
		catch (...) {
			wcerr << L"\007Nežinoma klaida" << endl;
			continue;
		}
	}
	return in;
}

Student::~Student() {
	name_ = L"";
	surname_ = L"";
	marks_.clear();
	examMark_ = 0;
}

float Student::calculateFinalMean() const {
	vector<int> marks = getMarks();
	if (marks.size() == 0) return 0;
    return 0.4 * ((std::accumulate(marks.begin(), marks.end(), 0) * 1.0) / (marks.size() * 1.0)) + 0.6 * examMark_;
}

float Student::calculateFinalMedian() const {
	vector<int> marks = getMarks();
	if (marks.size() == 0) return 0;
	float median = 0;
    std::sort(marks.begin(), marks.end());
    (marks.size() % 2 != 0) ? median = marks[marks.size() / 2] : median = (marks[marks.size() / 2] + marks[marks.size() / 2 - 1]) / 2.0;
    median = median * 0.4 + examMark_ * 0.6;
    return median;
}

wstring Student::output() {
	wstring output = name_ + surname_;
	for (int i = 0; i < marks_.size(); i++) {
		output += std::to_wstring(marks_[i]) + L" ";
	}
	output += std::to_wstring(examMark_);
	return output;
}
