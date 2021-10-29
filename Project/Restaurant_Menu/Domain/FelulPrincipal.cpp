
#include "FelulPrincipal.h"

FelulPrincipal::FelulPrincipal() : Preparat() {
    autohtona = true;
}

FelulPrincipal::~FelulPrincipal() {

}

FelulPrincipal::FelulPrincipal(string Nume, int Pret, string Gust, int Calorii, string Cerere, bool Aut) : Preparat(
        Nume, Pret, Gust, Calorii, Cerere) {
    autohtona = Aut;
}

FelulPrincipal::FelulPrincipal(const FelulPrincipal &FP) : Preparat(FP) {
    autohtona = FP.autohtona;
}

bool FelulPrincipal::getAutohtona() const {
    return autohtona;
}

void FelulPrincipal::setAutohtona(bool autohtona) {
    this->autohtona = autohtona;
}

FelulPrincipal &FelulPrincipal::operator=(const FelulPrincipal &FP) {
    if (&FP != this) {
        Preparat::operator=(FP);
        setAutohtona(FP.autohtona);
    }
    return *this;
}

bool FelulPrincipal::operator==(const FelulPrincipal &FP) {
    return Preparat::operator==(FP) && autohtona == FP.autohtona;
}

string FelulPrincipal::toString() {
    return "FP: " + Preparat::toString() + " " + (autohtona ? "true" : "false");
}
