//
// Created by Vlad on 17.11.2025.
//

#ifndef PROIECT_OOP_ENTITATECOSMICA_H
#define PROIECT_OOP_ENTITATECOSMICA_H
#include <string>
using namespace std;

class EntitateCosmica {
protected:
    int id;
    string nume;

private:
    static int idGenerator;

public:
    EntitateCosmica(string nume="Entitate nedenumita"):nume(nume) {
        id = idGenerator;
        idGenerator++;
    }

    int getId() const {
        return id;
    }

    virtual void afiseazaDetalii() const =0;

    virtual ~EntitateCosmica() = default;
};


#endif //PROIECT_OOP_ENTITATECOSMICA_H
