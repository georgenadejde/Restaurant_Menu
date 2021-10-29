
#ifndef PROIECTLAB13_14_FELULPRINCIPAL_H
#define PROIECTLAB13_14_FELULPRINCIPAL_H


#include "Preparat.h"

class FelulPrincipal : public Preparat {
private:
    bool autohtona;

public:
    FelulPrincipal();

    ~FelulPrincipal();

    FelulPrincipal(string Nume, int Pret, string Gust, int Calorii, string Cerere, bool Aut);

    FelulPrincipal(const FelulPrincipal &FP);

    bool getAutohtona() const;

    void setAutohtona(bool autohtona);

    FelulPrincipal& operator=(const FelulPrincipal& FP);
    bool operator==(const FelulPrincipal& FP);

    string toString();

};


#endif //PROIECTLAB13_14_FELULPRINCIPAL_H
