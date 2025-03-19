#include "../include/studentas.h"

Student::Student() {

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
    return a.vid() < b.vid();
}

bool CompareByMed(const Student& a, const Student& b) {
    return a.median() < b.median();
}