#include "pch.h"
#include "funkcijos.h"

int InputMark() {
    int value;
    while (true) {
        if (cin >> value && value <= 10 && value > -1) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite tinkamą pažymį nuo 1 iki 10 (0 - pabaigti)";
        }
    }
}

int InputMarkNum() {
    int value;
    while (true) {
        if (cin >> value && value > 0) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite tinkamą pažymių skaičių";
        }
    }
}

int InputExamMark() {
    int value;
    while (true) {
        if (cin >> value && value <= 10 && value > 0) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite tinkamą pažymį nuo 1 iki 10";
        }
    }
}

bool InputSortType() {
    bool value;
    while (true) {
        if (cin >> value) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite 0 arba 1";
        }
    }
}

int InputTestNum() {
    int value;
    while (true) {
        if (cin >> value && value <= 10000000 && value > 0) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite tinkamą įrašų skaičių";
        }
    }
}

int InputStrategy() {
    int value;
    while (true) {
        if (cin >> value && value <= 3 && value >= 1) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite tinkamą strategijos numerį";
        }
    }
}