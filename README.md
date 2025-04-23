# Naudojimo instrukcija:
1. Yra aplankas vector su programa.
2. Kad paleisti programą, jums reikia įeiti į tą aplanką ir ten paleisti runme.bat
3. Programa turi atsidaryti terminale, taip pat ir sukurti projektą jūsų IDE

# Reikalavimai:
- Windows 10 x64bit ar naujesnė versija
- Instaliuotas CMake

# Dokumentacija
### Klasės "Studentas" Dokumentacija yra pasiekiama aplanke "Documentation"
- Yra HTML, LaTex ir .PDF formatai
- Sukurta naudojant DoxyGen

# Unit tests
### Klasė "Studentas" buvo protestuota naudojant CPP unit tests. 
#### Testo pavyzdys:   
![image](https://github.com/user-attachments/assets/b6429876-95ae-4f05-8bca-96fbb6bc1cf3)
#### Visus testus klase praejo:   
![image](https://github.com/user-attachments/assets/caadca10-bc31-45cd-8a53-6a3d3fe3aeda)

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
## v2.0
- Naujausia versija
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
