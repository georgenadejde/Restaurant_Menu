
#ifndef PROIECTLAB13_14_PREPARAT_H
#define PROIECTLAB13_14_PREPARAT_H
#include <string>

using namespace std;

class Preparat {
protected:
    string nume;
    int pret;
    string gust;
    int calorii;
    string cerere;
public:
    Preparat();

    Preparat(string, int, string, int, string);

    Preparat(const Preparat &p);

    string getNume();

    int getPret();

    string getGust();

    int getCalorii();

    string getCerere();

    void setNume(string);

    void setPret(int);

    void setGust(string);

    void setCalorii(int);

    void setCerere(string);

    virtual string toString();

    Preparat& operator=(const Preparat &p);

    bool operator==(const Preparat &p);
//
//    virtual bool getAutohtona();
//
//    virtual bool getDePost();
//
//    virtual int getTimpAsteptare();

    virtual ~Preparat();
};


#endif //PROIECTLAB13_14_PREPARAT_H
