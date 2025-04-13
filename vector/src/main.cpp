#include "../include/mylibrary.h"
#include "../include/templates.h"


int main()
{
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stderr), _O_U8TEXT);
    srand(time(NULL));
    vector<Student> grupe, vargsiukai, kietiakai;
    float galutinisVid = 0;
    float mediana = 0;
    char menu;
    bool check = true;
    bool sortType = 1;
	wstring inputFileName;
    wstring outputFileName;
	wifstream inputFile;
    std::ofstream test;

    myVector<int> v1;
    v1.push_back(2);
    wcout << "xd\n";
    v1.push_back(3);
    wcout << "xd\n";
    cout << v1[1];

    while (check == true) {
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
			Case4(grupe);
            break;
        case('5'):
			Case5(grupe, vargsiukai, kietiakai);
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
            sort(kietiakai.begin(), kietiakai.end(), [](const Student& s1, const Student& s2) -> bool {
				return s1.getName() < s2.getName();
                });
            sort(vargsiukai.begin(), vargsiukai.end(), [](const Student& s1, const Student& s2) -> bool {
                return s1.getName() < s2.getName();
                });
            break;
        case('2'):
            sort(kietiakai.begin(), kietiakai.end(), [](const Student & s1, const Student & s2) -> bool {
                return s1.getSurname() < s2.getSurname();
            });
            sort(vargsiukai.begin(), vargsiukai.end(), [](const Student& s1, const Student& s2) -> bool {
                return s1.getSurname() < s2.getSurname();
                });
            break;
        case('3'):
            sort(kietiakai.begin(), kietiakai.end(), [](const Student& s1, const Student& s2) -> bool {
                return s1.calculateFinalMean() < s2.calculateFinalMean();
                });
            sort(vargsiukai.begin(), vargsiukai.end(), [](const Student& s1, const Student& s2) -> bool {
                return s1.calculateFinalMean() < s2.calculateFinalMean();
                });
            break;
        case('4'):
            sort(kietiakai.begin(), kietiakai.end(), [](const Student& s1, const Student& s2) -> bool {
                return s1.calculateFinalMedian() < s2.calculateFinalMedian();
                });
            sort(vargsiukai.begin(), vargsiukai.end(), [](const Student& s1, const Student& s2) -> bool {
                return s1.calculateFinalMedian() < s2.calculateFinalMedian();
                });
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
