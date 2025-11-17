//
// Created by Vlad on 17.11.2025.
//

#ifndef PROIECT_OOP_ENTITATECOSMICA_H
#define PROIECT_OOP_ENTITATECOSMICA_H


class EntitateCosmica {
private:
    int id;
    static int idGenerator;

public:
    EntitateCosmica() {
        id = idGenerator;
        idGenerator++;
    }

    virtual ~EntitateCosmica() = default;

    int getId() const {
        return id;
    }

 //   virtual void AfiseazaDetalii() =0;
};


#endif //PROIECT_OOP_ENTITATECOSMICA_H
