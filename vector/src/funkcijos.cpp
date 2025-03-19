#include "../include/funkcijos.h"

float Mean(Student st) {
    return (std::accumulate(st.marks.begin(), st.marks.end(), 0) * 1.0) / (st.marks.size() * 1.0);
}

float Median(Student st) {
    float median = 0;
    sort(st.marks.begin(), st.marks.end());
    (st.marks.size() % 2 != 0) ? median = st.marks[st.marks.size() / 2] : median = (st.marks[st.marks.size() / 2] + st.marks[st.marks.size() / 2 - 1]) / 2.0;
    median = median * 0.4 + st.examMark * 0.6;
    return median;
}



void FileGen(int n) {
    string name;
    name = "studentai" + std::to_string(n) + ".txt";
    std::ofstream file(name);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    file << setw(17) << left << "Pavarde" << setw(17) << left << "Vardas" << setw(10) << left << "ND1"
        << setw(10) << left << "ND2" << setw(10) << left << "ND3" << setw(10) << left << "ND4" << setw(10) << left << "ND5" << setw(9) << left << "Egzaminas";
    for (int i = 0; i < n; i++) {
        file << endl;
        file << setw(17) << left << "Pavarde" + std::to_string(i + 1) << setw(17) << left << "Vardas" + std::to_string(i + 1)
            << setw(10) << left << dist(mt) << setw(10) << left << dist(mt) << setw(10) << left << dist(mt) << setw(10) << left << dist(mt)
            << setw(10) << left << dist(mt) << dist(mt);
    }
    file.close();
}

