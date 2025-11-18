//
// Created by Vlad on 18.11.2025.
//

#ifndef PROIECT_OOP_NAVASPATIALA_H
#define PROIECT_OOP_NAVASPATIALA_H
#include "ObiectCelest.h"
#include "Astronaut.h"
#include <limits>
#include <vector>


class NavaSpatiala : public ObiectCelest {
private:
    vector<Astronaut *> echipaj;
    string misiune;

public:
    NavaSpatiala(const string &nume, double masa, double temperatura, const Punct &pozitie, int id_sistem,
                 const string &misiune)
        : ObiectCelest(nume, masa, temperatura, pozitie, id_sistem),
          misiune(misiune) {
    }

    NavaSpatiala(const NavaSpatiala &nava);

    void adaugaAstronaut();

    bool esteLocuibil() const override;

    void afiseazaDetalii() const override;

    string getTip() const {
        return "Nava Spatiala";
    }

    ~NavaSpatiala() {
        for (auto a: echipaj) {
            delete a;
        }
    }
};


#endif //PROIECT_OOP_NAVASPATIALA_H
