#include <iostream>
#include "Pokladna.h"


int main() {
    std::cout << "TEST" << std::endl;
    auto *pokladna = new Pokladna(5);
    pokladna->vystavUctenku(10000,0.21);
    pokladna->vystavUctenku(1000,0.18);
    pokladna->vystavUctenku(2000,0.1);
    pokladna->vystavUctenku(2000,0.1);
    pokladna->vystavUctenku(2000,0.1);
    auto a = pokladna->dejCastku();
    auto b = pokladna->dejCastkuVcDph();
    auto c = pokladna->dejUctenku(1003);
    return 0;
}