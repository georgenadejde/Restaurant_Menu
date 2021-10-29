
#ifndef PROIECTLAB13_14_VALIDATORFELULPRINCIPAL_H
#define PROIECTLAB13_14_VALIDATORFELULPRINCIPAL_H


#include "ValidatorPreparat.h"

class ValidatorFelulPrincipal: public ValidatorPreparat {
public:
    ValidatorFelulPrincipal();
    ~ValidatorFelulPrincipal();
    void validate(Preparat* p) throw(ValidationException);
};


#endif //PROIECTLAB13_14_VALIDATORFELULPRINCIPAL_H
