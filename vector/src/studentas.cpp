#include "../include/studentas.h"

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

std::wostream& operator<<(std::wostream& out, const Student& st) {
	out << L"|Pavardė: " << setw(17) << left  << st.surname_ << L"|Vardas: " << setw(17) << left
		 << st.name_ << L"|Pažymių suma: " << setw(20) << left << setprecision(2) << fixed
		 << std::accumulate(st.marks_.begin(), st.marks_.end(), 0) << L"|Egzamino pažymys: " << setw(15) << left << setprecision(2) << fixed  << st.examMark_ << L"\n";
	return out;
}

Student::~Student() {
	name_ = L"";
	surname_ = L"";
	marks_.clear();
	examMark_ = 0;
}

float Student::calculateFinalMean() const {
	vector<int> marks = getMarks();
    return 0.4 * ((std::accumulate(marks.begin(), marks.end(), 0) * 1.0) / (marks.size() * 1.0)) + 0.6 * examMark_;
}

float Student::calculateFinalMedian() const {
	vector<int> marks = getMarks();
    float median = 0;
    std::sort(marks.begin(), marks.end());
    (marks.size() % 2 != 0) ? median = marks[marks.size() / 2] : median = (marks[marks.size() / 2] + marks[marks.size() / 2 - 1]) / 2.0;
    median = median * 0.4 + examMark_ * 0.6;
    return median;
}
