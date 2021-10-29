
#include "ValidatorFelulSecundar.h"
#include "FelulSecundar.h"

ValidatorFelulSecundar::ValidatorFelulSecundar() {

}

ValidatorFelulSecundar::~ValidatorFelulSecundar() {

}

void ValidatorFelulSecundar::validate(Preparat *p) throw(ValidationException) {
    string errorMessage = "";
    try {
        ValidatorPreparat::validate(p);
    }
    catch (ValidationException &e) {
        errorMessage += e.toString();
    }

    FelulSecundar *FS = (FelulSecundar *) p;
    if (FS->getGust() != "sarat" && FS->getGust() != "iute" && FS->getGust() != "dulce") {
        errorMessage += "Gustul felului secundar poate fi doar \"sarat\", \"dulce\" sau \"iute\"! \n";
    }
    if (FS->getTimpAsteptare() <= 0) {
        errorMessage += "Timpul de asteptare trebuie sa fie strict pozitiv! \n";
    }

    if (errorMessage.length() > 0) {
        throw ValidationException(errorMessage);
    }
}
