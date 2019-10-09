#ifndef SESSION2_UCTENKA_H
#define SESSION2_UCTENKA_H

class Uctenka{
public:
    Uctenka();

    int getCisloUctenky() const;

    void setCisloUctenky(int cisloUctenky);

    double getCastka() const;

    void setCastka(double castka);

    double getDph() const;

    void setDph(double dph);

private:
    int cisloUctenky;
    double castka;
    double dph;
public:
    Uctenka(double castka, double dph, int cisloUctenky);
};



#endif //SESSION2_UCTENKA_H
