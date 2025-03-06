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
void ivestiStudenta(vector<Studentas>& studentai, char pasirinkimas);
void generuotiPazymius(Studentas& stud, char pasirinkimas);
void generuotiStudentus(vector<Studentas>& studentai, char pasirinkimas);
void nuskaitytiIsFailo(vector<Studentas>& studentai);
void rusiuotiStudentus(vector<Studentas>& studentai);
void isvestiDuomenis(vector<Studentas>& studentai);
void generuotiFailus(vector<int> dydziai);
void grupuotiStudentus(vector<Studentas>& studentai, vector<Studentas>& kietekai, vector<Studentas>& nuskriaustukai);
void isvestiIDuFailus(vector<Studentas>& kietekai, vector<Studentas>& nuskriaustukai);
void testavimoFunkcija_1(vector<int> dydziai);
void testavimoFunkcija_2(vector<Studentas>& studentai, vector<Studentas>& kietekai, vector<Studentas>& nuskriaustukai);

#endif
