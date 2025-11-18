// HartaVizualizator.cpp
#include "HartaVizualizator.h"
#include "SistemStelar.h" // Necesar pentru a accesa membrii friend
#include "ObiectCelest.h" // Pentru a accesa metodele obiectelor
#include <cmath>
#include <algorithm> // Pentru min/max
#include <tuple>
#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- FUNCTIE AUXILIARA DE SCALARE ---
// Returnează {minX, maxX, minY, maxY}
tuple<double, double, double, double> getLimiteleHarta(const vector<ObiectCelest*>& obiecte) {
    if (obiecte.empty()) return {0.0, 0.0, 0.0, 0.0};

    double minX = obiecte[0]->getPozitie().getX();
    double maxX = minX;
    double minY = obiecte[0]->getPozitie().getY();
    double maxY = minY;

    for (const auto& ob : obiecte) {
        Punct p = ob->getPozitie();
        minX = min(minX, p.getX());
        maxX = max(maxX, p.getX());
        minY = min(minY, p.getY());
        maxY = max(maxY, p.getY());
    }

    double rangeX = maxX - minX;
    double rangeY = maxY - minY;
    // Asigurăm o marjă minimă de 5.0 dacă range-ul e mic/zero
    double marginX = (rangeX == 0) ? 5.0 : rangeX * 0.2;
    double marginY = (rangeY == 0) ? 5.0 : rangeY * 0.2;

    // Adăugăm marja
    return {minX - marginX, maxX + marginX, minY - marginY, maxY + marginY};
}


// --- IMPLEMENTAREA PRINCIPALA (HARTA ASCII) ---
void HartaVizualizator::deseneazaSistem(const SistemStelar* sistem) const {

    if (sistem == nullptr) {
        cout << "Eroare: Sistemul este null." << endl;
        return;
    }

    // Acces direct (datorită 'friend')
    const auto& obiecte = sistem->obiecte;
    const int sistem_id = sistem->id;
    const string sistem_nume = sistem->nume;

    if (obiecte.empty()) {
        cout << "\n[INFO] Sistemul stelar " << sistem_nume << " este gol. Nu se poate desena harta." << endl;
        return;
    }

    cout << "\n==================================================================================" << endl;
    // Am scos diacriticele pentru a preveni erorile de afișare
    cout << "  HARTA VIZUALA (PROIECTIE 2D) - SISTEMUL: " << sistem_nume << " (ID: " << sistem_id << ")" << endl;
    cout << "==================================================================================" << endl;

    // 1. Calculul limitelor
    auto [minX, maxX, minY, maxY] = getLimiteleHarta(obiecte);

    // Dimensiunea hărții în caractere
    const int W = 80; // Lățimea
    const int H = 20; // Înălțimea

    double rangeX = maxX - minX;
    double rangeY = maxY - minY;

    if (rangeX == 0) rangeX = 1.0;
    if (rangeY == 0) rangeY = 1.0;

    vector<string> harta(H, string(W, ' ')); // Fundal gol (spațiu)

    map<char, vector<string>> legenda;

    map<string, char> simboluri = {
        {"STEAUA",         '*'},
        {"NAVA SPATIALA",  'N'},
        {"PLANETA",        'P'},
        {"COMETA",         'C'}
    };

    auto getTypeString = [](const ObiectCelest* obj) -> string {
        if (dynamic_cast<const Stea*>(obj)) return "STEAUA";
        if (dynamic_cast<const Planeta*>(obj)) return "PLANETA";
        if (dynamic_cast<const Cometa*>(obj)) return "COMETA";
        if (dynamic_cast<const NavaSpatiala*>(obj)) return "NAVA SPATIALA";
        return "Obiect Necunoscut";
    };

    // 2. Proiectarea obiectelor pe hartă (X-Y)
    for (const auto& ob : obiecte) {
        Punct p = ob->getPozitie();

        double normX = (p.getX() - minX) / rangeX;
        double normY = (p.getY() - minY) / rangeY;

        int drawX = (int)round(normX * (W - 1));
        int drawY = (int)round((1.0 - normY) * (H - 1));

        if (drawX >= 0 && drawX < W && drawY >= 0 && drawY < H) {
            string tip = getTypeString(ob);
            char simbol = simboluri.count(tip) ? simboluri.at(tip) : 'O';
            harta[drawY][drawX] = simbol;
            legenda[simbol].push_back(ob->getNume() + " (ID: " + to_string(ob->getId()) + ")");
        }
    }

    // 3. Afișarea Hărții (CU CADRU ASCII STANDARD)
    cout << "+" << string(W, '-') << "+" << endl; // CORECTAT

    for (int y = 0; y < H; ++y) {
        cout << "|"; // CORECTAT
        cout << harta[y];
        cout << "|" << endl; // CORECTAT
    }

    cout << "+" << string(W, '-') << "+" << endl; // CORECTAT

    // 4. Afișarea Legendei
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "  LEGENDA HARTII (ID-uri si Simboluri):" << endl; // CORECTAT (fără diacritice)
    cout << "----------------------------------------------------------------------------------" << endl;
    for (const auto& pair : legenda) {
        cout << "  Simbol: [" << pair.first << "]" << endl;
        for (const auto& nume : pair.second) {
            cout << "    -> " << nume << endl;
        }
    }
    cout << "==================================================================================" << endl;
}