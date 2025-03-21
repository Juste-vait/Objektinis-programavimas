v1.0 galutinis

Kopiuterio parametrai:
CPU - Apple M3
RAM - 16 GB
SSD - 494,38 GB

Programos paleidimas su "Makefile":
1) Parsisiųsti source code
2) naudojantis cd įeiti į reikiamą folder'į
3) Susiinstaliuoti make: https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows
4) Sukompiliuoti programą: make
5) Paleisti programą: make run

Programa leidžia pasirinkti norimą konteinerį (vector, deque, list) ir su juo atlieka įvairius veiksmus:
nuskaito duomenis iš norimo failo, 
surikiuoja pagal norimą parametrą,
sugrupuoja pagal norimą strategiją ir parametrą,
ir išveda į du failus pagal grupes.

Programos tikslas - ištestuoti skirtingų konteinerių atminties naudojimą ir veikimo spartą nuskaitant iš failo, rikiuojant bei grupuojant skirtingomis strategijomis.

Pirmas meniu pasirinkimas:
1 - vector
2 - deque
3- list

Rikiavimo pasirinkimas:
1 - pagal vardą
2 - pagal pavardę
3 - pagal vidurkį
4 - pagal medianą

Grupavimo pasirinkimas (strategija):
1 - strategija (iš pirminio "studentai" konteinerio pagal pažymius studentus perkelia į du naujus "kietekai" ir "nuskriaustukai" koonteinerius. Studento duomenus lieka dviejuose konteineriuose: "studentai" ir viename iš naujų).
2 - strategija ("studentai" yra surūšiuojami mažėjimo tvarka (neįeina į laiko skaičiavimą) . Iš pirminio "studentai" konteinerio pagal pažymius reikiami studentai yra perkeliami į "nuskriaustukai" konteinerį ir ištrinami iš "studentai" konteinerio, o "kietekai" lieka "studentai" konteineryje).
3 - startegija (naudojami STL algoritmas: std::partition. Iš pradinio studentai konteinerio visi studentai yra perrūšiuojami taip, kad pirmiausia būtų tie, kurių galutinis balas yra ≥5 o gale tie, kurių balas <5. Gale esantys studentai yra perkeliami į "nuskriaustukai" konteinerį ir pašalinami iš "studentai" konteinerio).

Grupavimo pasirinkimas (parametras):
V - pagal vidurki
M - pagal medianą


Išvados: 
nuskaitymas greičiausiai veikia su vector
rikiavimas vector ir deque taip pat, list lėčiausiai
grupavimas greičiausiai veikia su list


Tyrimų rezultatai:

![Image 21-03-2025 at 11 21](https://github.com/user-attachments/assets/b130cf34-02f7-4559-9503-de3c4610b1ea)


![Image 21-03-2025 at 11 21](https://github.com/user-attachments/assets/3c586d71-daed-4634-85dd-767fe1f3ea93)


![Image 21-03-2025 at 11 22](https://github.com/user-attachments/assets/fd108eb5-1332-4aa7-9673-bc8e554d4bea)





