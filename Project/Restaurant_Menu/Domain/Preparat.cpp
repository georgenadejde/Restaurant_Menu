
#include "Preparat.h"

Preparat::Preparat() {
    nume = "";
    pret = 0;
    gust = "";
    calorii = 0;
    cerere = "";
}

Preparat::Preparat(string Nume, int Pret, string Gust, int Calorii, string Cerere) {
    nume = Nume;
    pret = Pret;
    gust = Gust;
    calorii = Calorii;
    cerere = Cerere;
}

Preparat::Preparat(const Preparat &p) {
    nume = p.nume;
    pret = p.pret;
    gust = p.gust;
    calorii = p.calorii;
    cerere = p.cerere;
}

string Preparat::getNume() {
    return nume;
}

int Preparat::getPret() {
    return pret;
}

string Preparat::getGust() {
    return gust;
}

int Preparat::getCalorii() {
    return calorii;
}

string Preparat::getCerere() {
    return cerere;
}

void Preparat::setNume(string Nume) {
    nume = Nume;
}

void Preparat::setPret(int Pret) {
    pret = Pret;
}

void Preparat::setGust(string Gust) {
    gust = Gust;
}

void Preparat::setCalorii(int Cal) {
    calorii = Cal;
}

void Preparat::setCerere(string Cer) {
    cerere = Cer;
}

string Preparat::toString() {
    return nume + " " + to_string(pret) + " " + gust + " " + to_string(calorii) + " " + cerere;
}

Preparat& Preparat::operator=(const Preparat &p) {
    if(&p != this)
    {
        setNume(p.nume);
        setPret(p.pret);
        setGust(p.gust);
        setCalorii(p.calorii);
        setCerere(p.cerere);
    }
    return *this;
}

bool Preparat::operator==(const Preparat &p) {
   // return nume == p.nume && pret == p.pret;
    return nume == p.nume ;
}

Preparat::~Preparat() {

}
