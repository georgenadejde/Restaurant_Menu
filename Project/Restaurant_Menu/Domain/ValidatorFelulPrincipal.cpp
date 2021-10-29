
#include "ValidatorFelulPrincipal.h"
#include "FelulPrincipal.h"

ValidatorFelulPrincipal::ValidatorFelulPrincipal() {

}

ValidatorFelulPrincipal::~ValidatorFelulPrincipal() {

}

void ValidatorFelulPrincipal::validate(Preparat *p) throw(ValidationException) {
    string errorMessage = "";
    try {
        ValidatorPreparat::validate(p);
    }
    catch (ValidationException& e)
    {
        errorMessage += e.toString();
    }

    FelulPrincipal* FP = (FelulPrincipal*)p;
    if (!(FP->getGust() == "sarat" || FP->getGust() == "iute"))
    {
        errorMessage += "Gustul felului principal poate fi doar \"sarat\" sau \"iute\"! \n";
    }
    if (FP->getAutohtona() != 1 && FP->getAutohtona() != 0)
    {
        errorMessage += "Autohtona poate fi doar 1 sau 0! \n";
    }

    if (errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
