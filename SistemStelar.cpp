//
// Created by Vlad on 18.11.2025.
//
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

#include "SistemStelar.h"

void SistemStelar::afiseazaDetalii() const {
    for (auto ob: obiecte){
        cout << endl;
        ob->afiseazaDetalii();
        cout << endl;
    }
}

void SistemStelar::cautaSiAfiseazaDetalii(int id_cautat) const {
    cout << "Cautare ID: " << id_cautat << "..." << endl;

    for (auto const& obiect : obiecte) {
        if (obiect->getId() == id_cautat) {
            cout << "\n--- ENTITATE GASITA ---" << endl;
            // Aici se folosește polimorfismul!
            obiect->afiseazaDetalii();
            cout << "-----------------------" << endl;
            return; // Obiectul a fost gasit, oprim cautarea
        }
    }

    // Daca bucla s-a terminat si nu am gasit nimic
    cout << "Eroare: Nu s-a gasit nicio entitate cu ID-ul " << id_cautat << " in sistem." << endl;
}

void SistemStelar::adaugaObiect() {
    using namespace std;

    int tip;

    cout << "\n--- ADĂUGARE OBIECT COSMIC ÎN SISTEMUL " << nume << " (ID: " << id << ") ---" << endl;
    cout << "Alege tipul de obiect:" << endl;
    cout << " (1) Stea" << endl;
    cout << " (2) Cometă" << endl;
    cout << " (3) Planetă" << endl;
    cout << " (4) Navă Spațială" << endl;
    cout << "Opțiune: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Variabile comune
    string numeObiect;
    double masa, temperatura, x, y, z;
    int id_sistem = this->id;

    // --- INPUT COMUN ---
    cout << "Nume: ";
    getline(cin, numeObiect);

    cout << "Masa (kg): ";
    if (!(cin >> masa)) return;
    cout << "Temperatura (C): ";
    if (!(cin >> temperatura)) return;

    // Coordonate
    cout << "--- Coordonate (X, Y, Z) ---" << endl;
    cout << "X: ";
    if (!(cin >> x)) return;
    cout << "Y: ";
    if (!(cin >> y)) return;
    cout << "Z: ";
    if (!(cin >> z)) return;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Punct pozitie(x, y, z);
    ObiectCelest* nouObiect = nullptr;

    switch (tip) {
        case 1: { // Stea (Necesar: clasaSpectrala)
            string clasaSpectrala;
            cout << "Clasa spectrală (O, B, A, F, G, K, M): ";
            getline(cin, clasaSpectrala);

            nouObiect = new Stea(numeObiect, masa, temperatura, pozitie, id_sistem, clasaSpectrala);
            break;
        }
        case 2: { // Cometă (Necesar: periodaOrbitala)
            int perioada;
            cout << "Perioada orbitală (ani): ";
            if (!(cin >> perioada)) break;

            nouObiect = new Cometa(numeObiect, masa, temperatura, pozitie, id_sistem, perioada);
            break;
        }
        case 3: { // Planetă (Necesar: tipSuprafata, nivelOxigen)
            string tipSuprafata;
            int nivelOxigen;

            cout << "Tipul suprafeței (ex: Roca,Nisip,Gaz): ";
            getline(cin, tipSuprafata);

            cout << "Nivel Oxigen (procent, 1-100): ";
            if (!(cin >> nivelOxigen)) break;

            nouObiect = new Planeta(numeObiect, masa, temperatura, pozitie, id_sistem, tipSuprafata, nivelOxigen);
            break;
        }
        case 4: { // Navă Spațială (Necesar: misiune)
            string misiune;
            cout << "Misiunea navei: ";
            getline(cin, misiune);
            nouObiect = new NavaSpatiala(numeObiect, masa, temperatura, pozitie, id_sistem, misiune);
            break;
        }
        default:
            cout << "\n[EROARE] Alegere invalidă. Obiectul nu a fost adăugat." << endl;
            break;
    }

    // --- ADAUGAREA FINALĂ ---
    if (nouObiect) {
        obiecte.push_back(nouObiect);
        cout << "\n[SUCCESS] Obiectul " << nouObiect->getId() << " a fost adăugat în sistem." << endl;
    } else {
        // Dacă eșecul a venit dintr-un input numeric invalid
        if (tip > 0 && tip <= 4) {
             cout << "\n[EROARE] Eșec la citirea unei valori numerice sau string. Anulare." << endl;
        }
    }
}