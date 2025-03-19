#include "../include/mylibrary.h"
#include "../include/templates.h"
#include "../include/studentas.h"


int main()
{

    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stderr), _O_U8TEXT);
    srand(time(NULL));

    vector<Student> grupe, vargsiukai, kietiakai;
    wstring names[10] = { L"name1", L"name2", L"name3", L"name4", L"name5", L"name6", L"name7", L"name8", L"name9", L"name10",};
    wstring surnames[10] = { L"surname1", L"surname2", L"surname3", L"surname4", L"surname5", L"surname6", L"surname7",  L"surname8", L"surname9", L"surname10"};
    float galutinisVid = 0;
    float mediana = 0;
    char menu;
    int markNum;
    int randExMark;
    int randMark;
	int strategy;
    bool check = true;
    bool sortType = 1;
	wstring inputFileName;
    wstring outputFileName;
	wifstream inputFile;
    std::ofstream test;

    while (check == true) {
        Student student;
        wcout << "---------------------------------\nMENU\n";
        wcout << L"1 - ranka įvesti duomenis\n2 - generuoti pažymius\n3 - generuoti ir pažymius ir studentų vardus, pavardės\n4 - įvesti duomenis iš failo\n5 - testavimas\n6 - baigti darbą\n---------------------------------\n";
        cin >> menu;
        switch (menu)
        {
        case('1'):
			system("cls");
            wcout << L"Įveskite studento vardą:\n";
            wcin >> student.name;
            wcout << L"Įveskite studento pavardę:\n";
            wcin >> student.surname;
            wcout << L"Įveskite pažymius (0 - pabaigti)\n";
            while (true) {
                try {
                    int mark = InputMark();
                    if (mark == 0) {
                        if (student.marks.size() != 0) {
                            break;
                        }
                        else throw L"\007Įveskite bent vieną pažymį";
                        continue;
                    }
                    student.marks.push_back(mark);
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
                    student.examMark = InputExamMark();
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
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('2'):
            system("cls");
            wcout << L"Įveskite studento vardą:\n";
            wcin >> student.name;
            wcout << L"Įveskite studento pavardę:\n";
            wcin >> student.surname;
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
            for (int i = 0; i < markNum; i++) {
                randMark = rand() % 10 + 1;
                wcout << L"Generuotas pažymys: " << randMark << "\n";
                student.marks.push_back(randMark);
            }
            randExMark = rand() % 10 + 1;
            wcout << L"Generuotas egzamino pažymys: " << randExMark << "\n";
            student.examMark = randExMark;
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('3'):
            system("cls");
            student.name = names[rand() % 5];
            wcout << L"Generuotas vardas: " << student.name << endl;
            student.surname = surnames[rand() % 5];
            wcout << L"Generuota pavardė: " << student.surname << endl;
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
            for (int i = 0; i < markNum; i++) {
                randMark = rand() % 10 + 1;
                wcout << L"Generuotas pažymys: " << randMark << "\n";
                student.marks.push_back(randMark);
            }
            randExMark = rand() % 10 + 1;
            wcout << L"Generuotas egzamino pažymys: " << randExMark << "\n";
            student.examMark = randExMark;
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('4'):
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
				break;
			}
			catch (...) {
				wcerr << L"\007Nežinoma klaida" << endl;
                break;
			}
            break;
        case('5'):
            wcout << L"Kokią strategiją naudoti? 1,2 ar 3?\n";
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
            break;
        case('6'):
            system("cls");
            check = false;
            break;
        default:
            system("cls");
            wcout << L"\007Įveskite tinkamą skaičių nuo 1 iki 6\n";
            continue;
        }
    }
   grupe.shrink_to_fit();
    wcout << L"Pagal ką rušiuoti studentus į grupes? 1 - vidurkis, 0 - mediana\n";
    while (true) {
        try {
            sortType = InputSortType();
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
    system("cls");
    
    SortStudentsInGroups(kietiakai, vargsiukai, grupe, sortType);
    grupe.clear();
    grupe.shrink_to_fit();
    wcout << L"Pagal ką rušiuoti studentus? (1 - pagal vardą, 2 - pagal pavardę, 3 - pagal galutinį balą (vid.), 4 - pagal galutinį balą (med.))\n";
    while (true) {
        cin >> menu;
        switch (menu)
        {
        case('1'):
            sort(kietiakai.begin(), kietiakai.end(), CompareByName);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByName);
            break;
        case('2'):
            sort(kietiakai.begin(), kietiakai.end(), CompareBySurname);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareBySurname);
            break;
        case('3'):
            sort(kietiakai.begin(), kietiakai.end(), CompareByVid);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByVid);
            break;
        case('4'):
            sort(kietiakai.begin(), kietiakai.end(), CompareByMed);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByMed);
            break;
        default:
            wcout << L"\007Įveskite tinkama skaičių nuo 1 iki 4\n";
            continue;
        }
        break;
    }
    outputFileName = L"vargsiukuRezultatai.txt";
    PrintIntoFile(vargsiukai, outputFileName);
    outputFileName = L"kietiakuRezultatai.txt";
    PrintIntoFile(kietiakai, outputFileName);
	system("notepad.exe vargsiukuRezultatai.txt");
	system("notepad.exe kietiakuRezultatai.txt");
	return 0;
}
