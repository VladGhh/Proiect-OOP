//
// Created by Vlad on 18.11.2025.
//

#ifndef PROIECT_OOP_ASTRONAUT_H
#define PROIECT_OOP_ASTRONAUT_H
#include <iostream>
using namespace std;

class Astronaut {
private:
    string nume;
    string sex;
    string etnie;
    int anNastere;
    string pasiune;

public:
    Astronaut(const string &nume, const string &sex, const string &etnie, int an_nastere, const string &pasiune)
        : nume(nume),
          sex(sex),
          etnie(etnie),
          anNastere(an_nastere),
          pasiune(pasiune) {
    }

    void afiseazaInformatii() const;
};


#endif //PROIECT_OOP_ASTRONAUT_H
