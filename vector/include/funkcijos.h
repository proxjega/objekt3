#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <random>
#include <chrono>
#include <locale>
#include <codecvt>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::wcout;
using std::wstringstream;
using std::wstring;
using std::getline;
using std::wifstream;
using std::string;
using std::setw;
using std::left;
using std::setprecision;
using std::fixed;

template <class T>
void Readfile(std::wifstream& inputFile, T& grupe);
bool CompareByVid(Student a, Student b);
int InputTestNum();
