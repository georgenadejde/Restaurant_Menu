
#include "ValidatorDesert.h"
#include "Desert.h"

ValidatorDesert::ValidatorDesert() {

}

ValidatorDesert::~ValidatorDesert() {

}

void ValidatorDesert::validate(Preparat *p) throw(ValidationException) {
    string errorMessage = "";
    try {
        ValidatorPreparat::validate(p);
    }
    catch (ValidationException& e)
    {
        errorMessage += e.toString();
    }

    Desert* D = (Desert*)p;
    if (D->getGust() != "sarat" && D->getGust() != "dulce")
    {
        errorMessage += "Gustul desertului poate fi doar \"sarat\" sau \"dulce\"! \n";
    }
    if (D->getDePost() != 1 && D->getDePost() != 0)
    {
        errorMessage += "De post poate fi doar 1 sau 0! \n";
    }
    if (errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
