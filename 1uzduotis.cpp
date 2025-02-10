#include <iostream>
#include <vector>

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

        cout << "Iveskite 5 namu darbu pazymius: ";
        studentai[i].namuDarbai.resize(5); 
        for (int j = 0; j < 5; j++) {
            cin >> studentai[i].namuDarbai[j];
        }

        cout << "Iveskite egzamino rezultata: ";
        cin >> studentai[i].egzaminas;
    }

    return 0;
}
