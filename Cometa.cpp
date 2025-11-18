//
// Created by Vlad on 18.11.2025.
//

#include "Cometa.h"

bool Cometa::esteLocuibil() const {
    return false;
}

void Cometa::afiseazaDetalii() const {
    cout << "ID Entitate: " << id << endl;
    cout << "ID sistem: " << idSistem << endl;
    cout << "Nume: " << nume << endl;
    cout << "Natura: cometa cu perioada orbitala " << periodaOrbitala <<" ani"<< endl;
    cout << "Temperatura: " << temperatura << endl;
    cout << "Masa: " << masa << endl;
}