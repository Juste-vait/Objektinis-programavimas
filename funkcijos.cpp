#include "funkcijos.h"
#include <algorithm>

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

double skaiciuotiGalutiniVidurkis(const vector<int>& namuDarbai, int egzaminas) {
    double vidurkis = skaiciuotiVidurki(namuDarbai);
    return 0.4 * vidurkis + 0.6 * static_cast<double>(egzaminas);
}

double skaiciuotiGalutiniMediana(vector<int>& namuDarbai, int egzaminas) {
    double mediana = skaiciuotiMediana(namuDarbai);
    return 0.4 * mediana + 0.6 * static_cast<double>(egzaminas);
}
