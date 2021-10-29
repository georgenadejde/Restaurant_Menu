
#include "Desert.h"

Desert::Desert(): Preparat() {
    dePost = true;
}

Desert::~Desert() {

}

Desert::Desert(string Nume, int Pret, string Gust, int Calorii, string Cerere, bool dePost):Preparat(Nume,Pret,Gust,Calorii,Cerere) {
    this->dePost = dePost;
}

Desert::Desert(const Desert &D): Preparat(D) {
    this->dePost = D.dePost;
}

Desert &Desert::operator=(const Desert &D) {
    if(&D != this)
    {
        Preparat::operator=(D);
        setDePost(D.dePost);
    }
    return*this;
}

bool Desert::operator==(const Desert &D) {
    return Preparat::operator==(D) && dePost == D.dePost;
}

string Desert::toString() {
    return "D: " + Preparat::toString() + " " + (dePost ? "true" : "false");
}

bool Desert::getDePost() const {
    return dePost;
}

void Desert::setDePost(bool dePost) {
    Desert::dePost = dePost;
}
