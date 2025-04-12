﻿#include "../include/funkcijos.h"

void Case1(vector<Student> &grupe) {
    wstring name, surname;
    vector<int> marks;
    int examMark;
    system("cls");
    wcout << L"Įveskite studento vardą:\n";
    wcin >> name;
    wcout << L"Įveskite studento pavardę:\n";
    wcin >> surname;
    wcout << L"Įveskite pažymius (0 - pabaigti)\n";
    while (true) {
        try {
            int mark = InputMark();
            if (mark == 0) {
                if (marks.size() != 0) {
                    break;
                }
                else throw L"\007Įveskite bent vieną pažymį";
                continue;
            }
            marks.push_back(mark);
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
            examMark = InputExamMark();
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
    Student student(name, surname, marks, examMark);
    grupe.push_back(student);
}

void Case2(vector<Student>& grupe) {
    wstring name, surname;
    int markNum;
    system("cls");
    wcout << L"Įveskite studento vardą:\n";
    wcin >> name;
    wcout << L"Įveskite studento pavardę:\n";
    wcin >> surname;
    wcout << L"Kiek pažymių generuoti?\n";
    while (true) {
        try {
            markNum = InputMarkNum();
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
	Student student(name, surname, markNum);
    grupe.push_back(student);
}

void Case3(vector<Student> &grupe) {
    int markNum;
    system("cls");
    wcout << L"Kiek pažymiu generuoti?\n";
    while (true) {
        try {
            markNum = InputMarkNum();
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
	Student student(markNum);
    grupe.push_back(student);
}

void Case4(vector<Student>& grupe) {
	wstring inputFileName;
	wifstream inputFile;
    system("cls");
    wcout << L"Iš kokio failo nuskaityti duomenis?\n\n";
    system("dir /b *.txt");
    wcin >> inputFileName;
    try {
        inputFile.open(inputFileName);
        if (!inputFile) {
            throw L"\007Failas nerastas";
        }
        Readfile(inputFile, grupe);
        wcout << L"\nDuomenys nuskaityti.\n";
    }
    catch (const wchar_t* e) {
        wcerr << e << endl;
        return;
    }
    catch (...) {
        wcerr << L"\007Nežinoma klaida" << endl;
        return;
    }
}

void Case5(vector<Student>& grupe, vector<Student> &vargsiukai, vector<Student> &kietiakai) {
	int strategy;
    wcout << L"Kokią strategiją naudoti? 1 ar 2?\n";
    wcout << L"Arba norite ištestuoti Rule of Five? 3\n";
    while (true) {
        try {
            strategy = InputStrategy();
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
    if (strategy == 1) TestFunction(grupe, vargsiukai, kietiakai);
    if (strategy == 2) TestFunction2(grupe, vargsiukai);
    if (strategy == 3) TestRuleOfFive();
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

void TestRuleOfFive() {
    //Human test;// not allowed
    wcout << L"Testing rule of five...\n";
    Student first;
    wcin >> first;
    wcout << L"____________________________________\nCopying through constructor: \n";
    wcout << L"Original:\n" << first;
    Student firstCopy(first);
    wcout << L"Copy constructor:\n" << firstCopy;
    wcout << L"Original after copying\n" << first;
	wcout << L"____________________________________\nCopying through operator:\n";
    wcout << L"Original:\n" << first;
    Student firstCopyOperator = first;
    wcout << L"Copy operator:\n" << firstCopyOperator;
    wcout << L"Original after copying\n" << first;
	wcout << L"____________________________________\nMoving through constructor:\n";
    wcout << L"Original:\n" << first;
    Student firstMove(std::move(first));
    wcout << L"Move constructor:\n" << firstMove;
    wcout << L"Original after moving:\n" << first;
	wcout << L"____________________________________\nMoving through operator:\n";
    wcout << L"Original:\n" << firstCopy;
    Student firstMoveOperator = std::move(firstCopy);
    wcout << L"Move operator:\n" << firstMoveOperator;
    wcout << L"Original after moving:\n" << firstCopy;
    wofstream output(L"overloadedOperatorTest.txt");
    output.imbue(std::locale(output.getloc(), new std::codecvt_utf8<wchar_t>)); 
	output << "Testing operator << into file:\n";
    output << firstCopyOperator;
	output.close();
	system("notepad.exe overloadedOperatorTest.txt");
}

