#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>
#include <deque>
#include <variant>
#include <struct.h>

using namespace std;
using namespace std::chrono;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
    double galutinisVid;
    double galutinisMed;
};

double skaiciuotiVidurki(const vector<int>& pazymiai);

double skaiciuotiMediana(vector<int>& pazymiai);
/*
void ivestiStudenta(vector<Studentas>& studentai, char pasirinkimas);
void generuotiPazymius(Studentas& stud, char pasirinkimas);
void generuotiStudentus(vector<Studentas>& studentai, char pasirinkimas);
*/

template <typename konteineris>
void nuskaitytiIsFailo(konteineris &studentai) {
    string failoPavadinimas;
    ifstream failas;

    while (true) {
        try {
            cout << "\nĮveskite failo pavadinimą: ";
            cin >> failoPavadinimas;
            
            failas.open(failoPavadinimas);
            if (!failas) throw runtime_error("Nepavyko atidaryti failo!");
            
            break; 
        }
        catch (const exception& e) {
            cout << e.what() << "Bandykite dar kartą.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    auto start = steady_clock::now();
    
    string eilute;
    getline(failas, eilute); 
    while (getline(failas, eilute)) {
        istringstream line(eilute);
        Studentas stud;
        line >> stud.vardas >> stud.pavarde;
        
        int rezultatas;
        while (line >> rezultatas) {
            stud.namuDarbai.push_back(rezultatas);
        }
        
        stud.egzaminas = stud.namuDarbai.back(); 
        stud.namuDarbai.pop_back(); 

        double vidurkis = skaiciuotiVidurki(stud.namuDarbai);
        stud.galutinisVid = 0.4 * vidurkis + 0.6 * stud.egzaminas;

        double mediana = skaiciuotiMediana(stud.namuDarbai);
        stud.galutinisMed = 0.4 * mediana + 0.6 * stud.egzaminas;

        studentai.push_back(stud); 
    }
    failas.close();

    auto end = steady_clock::now();

    cout << "Duomenų nuskaitymas užtruko: " << duration_cast<seconds>(end - start).count() << " s" << endl;
}

template <typename konteineris>
void rusiuotiStudentus(konteineris &studentai){
    int rusiavimoPasirinkimas;

    while (true) {
        try {
            cout << "Pasirinkite rikiavimo būdą:\n";
            cout << "1 - Pagal vardą (A-Z)\n";
            cout << "2 - Pagal pavardę (A-Z)\n";
            cout << "3 - Pagal galutinį vidurkį (didėjančiai)\n";
            cout << "4 - Pagal galutinę medianą (didėjančiai)\n";
            cout << "Jūsų pasirinkimas: ";
            cin >> rusiavimoPasirinkimas;

            if (cin.fail()) {
                throw invalid_argument("Neteisinga įvestis! Įveskite tik skaičių.");
            }
            if (rusiavimoPasirinkimas < 1 || rusiavimoPasirinkimas > 4) {
                throw out_of_range("Pasirinkimas turi būti nuo 1 iki 4.");
            }
            break;
        }
        catch (const exception &e) {
            cout << e.what() << " Bandykite dar kartą.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    auto start1 = steady_clock::now();

    switch (rusiavimoPasirinkimas) {
        case 1:
            if constexpr (std::is_same<konteineris, std::list<Studentas>>::value) {
                studentai.sort([](const Studentas& a, const Studentas& b) {
                    return a.vardas < b.vardas;
                });
            } else {
                std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                    return a.vardas < b.vardas;
                });
            }
            break;
        case 2:
            if constexpr (std::is_same<konteineris, std::list<Studentas>>::value) {
                studentai.sort([](const Studentas& a, const Studentas& b) {
                    return a.pavarde < b.pavarde;
                });
            } else {
                std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                    return a.pavarde < b.pavarde;
                });
            }
            break;
        case 3:
            if constexpr (std::is_same<konteineris, std::list<Studentas>>::value) {
                studentai.sort([](const Studentas& a, const Studentas& b) {
                    return a.galutinisVid < b.galutinisVid;
                });
            } else {
                std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                    return a.galutinisVid < b.galutinisVid;
                });
            }
            break;
        case 4:
            if constexpr (std::is_same<konteineris, std::list<Studentas>>::value) {
                studentai.sort([](const Studentas& a, const Studentas& b) {
                    return a.galutinisMed < b.galutinisMed;
                });
            } else {
                std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                    return a.galutinisMed < b.galutinisMed;
                });
            }
            break;
    }
    
    auto end1 = steady_clock::now();
    cout << "Rikiavimas užtruko: " << duration_cast<seconds>(end1 - start1).count() << " s" << endl;
}

