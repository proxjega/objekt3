#pragma once
#include "mylibrary.h"

template <class T>
void Readfile(std::wifstream& inputFile, T& grupe) { //skaitymas is failo
    wstring temp;
    getline(inputFile, temp);
    wstringstream ss(temp);
    int counter = 0;
    while (ss >> temp) {
        counter++;
    }
    wstringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();
    while (buffer) {
        if (buffer.eof()) {
            break;
        }
		wstring name, surname;
        vector<int> marks;
        int mark, examMark; 
        buffer >> surname >> name;
        for (int i = 0; i < counter - 3; i++) {
            buffer >> mark;
            marks.push_back(mark);
        }
        buffer >> mark;
        examMark = mark;
		Student student(name, surname, marks, examMark);
        grupe.push_back(student);
    }
}

template <class arr1, class arr2, class arr3>
void SortStudentsInGroups(arr1& kietiakai, arr2& vargsiukai, arr3& group, bool sortType) { //sorting function
    for (int i = 0; i < group.size(); i++) {
        if (sortType == 1) {
            if (group[i].calculateFinalMean() < 5.0) {
                vargsiukai.push_back(group[i]);
            }
            else {
                kietiakai.push_back(group[i]);
            }
        }
        else {
            if (group[i].calculateFinalMedian() < 5.0) {
                vargsiukai.push_back(group[i]);
            }
            else {
                kietiakai.push_back(group[i]);
            }
        }
    }
    kietiakai.shrink_to_fit();
    vargsiukai.shrink_to_fit();
}

template <class arr1, class arr2>
void SortStudentsInGroups2(arr1& vargsiukai, arr2& group, bool sortType) { //sorting function
    for (auto it = group.begin(); it != group.end(); ) {
        if (sortType == 1) {
            if (it->calculateFinalMean() < 5.0) {
                vargsiukai.push_back(*it);
                it = group.erase(it);
            }
            else {
                ++it;
            }
        }
        else {
            if (it->calculateFinalMedian() < 5.0) {
                vargsiukai.push_back(*it);
                it = group.erase(it);
            }
            else {
                ++it;
            }
        }
    }
}

template <class T>
void PrintIntoFile(T& group, wstring fileName) {
    wstringstream output;
    output << setw(17) << left << L"Pavardė" << setw(17) << left << L"Vardas" << setw(20) << left << "Galutinis(vid.)" << setw(15) << left << "Galutinis(med.)\n";
    output << "-----------------------------------------------------------------------------------\n";
    for (int i = 0; i < group.size(); i++) {
        output << setw(17) << left << group[i].getSurname() << setw(17) << left
            << group[i].getName() << setw(20) << left << setprecision(2) << fixed
            << group[i].calculateFinalMean() << setw(15) << left << setprecision(2) << fixed << group[i].calculateFinalMedian() << L"\n";
    }
    std::wofstream outputFile(fileName);
    outputFile.imbue(std::locale(outputFile.getloc(), new std::codecvt_utf8<wchar_t>));
    outputFile << output.str();
    outputFile.close();
}

