//
// Created by Vlad on 17.11.2025.
//

#include<iostream>
#include "Punct.h"

#include <iostream>

Punct Punct::operator*(double scalar) const {
    return Punct(x * scalar, y * scalar, z * scalar);
}

Punct Punct::operator+(const Punct &p) const {
    return Punct(x + p.x, y + p.y, z + p.z);
}

Punct Punct::operator-(const Punct &p) const {
    return Punct(x - p.x, y - p.y, z - p.z);
}

Punct operator*(double scalar, const Punct &p) {
    return Punct(p.x * scalar, p.y * scalar, p.z * scalar);
}

std::ostream &operator<<(std::ostream &out, const Punct &p) {
    out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
}

bool Punct::operator==(const Punct &p) const{
    return ((x == p.x) && (y == p.y) && (z == p.z));
}
