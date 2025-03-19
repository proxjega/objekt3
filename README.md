# Naudojimo instrukcija:
1. Yra 3 programos versijos: su Vector, Deque ir List konteineriais. Jų kodai yra atitinkamai aplankuose
2. Kad paleisti programą, jums reikia įeiti į norima aplanką ir ten paleisti runme.bat
3. Programa turi atsidaryti terminale, taip pat ir sukurti projektą jūsų IDE

# Reikalavimai:
- Windows 10 x64bit ar naujesnė versija
- Instaliuotas CMake

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
