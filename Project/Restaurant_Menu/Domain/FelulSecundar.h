
#ifndef PROIECTLAB13_14_FELULSECUNDAR_H
#define PROIECTLAB13_14_FELULSECUNDAR_H


#include "Preparat.h"

class FelulSecundar : public Preparat {
private:
    int timpAsteptare;
public:
    FelulSecundar();

    ~FelulSecundar();

    FelulSecundar(string Nume, int Pret, string Gust, int Calorii, string Cerere, int timp);

    FelulSecundar(const FelulSecundar &FS);

    FelulSecundar &operator=(const FelulSecundar &FS);

    bool operator==(const FelulSecundar &FS);

    string toString();

    int getTimpAsteptare();

    void setTimpAsteptare(int timpAsteptare);

};


#endif //PROIECTLAB13_14_FELULSECUNDAR_H
