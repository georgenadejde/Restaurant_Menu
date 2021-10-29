
#include "FelulSecundar.h"

int FelulSecundar::getTimpAsteptare() {
    return timpAsteptare;
}

void FelulSecundar::setTimpAsteptare(int timpAsteptare) {
    FelulSecundar::timpAsteptare = timpAsteptare;
}

FelulSecundar::FelulSecundar() : Preparat(){
    timpAsteptare = 0;
}

FelulSecundar::~FelulSecundar() {

}

FelulSecundar::FelulSecundar(string Nume, int Pret, string Gust, int Calorii, string Cerere, int timp): Preparat(Nume,Pret,Gust,Calorii,Cerere) {
    this->timpAsteptare = timp;
}

FelulSecundar::FelulSecundar(const FelulSecundar &FS): Preparat(FS) {
    timpAsteptare = FS.timpAsteptare;
}

FelulSecundar &FelulSecundar::operator=(const FelulSecundar &FS) {
    if(&FS != this)
    {
        Preparat::operator=(FS);
        setTimpAsteptare(FS.timpAsteptare);
    }
    return *this;
}

bool FelulSecundar::operator==(const FelulSecundar &FS) {
    return Preparat::operator==(FS) && timpAsteptare == FS.timpAsteptare;
}

string FelulSecundar::toString() {
    return "FS: " + Preparat::toString() + " " + to_string(timpAsteptare);
}
