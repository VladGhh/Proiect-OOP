//
// Created by Vlad on 18.11.2025.
//

#ifndef PROIECT_OOP_COMETA_H
#define PROIECT_OOP_COMETA_H
#include "ObiectCelest.h"


class Cometa : public ObiectCelest {
private:
    int periodaOrbitala;

public:
    Cometa(const string &nume, double masa, double temperatura, const Punct &pozitie, int id_sistem,
           int perioda_orbitala)
        : ObiectCelest(nume, masa, temperatura, pozitie, id_sistem),
          periodaOrbitala(perioda_orbitala) {
    }

    bool esteLocuibil() const override;

    void afiseazaDetalii() const override;

    string getTip() const {
        return "Cometa";
    }

    ~Cometa() {
    }
};


#endif //PROIECT_OOP_COMETA_H
