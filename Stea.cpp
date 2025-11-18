//
// Created by Vlad on 17.11.2025.
//

#include "Stea.h"
#include "Stea.h"
#include "Stea.h"


int Stea::calculeazaDurataViata() const {
    if (clasaSpectrala == "O") {
        return 10;
    } else if (clasaSpectrala == "B") {
        return 100;
    } else if (clasaSpectrala == "A") {
        return 1000;
    } else if (clasaSpectrala == "F") {
        return 5000;
    } else if (clasaSpectrala == "G") {
        return 10000;
    } else if (clasaSpectrala == "K") {
        return 50000;
    } else if (clasaSpectrala == "M") {
        return 200000;
    } else {
        return 30000;
    }
}

void Stea::afiseazaDetalii() const {
    cout << "ID Entitate: " << id << endl;
    cout << "ID sistem: " << idSistem << endl;
    cout << "Nume: " << nume << endl;
    cout << "Natura: stea de clasa spectrala " << clasaSpectrala << endl;
    cout << "Constelatia: " << constelatie << endl;
    int durata = calculeazaDurataViata();
    cout << "Durata estimativa de viata: " << durata << " milioane de ani" << endl;
    cout << "Temperatura: " << temperatura << endl;
    cout << "Masa: " << masa << endl;
}

bool Stea::esteLocuibil() const {
    return false;
}
