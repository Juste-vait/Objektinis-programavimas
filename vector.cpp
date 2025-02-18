#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <string>
#include "funkcijos.h"

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};


int main() {
    vector<Studentas> studentai;
    char pasirinkimas;

    cout << "Pasirinkite galutinio balo skaiciavima (V - vidurkis, M - mediana): ";
    cin >> pasirinkimas;

    while (true) {
        cout << "Ar norite pridėti studentą? (T/N): ";
        char tesiame;
        cin >> tesiame;
        if (tesiame == 'N' || tesiame == 'n') break;

        Studentas stud;
        cout << "\nĮveskite studento vardą: ";
        cin >> stud.vardas;
        cout << "Įveskite studento pavardę: ";
        cin >> stud.pavarde;

        cout << "Įveskite namų darbų rezultatus (baigti -1):\n";
        while (true) {
            int rezultatas;
            cin >> rezultatas;
            if (rezultatas == -1) break;
            stud.namuDarbai.push_back(rezultatas);
        }

        cout << "Įveskite egzamino rezultatą: ";
        cin >> stud.egzaminas;

        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
            double vidurkis = skaiciuotiVidurki(stud.namuDarbai);
            stud.galutinis = 0.4 * vidurkis + 0.6 * stud.egzaminas;
        } else {
            double mediana = skaiciuotiMediana(stud.namuDarbai);
            stud.galutinis = 0.4 * mediana + 0.6 * stud.egzaminas;
        }

        studentai.push_back(stud);
    }

    cout << "\n--------------------------------------------\n";
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(15) << "Galutinis" << endl;
    cout << "--------------------------------------------\n";
    for (const auto& stud : studentai) {
        cout << left << setw(15) << stud.pavarde << setw(15) << stud.vardas
             << fixed << setprecision(2) << setw(15) << stud.galutinis << endl;
    }

    return 0;
}