template <class arr1, class arr2, class arr3>
void TestFunction(arr1& grupe, arr2& vargsiukai, arr3& kietiakai) {
    double readMean = 0, sortMean = 0, printMean = 0, allMean = 0;
    std::wofstream researchResults("spartos_tyrimas\\class\\tyrimas1StrategijaClass.txt", std::ios::app);
    wstringstream output; 
	wstring containers[] = {L"Vector", L"Deque", L"List"};
    int containerNum = 0;

    wcout << L"Is kiek irasu testuoti programa?";
    int testNum;
    while (true) {
        try {
            testNum = InputTestNum();
            break;
        }
        catch (const wchar_t* e) {
            std::wcerr << e << endl;
            continue;
        }
        catch (...) {
            std::wcerr << L"\007Nezinoma klaida" << endl;
            continue;
        }
    }
    wcout << L"Testo pradzia\n";
    for (int i = 0; i < 5; i++) {
        string inputFileName = "studentai" + std::to_string(testNum) + ".txt";
        wifstream inputFile(inputFileName);
        if (!inputFile) {
            std::wcerr << L"Failas nerastas\n";
            return;
        }
    
        std::ofstream testFile;
        if (std::is_same<typename std::decay<decltype(grupe)>::type, std::vector<Student>>::value) {
            testFile.open("spartos_tyrimas\\class\\tyrimasVector.txt", std::ios::app);
			containerNum = 0;
        }
        else if (std::is_same<typename std::decay<decltype(grupe)>::type, std::deque<Student>>::value) {
			testFile.open("spartos_tyrimas\\class\\tyrimasDeque.txt", std::ios::app);
			containerNum = 1;
        }
        else if (std::is_same<typename std::decay<decltype(grupe)>::type, std::list<Student>>::value) {
			testFile.open("spartos_tyrimas\\class\\tyrimasList.txt", std::ios::app);
			containerNum = 2;
		}
        else
            testFile.open("spartos_tyrimas\\class\\tyrimasUnknown.txt", std::ios::app); // Default fallback

    
        testFile << "Programos veikimas: \n";

        std::chrono::time_point<std::chrono::system_clock> programStart = std::chrono::system_clock::now();
        Readfile(inputFile, grupe);
        grupe.shrink_to_fit();
        std::chrono::time_point<std::chrono::system_clock> endReading = std::chrono::system_clock::now();

        std::chrono::time_point<std::chrono::system_clock> startSorting = std::chrono::system_clock::now();
        SortStudentsInGroups(kietiakai, vargsiukai, grupe, 1);
        grupe.clear();
        grupe.shrink_to_fit();
        sort(kietiakai.begin(), kietiakai.end(), [](const Student& s1, const Student& s2) -> bool {
            return s1.calculateFinalMean() < s2.calculateFinalMean();
            });
        sort(vargsiukai.begin(), vargsiukai.end(), [](const Student& s1, const Student& s2) -> bool {
            return s1.calculateFinalMean() < s2.calculateFinalMean();
            });
        std::chrono::time_point<std::chrono::system_clock> endSorting = std::chrono::system_clock::now();

        std::chrono::time_point<std::chrono::system_clock> startOutput = std::chrono::system_clock::now();
        wstring outputFileName = L"vargsiukuRezultatai.txt";
        PrintIntoFile(vargsiukai, outputFileName);
        outputFileName = L"kietiakuRezultatai.txt";
        PrintIntoFile(kietiakai, outputFileName);
        std::chrono::time_point<std::chrono::system_clock> endOutput = std::chrono::system_clock::now();

        testFile << "Duomenu nuskaitymas is " << testNum << " irasu: " << std::chrono::duration<double>(endReading - programStart).count() << " s\n";
        testFile << "Studentu rusiavimas i 2 grupes is " << testNum << " irasu: " << std::chrono::duration<double>(endSorting - startSorting).count() << " s\n";
        testFile << "Surusiuotu studentu isvedimas is " << testNum << " irasu: " << std::chrono::duration<double>(endOutput - startOutput).count() << " s\n";
        testFile << "Visos programos veikimo laikas is " << testNum << " irasu: " << std::chrono::duration<double>(endOutput - programStart).count() << " s\n\n";
		if (i == 4) testFile << "----------------------------------------------------------------------------------------------------------------\n";
        readMean += std::chrono::duration<double>(endReading - programStart).count();
		sortMean += std::chrono::duration<double>(endSorting - startSorting).count();
		printMean += std::chrono::duration<double>(endOutput - startOutput).count();
		allMean += std::chrono::duration<double>(endOutput - programStart).count();
        grupe.clear();
		kietiakai.clear();
		vargsiukai.clear();
    }
	readMean = readMean / 5.0;
	sortMean = sortMean / 5.0;
	printMean = printMean / 5.0;
	allMean = allMean / 5.0;
	
    /*output << setw(17) << left << L"Container" << setw(17) << left << L"Irasu sk." << setw(25) << left << "Skaitymo vidurkis(s)" << setw(25) << left << "Rusiavimo vidurkis(s)" << setw(25) << left << "Isvedimo vidurkis(s)" << setw(25) << left << "Visos programos vidurkis(s)\n";
    output << "-------------------------------------------------------------------------------------------------------\n";*/
	output << setw(17) << left << containers[containerNum] << setw(17) << left << testNum << setw(25) << left << readMean << setw(25) << left << sortMean << setw(25) << left << printMean << setw(25) << left << allMean << L"\n";
	researchResults << output.str();
    wcout << L"Testas baigtas. Patikrinkite spartos_tyrimas aplanka\n";
}

