#include <iostream>
#include "Punct.h"
#include "ObiectCelest.h"

int main() {
   ObiectCelest A ;
    A.afis();



    Punct a(1, 2, 3);
    Punct b(4, 5, 6);

    Punct c = a + b;
    Punct d = b - a;

     std::cout << "a + b = " << c << std::endl;
     std::cout << "b - a = " << d << std::endl;

     if(a == b) {
         std::cout << "a si b sunt egale" << std::endl;
     } else {
         std::cout << "a si b sunt diferite" << std::endl;
     }


    return 0;
}
