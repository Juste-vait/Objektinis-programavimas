include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct Studentas {
    string vardas, pavarde;
    vector<int> namuDarbai;
    int egzaminas;
};


int main() {
    int n;
    cout << "Iveskite studentu skaiciu: ";
    cin >> n;

    vector<Studentas> studentai(n);

    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
        cin >> studentai[i].pavarde;
        cout << "Iveskite " << i + 1 << "-ojo studento varda: ";
        cin >> studentai[i].vardas;

        // Iveskite tiksliai 5 namų darbų pažymius
        cout << "Iveskite 5 namu darbu pazymius desimtbaleje sistemoje: ";
        studentai[i].namuDarbai.clear();

        int pazymys;
        while (studentai[i].namuDarbai.size() < 5) {
            if (cin >> pazymys) {
                studentai[i].namuDarbai.push_back(pazymys);
            } else {
                cout << "Neteisinga ivestis! Iveskite skaiciu: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // Jei vartotojas įvedė per daug skaičių, ignoruojame juos
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Egzamino rezultato įvedimas
        cout << "Iveskite egzamino rezultata desimtbaleje sistemoje: ";
        while (!(cin >> studentai[i].egzaminas)) {
            cout << "Neteisinga ivestis! Iveskite skaiciu: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        // Jei vartotojas įvedė per daug skaičių, ignoruojame juos
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    return 0;
}
