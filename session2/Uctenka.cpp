#include "Uctenka.h"

Uctenka::Uctenka() {

}

int Uctenka::getCisloUctenky() const {
    return cisloUctenky;
}

void Uctenka::setCisloUctenky(int newCisloUctenky) {
    cisloUctenky = newCisloUctenky;
}

double Uctenka::getCastka() const {
    return castka;
}

void Uctenka::setCastka(double newCastka) {
castka=newCastka;
}

double Uctenka::getDph() const {
    return dph;
}

void Uctenka::setDph(double newDph) {
dph=newDph;
}

Uctenka::Uctenka(double castka, double dph, int cisloUctenky) {
this->castka = castka;
this->dph=dph;
this->cisloUctenky=cisloUctenky;
}

