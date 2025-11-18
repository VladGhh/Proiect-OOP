//
// Created by Vlad on 18.11.2025.
//

#ifndef PROIECT_OOP_SISTEMSTELAR_H
#define PROIECT_OOP_SISTEMSTELAR_H
#include "EntitateCosmica.h"
#include "ObiectCelest.h"
#include "Cometa.h"
#include "NavaSpatiala.h"
#include "Planeta.h"
#include "Stea.h"
#include <vector>

class HartaVizualizator;

class SistemStelar : public EntitateCosmica {
private:
    vector<ObiectCelest *> obiecte;

public:
    SistemStelar(const std::string& nume) : EntitateCosmica(nume) {}

    void afiseazaDetalii() const override;

    void adaugaObiect();

    void adaugaObiectPentruTest(ObiectCelest* obj) {
        if (obj != nullptr) {
            obiecte.push_back(obj);
        }
    }
    void cautaSiAfiseazaDetalii(int id_cautat) const;

    ~SistemStelar() {
        for (auto a: obiecte) {
            delete a;
        }
    }

    friend class HartaVizualizator;
};


#endif //PROIECT_OOP_SISTEMSTELAR_H
