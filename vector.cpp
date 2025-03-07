//kompiliuot: g++ -std=c++11 -o main vector.cpp

#include "funkcijos.h"

int main() {
    srand(time(0));  
    vector<Studentas> studentai;
    char pasirinkimas;
    int pasirinkimasMeniu;
    bool duomenysIsvesti = false;
    vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};
    vector<Studentas> kietekai, nuskriaustukai;
    
    while (true) {
        try {
        cout << "\nPasirinkite veiksmą:\n";
        cout << "1 - Rankiniu būdu įvesti duomenis\n";
        cout << "2 - Generuoti pažymius\n";
        cout << "3 - Generuoti ir pažymius, ir vardus/pavardes\n";
        cout << "4 - Baigti darbą\n";
        cout << "5 - Nuskaityti duomenis iš failo\n";
        cout << "6 - Generuoti failus\n";
        cout << "7 - Sugrupuoti į galvočius ir nuskriaustukus\n";
        cout << "8 - testavimo funkcija 1\n";
        cout << "9 - testavimo funkcija 2\n";
        cout << "Jūsų pasirinkimas: ";
        cin >> pasirinkimasMeniu;
        
        if (cin.fail()) throw invalid_argument("Neteisinga įvestis! Įveskite tik skaičių.");
        if (pasirinkimasMeniu < 1 || pasirinkimasMeniu > 9) throw out_of_range("Klaida: Skaičius turi būti tarp 1-9.");

        if (pasirinkimasMeniu == 4) {
            break;
        } else if (pasirinkimasMeniu == 1) {
            while (true) {
                cout << "Pasirinkite galutinio balo skaičiavimą (V - vidurkis, M - mediana): ";
                cin >> pasirinkimas;
        
                if (pasirinkimas == 'V' || pasirinkimas == 'v' || pasirinkimas == 'M' || pasirinkimas == 'm') {
                    break; 
                } else {
                    cout << "Neteisinga įvestis! Pasirinkite V arba M.\n";
                }
            }
            ivestiStudenta(studentai, pasirinkimas);
        } else if (pasirinkimasMeniu == 2) {
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
                cout << "Ar norite pridėti studentą? (T/N): ";
                char tesiame;
                cin >> tesiame;

                if (tesiame == 'T' || tesiame == 't') {
                    
                    Studentas stud;
                    cout << "\nĮveskite studento vardą: ";
                    cin >> stud.vardas;
                    cout << "Įveskite studento pavardę: ";
                    cin >> stud.pavarde;
                    generuotiPazymius(stud, pasirinkimas);
                    studentai.push_back(stud);
                } 
                else if (tesiame == 'N' || tesiame == 'n') {
                    break;
                } 
                else {
                    cout << "Neteisinga įvestis! Pasirinkite T arba N.\n";
                }
            }
        } else if (pasirinkimasMeniu == 3) {
            while (true) {
                cout << "Pasirinkite galutinio balo skaičiavimą (V - vidurkis, M - mediana): ";
                cin >> pasirinkimas;
        
                if (pasirinkimas == 'V' || pasirinkimas == 'v' || pasirinkimas == 'M' || pasirinkimas == 'm') {
                    break; 
                } else {
                    cout << "Neteisinga įvestis! Pasirinkite V arba M.\n";
                }
            }
            generuotiStudentus(studentai, pasirinkimas);
        } else if (pasirinkimasMeniu == 5) {
            nuskaitytiIsFailo(studentai);
            rusiuotiStudentus(studentai);
            isvestiDuomenis(studentai);
            duomenysIsvesti = true;
            break;
        } else if (pasirinkimasMeniu == 6) {
            generuotiFailus(dydziai);
        } else if (pasirinkimasMeniu == 7) {
            nuskaitytiIsFailo(studentai);
            grupuotiStudentus(studentai, kietekai, nuskriaustukai);
            isvestiIDuFailus(kietekai, nuskriaustukai);
        } else if (pasirinkimasMeniu == 8) {
            testavimoFunkcija_1(dydziai);
        } else if (pasirinkimasMeniu == 9) {
            testavimoFunkcija_2(studentai, kietekai, nuskriaustukai);
            duomenysIsvesti = true;
            break;
        } else {
            cout << "Neteisingas pasirinkimas! Bandykite dar kartą.\n";
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    catch (const exception& e) {
        cout << e.what() << "\nBandykite dar kartą.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    }

    if (!duomenysIsvesti) {
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
        cout << left << setw(15) << stud.pavarde << setw(15) << stud.vardas << fixed << setprecision(2) << setw(15) << stud.galutinis << endl;
        }
    }

    return 0;
}