/*
void isvestiDuomenis(vector<Studentas>& studentai);
void generuotiFailus(vector<int>& dydziai);
*/

template <typename konteineris>
void grupuotiStudentus(konteineris& studentai, konteineris& kietekai, konteineris& nuskriaustukai){
    char rusiavimoPasirinkimas;

    while (true) {
        try {
            cout << "Pasirinkite pagal ką bus surūšiuoti studentai (V - pagal vidurkį, M - pagal medianą): ";
            cin >> rusiavimoPasirinkimas;

            if (rusiavimoPasirinkimas != 'V' && rusiavimoPasirinkimas != 'v' && rusiavimoPasirinkimas != 'M' && rusiavimoPasirinkimas != 'm') {
                throw invalid_argument("Neteisinga įvestis! Pasirinkite V arba M.");
            }

            break;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << " Bandykite dar kartą.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        }

        auto start = steady_clock::now();

        if (rusiavimoPasirinkimas == 'V' || rusiavimoPasirinkimas == 'v'){
            for (const auto& stud : studentai) {
                if (stud.galutinisVid >= 5) {
                    kietekai.push_back(stud);
                } else {
                    nuskriaustukai.push_back(stud);
                }   
            }
        }
        else{
            for (const auto& stud : studentai) {
                if (stud.galutinisMed >= 5) {
                    kietekai.push_back(stud);
                } else {
                    nuskriaustukai.push_back(stud);
                }
            }
        }
    
    
    auto end = steady_clock::now();
    cout << "Studentų grupavimas užtruko: " << duration_cast<seconds>(end - start).count() << " s" << endl;

}

template <typename konteineris>
void isvestiIDuFailus(konteineris& kietekai, konteineris& nuskriaustukai){
    ofstream outNuskriaustukai("nuskriaustukai.txt"), outKietekai("kietekai.txt");
    if (!outNuskriaustukai || !outKietekai) {
        cerr << "Nepavyko sukurti rezultatų failų!" << endl;
        return;
    }

    outNuskriaustukai << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    outNuskriaustukai << string(70, '-') << endl;
    outKietekai << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    outKietekai << string(70, '-') << endl;

    for (const auto& stud : nuskriaustukai) {
        outNuskriaustukai << left << setw(20) << stud.pavarde << setw(20) << stud.vardas << fixed << setprecision(2) << setw(20) << stud.galutinisVid << setw(20) << stud.galutinisMed << endl;
    }
    for (const auto& stud : kietekai) {        
        outKietekai << left << setw(20) << stud.pavarde << setw(20) << stud.vardas << fixed << setprecision(2) << setw(20) << stud.galutinisVid << setw(20) << stud.galutinisMed << endl;
    }

    cout << "Failai \"nuskriaustukai.txt\" ir \"kietekai.txt\" sukurti!" << endl;
}

/*
void testavimoFunkcija_1(vector<int> dydziai);
void testavimoFunkcija_2(vector<Studentas>& studentai, vector<Studentas>& kietekai, vector<Studentas>& nuskriaustukai);
*/

template <typename konteineris>
void testavimoFunkcija_3(konteineris &studentai, konteineris &kietekai, konteineris &nuskriaustukai){

    nuskaitytiIsFailo(studentai);

    rusiuotiStudentus(studentai);

    grupuotiStudentus(studentai, kietekai, nuskriaustukai);

    isvestiIDuFailus(kietekai, nuskriaustukai);

}

template <typename konteineris>
void strategija_2(konteineris& studentai, konteineris& nuskriaustukai) {
    auto start = steady_clock::now();

    for (auto it = studentai.begin(); it != studentai.end();) {
        if (it->galutinisVid < 5) {
            nuskriaustukai.push_back(*it);
            it = studentai.erase(it); 
        } else {
            ++it;
        }
    }

    auto end = steady_clock::now();
    cout << "2 strategija : " 
         << duration_cast<milliseconds>(end - start).count() << " s" << endl;
}

#endif
