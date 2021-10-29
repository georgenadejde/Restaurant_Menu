
#ifndef PROIECTLAB13_14_DESERT_H
#define PROIECTLAB13_14_DESERT_H


#include "Preparat.h"

class Desert : public Preparat {
private:
    bool dePost;
public:
    Desert();

    ~Desert();

    Desert(string Nume, int Pret, string Gust, int Calorii, string Cerere, bool dePost);

    Desert(const Desert &D);

    Desert &operator=(const Desert &D);

    bool operator==(const Desert &D);

    string toString();

    bool getDePost() const;

    void setDePost(bool dePost);
};


#endif //PROIECTLAB13_14_DESERT_H
