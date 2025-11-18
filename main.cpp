#include <iostream>
#include <limits>
#include <windows.h>
#include <string>
#include <vector>
#include "SistemStelar.h"
#include "HartaVizualizator.h"
#include "Stea.h"
#include "Planeta.h"
#include "Cometa.h"
#include "NavaSpatiala.h"
#include "Punct.h"

using namespace std;

int main() {
    // 1. Initializare Sistem Stelar
    SistemStelar sistem_test("Sistemul Cygnus X-1");
    int sistem_id = sistem_test.getId();

    // 2. Initializare Harta Vizualizator
    HartaVizualizator vizualizator;

    // --- Definirea Entităților pentru Test (Alocare dinamică) ---
    // FOLOSIM COORDONATE MICI PENTRU VIZUALIZARE

    // A. Stea (Centru)
    Punct p_stea(0.0, 0.0, 0.0);
    Stea* stea = new Stea("Cygnus A*", 3.0e31, 10000.0, p_stea, sistem_id, "O");
    int stea_id = stea->getId(); // Salvam ID-ul pentru cautare

    // B. Planetă Locuibilă
    Punct p_planeta(-3.0, 1.0, 0.0); // COORDONATE MICI
    Planeta* planeta = new Planeta("Planeta Pandora",
                                     8.0e24, 25.0, p_planeta, sistem_id,
                                     "Roca", 25);

    // C. Cometă
    Punct p_cometa(5.0, -4.0, 0.0); // COORDONATE MICI
    Cometa* cometa = new Cometa("Cometa Halley",
                                  1.0e15, -150.0, p_cometa, sistem_id, 76);

    // D. Navă Spațială
    Punct p_nava(1.0, 2.0, 0.0); // COORDONATE MICI
    NavaSpatiala* nava = new NavaSpatiala("Nava Enterprise",
                                           9.0e9, 20.0, p_nava, sistem_id,
                                           "Misiune de explorare");

    // --- 3. Adaugare in Sistem (Folosind metoda publică de test) ---
    sistem_test.adaugaObiectPentruTest(stea);
    sistem_test.adaugaObiectPentruTest(planeta);
    sistem_test.adaugaObiectPentruTest(cometa);
    sistem_test.adaugaObiectPentruTest(nava);

    cout << "\n\n========================================================" << endl;
    cout << "           RULARE TESTE AUTOMATE - PROIECT POO            " << endl;
    cout << "========================================================" << endl;


    // TEST 1: Vizualizare Harta (Acum va afișa grila ASCII)
    cout << "\n--- TEST 1: HARTA SISTEMULUI ---" << endl;
    vizualizator.deseneazaSistem(&sistem_test);

    // TEST 2: Detalii Complete (Testează polimorfismul)
    cout << "\n\n=== TEST 2: DETALII COMPLETE (afiseazaDetalii) ===" << endl;
    sistem_test.afiseazaDetalii();

    // TEST 3: Cautare dupa ID (Testează căutarea)
    cout << "\n\n=== TEST 3: CĂUTARE ENTITATE (Exemplu: Steaua ID " << stea_id << ") ===" << endl;
    sistem_test.cautaSiAfiseazaDetalii(stea_id);

    // TEST 4: Cautare nereusita
    cout << "\n\n=== TEST 4: CĂUTARE NEREUȘITĂ (ID 9999) ===" << endl;
    sistem_test.cautaSiAfiseazaDetalii(9999);

    cout << "\n\n=== TESTE INCHEIATE. ===" << endl;

    return 0;
}