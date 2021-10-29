
#ifndef PROIECTLAB13_14_VALIDATORPREPARAT_H
#define PROIECTLAB13_14_VALIDATORPREPARAT_H


#include "Preparat.h"
#include "../ValidationException.h"

class ValidatorPreparat {
public:
    ValidatorPreparat();
    ~ValidatorPreparat();
    void validate(Preparat* p) throw(ValidationException);
};


#endif //PROIECTLAB13_14_VALIDATORPREPARAT_H
