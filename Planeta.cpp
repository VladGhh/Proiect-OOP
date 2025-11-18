//
// Created by Vlad on 18.11.2025.
//

#include "Planeta.h"

bool Planeta::esteLocuibil() const {
    bool masaValida = (masa > 1.8e24) && (masa < 6.0e25);
    bool temperaturaValida = (temperatura > 0.0) && (temperatura < 100.0);
    bool oxigen = (nivelOxigen > 10) && (nivelOxigen < 70);
    bool suprafata = tipSuprafata != "Gaz";
    return masaValida && temperaturaValida && oxigen && suprafata;
}

void Planeta::afiseazaDetalii() const {
    cout << "ID Entitate: " << id << endl;
    cout << "ID sistem: " << idSistem << endl;
    cout << "Nume: " << nume << endl;
    cout << "Natura: planeta cu suprafata  " << tipSuprafata << endl;
    cout << "Nivel oxigen (procent): " << nivelOxigen << endl;
    cout << "Temperatura: " << temperatura << endl;
    cout << "Masa: " << masa << endl;
}