template <class arr1, class arr2>
void TestFunction2(arr1& grupe, arr2& vargsiukai) {
    double readMean = 0, sortMean = 0, printMean = 0, allMean = 0;
    std::wofstream researchResults("spartos_tyrimas\\class\\tyrimas2Strategija.txt", std::ios::app);
    wstringstream output;
    wstring containers[] = { L"Vector", L"Deque", L"List" };
    int containerNum = 0;

    wcout << L"Is kiek irasu testuoti programa?";
    int testNum;
    while (true) {
        try {
            testNum = InputTestNum();
            break;
        }
        catch (const wchar_t* e) {
            std::wcerr << e << endl;
            continue;
        }
        catch (...) {
            std::wcerr << L"\007Nezinoma klaida" << endl;
            continue;
        }
    }
    wcout << L"Testo pradzia\n";
    for (int i = 0; i < 5; i++) {
        string inputFileName = "studentai" + std::to_string(testNum) + ".txt";
        wifstream inputFile(inputFileName);
        if (!inputFile) {
            std::wcerr << L"Failas nerastas\n";
            return;
        }

        std::ofstream testFile;
        if (std::is_same<typename std::decay<decltype(grupe)>::type, std::vector<Student>>::value) {
            testFile.open("spartos_tyrimas\\class\\tyrimasVector2.txt", std::ios::app);
            containerNum = 0;
        }
        else if (std::is_same<typename std::decay<decltype(grupe)>::type, std::deque<Student>>::value) {
            testFile.open("spartos_tyrimas\\class\\tyrimasDeque2.txt", std::ios::app);
            containerNum = 1;
        }
        else if (std::is_same<typename std::decay<decltype(grupe)>::type, std::list<Student>>::value) {
            testFile.open("spartos_tyrimas\\class\\tyrimasList2.txt", std::ios::app);
            containerNum = 2;
        }
        else
            testFile.open("spartos_tyrimas\\class\\tyrimasUnknown2.txt", std::ios::app); // Default fallback


        testFile << "Programos veikimas: \n";

        std::chrono::time_point<std::chrono::system_clock> programStart = std::chrono::system_clock::now();
        Readfile(inputFile, grupe);
        std::chrono::time_point<std::chrono::system_clock> endReading = std::chrono::system_clock::now();

        std::chrono::time_point<std::chrono::system_clock> startSorting = std::chrono::system_clock::now();
        SortStudentsInGroups2(vargsiukai, grupe, 1);
        sort(grupe.begin(), grupe.end(), [](const Student& s1, const Student& s2) -> bool {
            return s1.calculateFinalMean() < s2.calculateFinalMean();
            });
        sort(vargsiukai.begin(), vargsiukai.end(), [](const Student& s1, const Student& s2) -> bool {
            return s1.calculateFinalMean() < s2.calculateFinalMean();
            });
        std::chrono::time_point<std::chrono::system_clock> endSorting = std::chrono::system_clock::now();

        std::chrono::time_point<std::chrono::system_clock> startOutput = std::chrono::system_clock::now();
        wstring outputFileName = L"vargsiukuRezultatai.txt";
        PrintIntoFile(vargsiukai, outputFileName);
        outputFileName = L"kietiakuRezultatai.txt";
        PrintIntoFile(grupe, outputFileName);
        std::chrono::time_point<std::chrono::system_clock> endOutput = std::chrono::system_clock::now();

        testFile << "Duomenu nuskaitymas is " << testNum << " irasu: " << std::chrono::duration<double>(endReading - programStart).count() << " s\n";
        testFile << "Studentu rusiavimas i 2 grupes is " << testNum << " irasu: " << std::chrono::duration<double>(endSorting - startSorting).count() << " s\n";
        testFile << "Surusiuotu studentu isvedimas is " << testNum << " irasu: " << std::chrono::duration<double>(endOutput - startOutput).count() << " s\n";
        testFile << "Visos programos veikimo laikas is " << testNum << " irasu: " << std::chrono::duration<double>(endOutput - programStart).count() << " s\n\n";
        if (i == 4) testFile << "----------------------------------------------------------------------------------------------------------------\n";
        readMean += std::chrono::duration<double>(endReading - programStart).count();
        sortMean += std::chrono::duration<double>(endSorting - startSorting).count();
        printMean += std::chrono::duration<double>(endOutput - startOutput).count();
        allMean += std::chrono::duration<double>(endOutput - programStart).count();
        grupe.clear();
        vargsiukai.clear();
    }
    readMean = readMean / 5.0;
    sortMean = sortMean / 5.0;
    printMean = printMean / 5.0;
    allMean = allMean / 5.0;

    /*output << setw(17) << left << L"Container" << setw(17) << left << L"Irasu sk." << setw(25) << left << "Skaitymo vidurkis(s)" << setw(25) << left << "Rusiavimo vidurkis(s)" << setw(25) << left << "Isvedimo vidurkis(s)" << setw(25) << left << "Visos programos vidurkis(s)\n";
    output << "-------------------------------------------------------------------------------------------------------\n";*/
    output << setw(17) << left << containers[containerNum] << setw(17) << left << testNum << setw(25) << left << readMean << setw(25) << left << sortMean << setw(25) << left << printMean << setw(25) << left << allMean << L"\n";
    researchResults << output.str();
    wcout << L"Testas baigtas. Patikrinkite spartos_tyrimas aplanka\n";
}