# Naudojimo instrukcija:
### Yra 2 budai paleisti programa:
## Naudojant installeri:
1) Ieiti i "Setup" aplanka
2) Paleisti **setup.exe**
3) ![image](https://github.com/user-attachments/assets/95aeb60d-5b32-4406-b10b-e08b2695dd8f)
4) Pasirinkite kur instaliuoti, taip pat ar instaliuoti visiems useriams, ar tik vienam:  
![image](https://github.com/user-attachments/assets/818b2207-0cd8-4814-91bd-78d6b9497309)
5) ![image](https://github.com/user-attachments/assets/7f364217-04ae-43dc-a18a-f014e98860cd)
6) Kai instaleris paprasys admino teises, paspauskite "Yes"
#### Instaleris instaliuos programa, taip pat sukurti nuoroda jusu desktope ir aplanka *Start Menu*

## Sukompiliuoti paciam (naudojant CMake)
1) Ieiti i aplanka "source code"
2) Paspausti **runme.bat**
#### Programa bus sukompiliuota ir paleista, taip pat bus sukurtas projektas jusu IDE

# Reikalavimai:
- Windows 10 x64bit ar naujesnė versija
- Instaliuotas CMake (Kompiliavimui)
- Microsoft Visual C++

# myVector klase:
### Buvo sukurta alternatyva klasei std::vector - **myVector**
### Konteineris atlieka tas pacias funkcijas, kaip ir std::vector.
### Keliu metodu pavyzdziai:
- Reserve   
 ![image](https://github.com/user-attachments/assets/3d4678d6-5b56-47c3-a87e-00392747bd0a)   
Rezervuoja atminti vektoriui. Jeigu duotas skaicius yra mazesnis negu dabartinis **capacity_** - funkcija nieko nedaro. Kitu atveju rezervuoja tiek atminties, kiek buvo paduota su parametru **num**. Veikimo principas:  
1) Rezervuojama nauja atmintis  
2) Kopijuojami duomenis is senos atminties  
3) Sena atmintis trinama, jos rodykle perkeliama i nauja atminti.  
4) Atnaujinami visi iteratoriai (begin_, end_). **size_** nesikeicia.
- Shrink_to_fit  
![image](https://github.com/user-attachments/assets/ac0ffd92-f21f-4384-8d53-5fa90f891299)  
Sumazina rezervuota atminti iki tiek, kiek uzimta dabar (size_ elementu). Jeigu uzimta kiek rezervuota (capacity_==size_) - nieko nedaro. Veikimo principas:
1) Keicia **capacity_** iki **size_**
2) Rezervuoja nauja atminti
3) Kopijuoja duomenis is senos atminties i nauja
4) Sena atmintis atlaisvinama, jos rodykle perkeliama i nauja atminti
5) Atnaujinami iteratoriai.
- Operatorius = su std::initializer_list  
![image](https://github.com/user-attachments/assets/5c9416ed-b892-4f00-8219-7b1dd683764b)  
Priskiria vektoriui reiksmes, kurios yra std::initalizer_list. Veikimo principas:  
1) Iskviecia destruktoriu (kad saugiai atlaisvinti sena atminti)
2) Priskiria vektoriui toki **size_** ir **capacity_**, kiek elementu yra list'e
3) Rezervuoja atminti
4) Kopijuoja elementus is list'o i rezervuota atminti
5) Atnaujina iteratorius
6) Grazina vektoriu.
- push_back  
![image](https://github.com/user-attachments/assets/e696b0d7-1748-4fec-963e-63e99a4a43e8)  
Ideda reiksme i vektoriaus gala. Veikimo principas:  
1) Tikrina, ar yra rezervuota atmintis. Jei jos nera - rezervuoja
2) Jeigu vektoriuje nera elementu - ideda pirma elementa, atnaujina **size_** ir iteratorius
3) Jei vektoriuje yra elementai - tikrina, ar **size_** == **capacity_**.  
3.1 Jei taip - rezervuoja nauja atminti **capacity_\*2** elementams, kopijuoja elementus, atlaisvina sena atminti, perkelia rodykle, atnaujina iteratorius.  
3.2 Jei ne - ideda nauja elementa i saraso gala, perkelia iteratoriu **end_**, atnaujina **size_**
- pop_back  
![image](https://github.com/user-attachments/assets/b9fe830f-666d-4f1d-a3d7-414398f0f564)  
Trina paskutini elementa. Jeigu vektorius tuscias - nieko nedaro. Veikimo principas:  
1) Tikrina ar **size_** yra nulis. Jeigu taip - nieko nedaro.
2) Kviecia paskutinio elemento destruktoriu (jei jis yra)
3) Mazina **size_**
4) Perkelia iteratoriu **end_**

