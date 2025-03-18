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

using studentaiVariant = variant<vector<Studentas>, list<Studentas>, deque<Studentas>>;
void pasirinktiKonteineri(studentaiVariant &studentai, char pasirinkimasK);
double skaiciuotiVidurki(const vector<int>& pazymiai);
double skaiciuotiMediana(vector<int>& pazymiai);
void ivestiStudenta(vector<Studentas>& studentai, char pasirinkimas);
void generuotiPazymius(Studentas& stud, char pasirinkimas);
void generuotiStudentus(vector<Studentas>& studentai, char pasirinkimas);
void nuskaitytiIsFailo(studentaiVariant &studentai);
void rusiuotiStudentus(studentaiVariant &studentai);
void isvestiDuomenis(vector<Studentas>& studentai);
void generuotiFailus(vector<int>& dydziai);
void grupuotiStudentus(studentaiVariant &studentai, studentaiVariant& kietekai, studentaiVariant& nuskriaustukai);
void isvestiIDuFailus(vector<Studentas>& kietekai, vector<Studentas>& nuskriaustukai);
void testavimoFunkcija_1(vector<int> dydziai);
void testavimoFunkcija_2(vector<Studentas>& studentai, vector<Studentas>& kietekai, vector<Studentas>& nuskriaustukai);
void testavimoFunkcija_3(studentaiVariant &studentai, studentaiVariant &kietekai, studentaiVariant &nuskriaustukai);

#endif
