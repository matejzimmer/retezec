#include <iostream>
#include "retezec.h"

int main() {
    retezec r1;
    retezec r2("Ahoj");
    retezec r4(" Vole");
    retezec r3(r2);
    retezec r5;
    std::cout << "Objekty vytvoreny vychozim konstruktorem";
    std::cout << "s0:"<< r1 << std::endl;
    std::cout << "Objekty vytvoreny konstruktorem s parametrem";
    std::cout << "s1:"<< r2 << std::endl;
    std::cout << "s4:"<< r4 << std::endl;
    std::cout << "Objekty vytvoreny kopirovacim konstruktorem";
    std::cout << "s2:"<< r3 << std::endl;
    std::cout << "Prirazeni s1 = s2" << std::endl;
    r3 = r2;
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;
    std::cout << "Secteni (s3 = s1 + s4)\n";
    r5 = r3 +r2;
    std::cout << r5 << std::endl;
    r2 += r4;
    std::cout << r2 << std::endl;




    return 0;
}