# myVector klases spartos tyrimas
### myVector klase buvo protestuota, lyginant su std::vector
#### 1 testas: kiek vidutiniškai laiko užtrunka std::vector tipo ir myVector tipo tuščius vektorius užpildyti: 10000, 100000, 1000000, 10000000 ir 100000000 int elementų naudojant push_back() funkciją:
![image](https://github.com/user-attachments/assets/b9c59e5b-2d32-472a-8edd-fd5a22af4c29)   
Pasirodo, std::vector siek tiek laimi
#### 2 testas: programos veikimo laikas:
![image](https://github.com/user-attachments/assets/880ed238-88ea-4c7c-b4ad-c6efc2a4143d)   
Matosi, kad myVector yra greitesnis. Kai irasu dydis yra mazas tai yra beveik nepastebima, bet kai irasu dydis didesnis - skirtumas pastebimas.
### Visa informacija yra pasiekiama aplanke "spartos_tyrimas/vector vs myVector

# Dokumentacija
### Klasės "Studentas" ir klases "myVector" dokumentacijos yra pasiekiamos aplanke "Documentation"
- Yra HTML, LaTex ir .pdf formatai
- Sukurta naudojant DoxyGen

# Unit tests
### Klasė "Studentas" ir klase "myVector" buvo protestuotos naudojant CPP unit tests. 
#### Testo pavyzdys:   
![image](https://github.com/user-attachments/assets/b6429876-95ae-4f05-8bca-96fbb6bc1cf3)
#### Visus testus klase "Studentas" praejo:   
![image](https://github.com/user-attachments/assets/caadca10-bc31-45cd-8a53-6a3d3fe3aeda)
#### Klase "myVector" irgi:
![image](https://github.com/user-attachments/assets/1e66175c-046b-44e8-b5f5-3cbefa968c26)
#### Visi testai yra pasiekiami aplanke "UnitTest1"

# v1.5:  Abstrakti bazinė klasė
### Buvo sukurta abstrakti bazinė klasė "Human"
![image](https://github.com/user-attachments/assets/2ebd4a77-63d8-405f-9055-a4fdb577dfab)
### Programa buvo protestuota naudojant testą iš 1.2 versijos:
![image](https://github.com/user-attachments/assets/3fdd2b68-f646-4b4a-ae67-f6f9d2a87129)
#### Viskas veikia.

# v1.2: Rule of five
### Buvo sukurti 5 metodai:
- destructor
- copy constructor
- move constructor
- copy assignment operator
- move assignment operator
### Taip pat buvo perdengti operatoriai: << ir >>
#### Funkcijoje "testavimas" galima protestuoti, kaip viekie visi metodai.
![image](https://github.com/user-attachments/assets/0dd947aa-c483-4149-a0b0-b20581a0729b)
#### Matomas visu metodų veikimas
#### >> operatorius leidžia įvesti duomenis iš konsolės (stdin) su įvesties validacija
Įvedimas iš failo realizuotas per atskira funkciją.
#### << operatorius leidžia išvesti duomenis bet kur (konsolė, failas)
Išveda studento pavardę, vardą, po to vidurkį ir medianą.

# Spartos tyrimas:
### Buvo atliktas programos spartos tyrimas, naudojant skirtingų įrašų dydžio duomenų failus.  
### Testavimo sistemos parametrai:
- CPU: AMD Ryzen 7 7735HS, 3.50 GHz
- RAM: 16GB
- Disk: SSD M.2 PCIe 4.0x4 NVMe
- Release version (in Visual Studio 2022)
- -O3 optimization flag
## 1 strategijos rezultatai:
(Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų")  
  
![image](https://github.com/user-attachments/assets/0da29df4-498d-4ad7-8e8b-c09c8d08d001)
#### Čia yra pateikti 5 testų vidurkiai.
### Pasirodo, Deque konteineris yra greičiausias, kai įrašų skaičius didesnis nei 100000. Kai šis skaičius mažesnis - laimi Vector.
## 2 strategijos rezultatai:
(Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai)  
  
![image](https://github.com/user-attachments/assets/7051e49e-cff7-4a44-8235-97bd675ee202)
#### Deque ir Vector konteineriai nepraėjo visų testų, nes jiems ši strategija yra ypač neefektyvi: 
![image](https://github.com/user-attachments/assets/a51622b2-e771-4944-9fdc-b7e6047797e1) (deque) ![image](https://github.com/user-attachments/assets/825b2c5e-fa46-4ad2-acd3-186c3a56290c) (vector)
### Taigi 2 strategijos atžvilgiu laimi List.

## Visa informacija ir kiekvieno testo laikai yra pasiekiama aplanke "spartos_tyrimas"

# Versijos:
## v3.0
- Naujausia versija
- Sukurtas konteineris "myVector", alternatyva std::vector
- Konteineris protestuotas, sukurta dokumentacija
- Pridetas setup.exe
## v2.0
- Atliktas klases testavimas naudojant CPP Unit tests
- Sukurta klases dokumentacija
## v1.5
- Yra abstrakti bazinė klasė "Human", o klasė "Student" yra išvestinė
## v1.2
- Naujausia versija
- Pridėti penki metodai iš "Rule of five"
## v1.1
- Vector versijoje struct pakeista i class
- Atliktas spartos tyrimas tarp class ir struct
## v1.0-final
- Naujausia versija
- Pridėta 2 strategija, atliktas spartos tyrimas
## v1.0-pradine
- Yra 3 programos, veikiančios su skirtingais konteineriais
- Atliktas spartos tyrimas
## v0.4
- Pridėtas studentų rušiavimas į 2 grupes pagal jų pažangumą
- Atliktas spartos tyrimas naudojant skirtingų įrašų kiekio failus
- Pridėta failų generavimo funkcija
## v0.3
- Programos kodas atskirtas į skirtingus .cpp ir .h failus
- Pridėtas klaidų gaudymo mechanizmas
## v0.2
- Pridėta galimybė skaityti duomenis iš failo
- Gražus studentų išvedimas į failą
- Studentų rušiavimas
## v0.1
- Veikia kai studentu ir pazymiu skaicius yra nezinomas is anksto
- Yra versija su c masyvu ir versija su vektoriais (vektoriu versija pagrindine)
- Pridėtas atsitiktinis vardu ir pazymiu generavimas
- Pridėta apsauga nuo netinkamų simbolių ir skaičių įvedimo
## v.pradinee
- Pradinė programos versija
