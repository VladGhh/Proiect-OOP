//
// Created by Vlad on 17.11.2025.
//

#ifndef PROIECT_OOP_PUNCT_H
#define PROIECT_OOP_PUNCT_H
#include<iostream>

class Punct {
private:
    double x, y, z;

public:
    Punct(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {
    }

    Punct operator+(const Punct &p) const;

    Punct operator-(const Punct &p) const;

    bool operator==(const Punct &p) const;

    Punct operator*(double scalar) const;

    friend std::ostream &operator<<(std::ostream &out, const Punct &p);

    friend Punct operator*(double scalar, const Punct &p);

    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    double getZ() const {
        return z;
    }
};


#endif //PROIECT_OOP_PUNCT_H
