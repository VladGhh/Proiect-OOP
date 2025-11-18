//
// Created by Vlad on 17.11.2025.
//

#ifndef PROIECT_OOP_OBIECTCELEST_H
#define PROIECT_OOP_OBIECTCELEST_H
#include "EntitateCosmica.h"
#include "Punct.h"
#include <iostream>


class ObiectCelest : public EntitateCosmica {
protected:
    double masa;
    double temperatura;
    Punct pozitie;
    int idSistem;

public:
    ObiectCelest(const string &nume, double masa, double temperatura, const Punct &pozitie, int id_sistem)
        : EntitateCosmica(nume),
          masa(masa),
          temperatura(temperatura),
          pozitie(pozitie),
          idSistem(id_sistem) {
    }

    virtual void afiseazaDetalii() const =0;

    virtual bool esteLocuibil() const =0;

    Punct getPozitie() const {
        return pozitie;
    }

    string getNume() const {
        return nume;
    }

    virtual string getTip() const =0;

    double getTemperatura() const {
        return temperatura;
    }

    double getMasa() const {
        return masa;
    }

    virtual ~ObiectCelest() = default;
};


#endif //PROIECT_OOP_OBIECTCELEST_H
