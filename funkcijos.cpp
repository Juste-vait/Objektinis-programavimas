#include "funkcijos.h"

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
            try {
                cout << "Įveskite pažymį: ";
                cin >> rezultatas;

                if (cin.fail()) throw invalid_argument("Neteisinga įvestis! Įveskite tik skaičių.");
                if (rezultatas < -1 || rezultatas > 10) throw out_of_range("Klaida: Skaičius turi būti tarp 1-10.");

                if (rezultatas == -1) break;
                stud.namuDarbai.push_back(rezultatas);
            }
            catch (const exception& e) {
                cout << e.what() << " Bandykite dar kartą.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
    while (true){
            try{
                cout << "Įveskite egzamino rezultatą: ";
                cin >> stud.egzaminas;

                if (cin.fail ()) throw invalid_argument("Neteisinga įvestis! Įveskite tik skaičių.");
                if (stud.egzaminas < 1 || stud.egzaminas > 10) throw out_of_range("Klaida: Skaičius turi būti tarp 1-10.");

                break;
            }
            catch (const exception& e) {
                cout << e.what() << " Bandykite dar kartą.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }


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

void nuskaitytiIsFailo(vector<Studentas>& studentai) {
    string failoPavadinimas;
    ifstream failas;

    while (true) {
        try {
            cout << "\nĮveskite failo pavadinimą: ";
            cin >> failoPavadinimas;
            
            failas.open(failoPavadinimas);
            if (!failas) throw runtime_error("Nepavyko atidaryti failo! Bandykite dar kartą.");
            
            break; 
        }
        catch (const exception& e) {
            cout << e.what() << endl;
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
    cout << "Duomenų nuskaitymas užtruko: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
}

void isvestiDuomenis(vector<Studentas>& studentai) {
    int rusiavimoPasirinkimas;
    cout << "Pasirinkite rikiavimo būdą:\n";
    cout << "1 - Pagal vardą (A-Z)\n";
    cout << "2 - Pagal pavardę (A-Z)\n";
    cout << "3 - Pagal galutinį vidurkį (mažėjančiai)\n";
    cout << "4 - Pagal galutinę medianą (mažėjančiai)\n";
    cout << "Jūsų pasirinkimas: ";
    cin >> rusiavimoPasirinkimas;

    auto start1 = steady_clock::now();

    if (cin.fail() || (rusiavimoPasirinkimas < 1 || rusiavimoPasirinkimas > 4)) {
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Neteisinga įvestis! Duomenys nebus rūšiuojami.\n";
    } else {
    switch (rusiavimoPasirinkimas) {
        case 1:
            sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                return a.vardas < b.vardas;
            });
            break;
        case 2:
            sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                return a.pavarde < b.pavarde;
            });
            break;
        case 3:
            sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                return a.galutinisVid > b.galutinisVid;
            });
            break;
        case 4:
            sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                return a.galutinisMed > b.galutinisMed;
            });
            break;
    }
    }

    auto end1 = steady_clock::now();
    cout << "Rūšiavimas užtruko: " << duration_cast<milliseconds>(end1 - start1).count() << " ms" << endl;


    string pasirinkimasIsvesti;
    cout << "Ar norite išvesti duomenis į failą ar į ekraną? (F/E): ";
    cin >> pasirinkimasIsvesti;
    
    ostream* out;
    ofstream outFile;
    
    if (pasirinkimasIsvesti == "F" || pasirinkimasIsvesti == "f") {
        string failoPavadinimas;
        cout << "Įveskite failo pavadinimą: ";
        cin >> failoPavadinimas;
        outFile.open(failoPavadinimas);
        
        if (!outFile) {
            cout << "Nepavyko atidaryti failo!" << endl;
            return;
        }
        out = &outFile;
    } else {
        out = &cout;
    }

    auto start2 = steady_clock::now();

    *out << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    *out << string(70, '-') << endl;
    
    for (auto& stud : studentai) {
        double vidurkis = skaiciuotiVidurki(stud.namuDarbai);
        double mediana = skaiciuotiMediana(stud.namuDarbai);
        double galutinisVid = 0.4 * vidurkis + 0.6 * stud.egzaminas;
        double galutinisMed = 0.4 * mediana + 0.6 * stud.egzaminas;

        *out << left << setw(15) << stud.pavarde << setw(15) << stud.vardas << fixed << setprecision(2) << setw(20) << galutinisVid << setw(20) << galutinisMed << endl;
    }

    if (outFile.is_open()) {
        outFile.close();
        cout << "Duomenys sėkmingai išsaugoti į failą!" << endl;
    }

    auto end2 = steady_clock::now();  
    cout << "Duomenų išvedimas užtruko: " << duration_cast<milliseconds>(end2 - start2).count() << " ms" << endl;
}
