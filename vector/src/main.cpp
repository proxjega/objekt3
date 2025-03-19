#include "../include/mylibrary.h"
#include "../include/templates.h"
#include "../include/studentas.h"


int main()
{

    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stderr), _O_U8TEXT);
    srand(time(NULL));

    vector<Student> grupe, vargsiukai, kietiakai;
    float galutinisVid = 0;
    float mediana = 0;
    char menu;
    int markNum;
    int randExMark;
    int randMark;
	int strategy;
    bool check = true;
    bool sortType = 1;

    wstring name, surname;
	vector<int> marks;
    int examMark;

	wstring inputFileName;
    wstring outputFileName;
	wifstream inputFile;
    std::ofstream test;

    while (check == true) {
		marks.clear();
        wcout << "---------------------------------\nMENU\n";
        wcout << L"1 - ranka įvesti duomenis\n2 - generuoti pažymius\n3 - generuoti ir pažymius ir studentų vardus, pavardės\n4 - įvesti duomenis iš failo\n5 - testavimas\n6 - baigti darbą\n---------------------------------\n";
        cin >> menu;
        switch (menu)
        {
        case('1'):
			Case1(grupe);
            break;
        case('2'):
			Case2(grupe);
            break;
        case('3'):
			Case3(grupe);
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
