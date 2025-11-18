//
// Created by Vlad on 18.11.2025.
//

#include "NavaSpatiala.h"

NavaSpatiala::NavaSpatiala(const NavaSpatiala &nava) : ObiectCelest(nava.nume, nava.masa, nava.temperatura,
                                                                    nava.pozitie, nava.idSistem),
                                                       misiune(nava.misiune) {
    echipaj.reserve(nava.echipaj.size());
    for (auto a: nava.echipaj) {
        echipaj.push_back(new Astronaut(*a));
    }
}

bool NavaSpatiala::esteLocuibil() const {
    return true;
}

void NavaSpatiala::afiseazaDetalii() const {
    cout << "ID Entitate: " << id << endl;
    cout << "ID sistem: " << idSistem << endl;
    cout << "Nume: " << nume << endl;
    cout << "Natura: Nava Spatiala  " << endl;
    cout << "Misiune: " << misiune << endl;
    cout << "Temperatura: " << temperatura << endl;
    cout << "Masa: " << masa << endl;
    cout << "Echipaj:" << endl;
    for (auto a: echipaj) {
        cout << "---------------------------------" << endl;
        a->afiseazaInformatii();
    }
    cout << "---------------------------------" << endl;
}

void NavaSpatiala::adaugaAstronaut() {
    string numeA, sex, pasiuni, etnie;
    int anNastere;
    cout << endl << "Nume: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, numeA);
    cout << endl << "Sex: ";
    getline(cin, sex);
    cout << endl << "Etnie: ";
    getline(cin, etnie);
    cout << endl << "An nastere: ";
    cin >> anNastere;
    cout << endl << "Are o pasiune pentru: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, pasiuni);
    cout << endl << nume << " a fost adaugat in echipaj!" << endl;
    Astronaut *a = new Astronaut(numeA, sex, etnie, anNastere, pasiuni);
    echipaj.push_back(a);
}
