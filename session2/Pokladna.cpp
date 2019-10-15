#include <iostream>
#include "Pokladna.h"

int Pokladna::citacId = 1000;

Uctenka& Pokladna::vystavUctenku(double cena, double dph) {
    try {
        if (velikost <= pocetVydanychUctenek)
            throw std::overflow_error("Pokladna je plna");
    }
    catch (int e) { std::cout << "Err " << e << std::endl; }
    auto uctenka = new Uctenka(cena, dph, citacId++);
    poleUctenek[pocetVydanychUctenek++] = *uctenka;
    return *uctenka;
}

Uctenka &Pokladna::dejUctenku(int cisloUctenky) {
    try {
        for (int i = 0; i < pocetVydanychUctenek; ++i) {
            if (poleUctenek[i].getCisloUctenky() == cisloUctenky)
                return poleUctenek[i];
        }
        throw -1;
    }
    catch (int e) { std::cout << "Err " << e << std::endl; }

    throw -1;
}

double Pokladna::dejCastku() const {
    double soucet = 0;
    for (int i = 0; i < pocetVydanychUctenek; ++i) {
        soucet += poleUctenek[i].getCastka();
    }
    return soucet;
}

double Pokladna::dejCastkuVcDph() const {
    double soucet = 0;
    for (int i = 0; i < pocetVydanychUctenek; ++i) {
        soucet += poleUctenek[i].getCastka() * (1+poleUctenek->getDph());
    }
    return soucet;
}

Pokladna::Pokladna(int velikostPole){
    velikost = velikostPole;
    poleUctenek = new Uctenka[velikostPole];
    pocetVydanychUctenek = 0;
}


Pokladna::~Pokladna() = default;
