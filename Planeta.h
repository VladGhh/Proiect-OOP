//
// Created by Vlad on 18.11.2025.
//

#ifndef PROIECT_OOP_PLANETA_H
#define PROIECT_OOP_PLANETA_H
#include "ObiectCelest.h"
using namespace std;

class Planeta : public ObiectCelest {
private:
    string tipSuprafata;
    int nivelOxigen;

public:
    Planeta(const string &nume, double masa, double temperatura, const Punct &pozitie, int id_sistem,
            const string &tip_suprafata, int nivel_oxigen)
        : ObiectCelest(nume, masa, temperatura, pozitie, id_sistem),
          tipSuprafata(tip_suprafata),
          nivelOxigen(nivel_oxigen) {
    }

    string getTip() const {
        return "Planeta";
    }

    bool esteLocuibil() const override;

    void afiseazaDetalii() const override;

    ~Planeta() {
    }
};


#endif //PROIECT_OOP_PLANETA_H
