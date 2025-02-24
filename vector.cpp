//kompiliuot: g++ -std=c++11 -o main vector.cpp

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



using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

double skaiciuotiVidurki(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    int suma = 0;
    for (int paz : pazymiai) suma += paz;
    return static_cast<double>(suma) / pazymiai.size();
}

double skaiciuotiMediana(vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    sort(pazymiai.begin(), pazymiai.end());
    size_t n = pazymiai.size();
    if (n % 2 == 0) {
        return (pazymiai[n / 2 - 1] + pazymiai[n / 2]) / 2.0;
    } else {
        return pazymiai[n / 2];
    }
}

void ivestiStudenta(vector<Studentas>& studentai, char pasirinkimas) {
    Studentas stud;
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
            if (!(cin >> rezultatas)) {
            cout << "Klaida! Įveskite tik skaičius.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
            }
        if (rezultatas == -1) break;
        stud.namuDarbai.push_back(rezultatas);
        }
        
        cout << "Įveskite egzamino rezultatą: ";
        while (!(cin >> stud.egzaminas)) {
        cout << "Klaida! Įveskite tik skaičius.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        double vidurkis = skaiciuotiVidurki(stud.namuDarbai);
        stud.galutinis = 0.4 * vidurkis + 0.6 * stud.egzaminas;
        } else {
        double mediana = skaiciuotiMediana(stud.namuDarbai);
        stud.galutinis = 0.4 * mediana + 0.6 * stud.egzaminas;
        }
    studentai.push_back(stud);
    }
    
}

void generuotiPazymius(Studentas& stud, char pasirinkimas) {
    
    int kiekis = rand() % 5 + 3;  

    
    for (int i = 0; i < kiekis; ++i) {
        stud.namuDarbai.push_back(rand() % 10 + 1);  
    }

    stud.egzaminas = rand() % 10 + 1; 
    
    if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        double vidurkis = skaiciuotiVidurki(stud.namuDarbai);
        stud.galutinis = 0.4 * vidurkis + 0.6 * stud.egzaminas;
    } else {
        double mediana = skaiciuotiMediana(stud.namuDarbai);
        stud.galutinis = 0.4 * mediana + 0.6 * stud.egzaminas;
    }

    
}

void generuotiStudentus(vector<Studentas>& studentai, char pasirinkimas) {
    vector<string> vardai = {"Jonas", "Petras", "Antanas", "Nojus", "Lukas"};
    vector<string> pavardes = {"Kazlauskas", "Petraitis", "Jonaitis", "Biliūnas", "Lukauskis"};

    while (true) {
        cout << "Ar norite pridėti studentą? (T/N): ";
        char tesiame;
        cin >> tesiame;
        if (tesiame == 'N' || tesiame == 'n') break;

        Studentas stud;
        stud.vardas = vardai[rand() % vardai.size()];
        stud.pavarde = pavardes[rand() % pavardes.size()];
        generuotiPazymius(stud, pasirinkimas);

        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
            double vidurkis = skaiciuotiVidurki(stud.namuDarbai);
            stud.galutinis = 0.4 * vidurkis + 0.6 * stud.egzaminas;
        } else {
            double mediana = skaiciuotiMediana(stud.namuDarbai);
            stud.galutinis = 0.4 * mediana + 0.6 * stud.egzaminas;
        }

        studentai.push_back(stud);
    }
}

void nuskaitytiIsFailo(vector<Studentas>& studentai, char pasirinkimas) {
    string failoPavadinimas;
    cout << "\nĮveskite failo pavadinimą: ";
    cin >> failoPavadinimas;

    ifstream failas(failoPavadinimas);
    if (!failas) {
        cout << "Nepavyko atidaryti failo!" << endl;
        return;
    }
    
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

        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
            double vidurkis = skaiciuotiVidurki(stud.namuDarbai);
            stud.galutinis = 0.4 * vidurkis + 0.6 * stud.egzaminas;
        } else {
            double mediana = skaiciuotiMediana(stud.namuDarbai);
            stud.galutinis = 0.4 * mediana + 0.6 * stud.egzaminas;
        }
        
        studentai.push_back(stud);
    }
    failas.close();

}

int main() {
    srand(time(0));  
    vector<Studentas> studentai;
    char pasirinkimas;
    int pasirinkimasMeniu;

    while (true) {
        cout << "Pasirinkite galutinio balo skaičiavimą (V - vidurkis, M - mediana): ";
        cin >> pasirinkimas;

        if (pasirinkimas == 'V' || pasirinkimas == 'v' || pasirinkimas == 'M' || pasirinkimas == 'm') {
            break; 
        } else {
            cout << "Neteisinga įvestis! Pasirinkite V arba M.\n";
        }
    }
    
    while (true) {
        cout << "\nPasirinkite veiksmą:\n";
        cout << "1 - Rankiniu būdu įvesti duomenis\n";
        cout << "2 - Generuoti pažymius\n";
        cout << "3 - Generuoti ir pažymius, ir vardus/pavardes\n";
        cout << "4 - Baigti darbą\n";
        cout << "Jūsų pasirinkimas: ";
        cin >> pasirinkimasMeniu;

        if (pasirinkimasMeniu == 4) {
            break;
        } else if (pasirinkimasMeniu == 1) {
            ivestiStudenta(studentai, pasirinkimas);
        } else if (pasirinkimasMeniu == 2) {
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
                generuotiPazymius(stud, pasirinkimas);
                studentai.push_back(stud);
            }
        } else if (pasirinkimasMeniu == 3) {
            generuotiStudentus(studentai, pasirinkimas);
        } else if (pasirinkimasMeniu == 5) {
            nuskaitytiIsFailo(studentai, pasirinkimas);
        } else {
            cout << "Neteisingas pasirinkimas! Bandykite dar kartą.\n";
        }
    }

    cout << "\n---------------------------------------------------\n";
    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (";
    if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        cout << "Vid.)";
    } else {
        cout << "Med.)";
    }
    cout << endl;
    cout << "---------------------------------------------------\n";

    for (const auto& stud : studentai) {
        cout << left << setw(15) << stud.pavarde << setw(15) << stud.vardas
             << fixed << setprecision(2) << setw(15) << stud.galutinis << endl;
    }
    git branch
    git branch

    return 0;
}