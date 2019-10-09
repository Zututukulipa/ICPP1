#ifndef SESSION2_POKLADNA_H
#define SESSION2_POKLADNA_H


#include "Uctenka.h"

class Pokladna {
    Uctenka *poleUctenek;
    int pocetVydanychUctenek;
    int velikost;
    static int citacId;
public:
    Pokladna(int velikostPole);

    Uctenka &vystavUctenku(double, double);

    Uctenka &dejUctenku(int);

    double dejCastku() const;

    double dejCastkuVcDph() const;
};



#endif //SESSION2_POKLADNA_H
