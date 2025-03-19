#include "../include/studentas.h"

Student::Student(wstring name, wstring surname, vector<int> marks, int examMark) {
	name_ = name;
	surname_ = surname;
	marks_ = marks;
	examMark_ = examMark;
	finalMean_ = calculateFinalMean();
	finalMedian_ = calculateFinalMedian();
}

Student::Student(wstring name, wstring surname, int pazymiuSk) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 10);
	for (int i = 0; i < pazymiuSk; i++) {
		marks_.push_back(dist(mt));
		std::cout << "Generuotas pazymys: " << marks_[i] << std::endl;
	}
	examMark_ = dist(mt);
	name_ = name;
	surname_ = surname;
	finalMean_ = calculateFinalMean();
	finalMedian_ = calculateFinalMedian();
}

Student::Student(int pazymiuSk) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
	for (int i = 0; i < pazymiuSk; i++) {
		marks_.push_back(dist(mt));
		std::cout << "Generuotas pazymys: " << marks_[i] << std::endl;
	}
	examMark_ = dist(mt);
	name_ = L"name" + std::to_wstring(dist(mt));
	wcout << L"Generuotas vardas: " << name_ << endl;
	surname_ = L"surname" + std::to_wstring(dist(mt));
	wcout << L"Generuota pavarde: " << surname_ << endl;
	finalMean_ = calculateFinalMean();
	finalMedian_ = calculateFinalMedian();
}

Student::~Student() {
	name_ = L"";
	surname_ = L"";
	marks_.clear();
	examMark_ = 0;
	finalMean_ = 0;
	finalMedian_ = 0;
}

double Student::calculateFinalMean() const {
	const vector<int>marks = getMarks();
    return 0.4 * ((std::accumulate(marks.begin(), marks.end(), 0) * 1.0) / (marks.size() * 1.0)) + 0.6 * examMark_;
}

double Student::calculateFinalMedian() const {
	const vector<int>marks = getMarks();
    float median = 0;
    std::sort(marks.begin(), marks.end());
    (marks.size() % 2 != 0) ? median = marks[marks.size() / 2] : median = (marks[marks.size() / 2] + marks[marks.size() / 2 - 1]) / 2.0;
    median = median * 0.4 + examMark_ * 0.6;
    return median;
}

bool CompareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}

bool CompareBySurname(const Student& a, const Student& b) {
    return a.getSurname() < b.getSurname();
}

bool CompareByVid(const Student& a, const Student& b) {
    return a.calculateFinalMean() < b.calculateFinalMean();
}

bool CompareByMed(const Student& a, const Student& b) {
    return a.calculateFinalMedian() < b.calculateFinalMedian();
}