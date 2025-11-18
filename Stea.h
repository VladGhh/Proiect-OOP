//
// Created by Vlad on 17.11.2025.
//

#ifndef PROIECT_OOP_STEA_H
#define PROIECT_OOP_STEA_H
#include "ObiectCelest.h"
#include "Punct.h"
using namespace std;

class Stea : public ObiectCelest {
private:
    string clasaSpectrala;
    string constelatie = "Necunoscuta";

public:
    Stea(const string &nume, double masa, double temperatura, const Punct &pozitie, int id_sistem,
         const string &clasa_spectrala)
        : ObiectCelest(nume, masa, temperatura, pozitie, id_sistem),
          clasaSpectrala(clasa_spectrala) {
    }

    void setConstelatie(string con) {
        constelatie = con;
    }

    string getTip() const {
        return "Stea";
    }

    int calculeazaDurataViata() const;

    bool esteLocuibil() const override;

    void afiseazaDetalii() const override;
};


#endif //PROIECT_OOP_STEA_H
