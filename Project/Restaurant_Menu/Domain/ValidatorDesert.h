
#ifndef PROIECTLAB13_14_VALIDATORDESERT_H
#define PROIECTLAB13_14_VALIDATORDESERT_H


#include "ValidatorPreparat.h"

class ValidatorDesert: public ValidatorPreparat {
public:
    ValidatorDesert();
    ~ValidatorDesert();
    void validate(Preparat* p) throw(ValidationException);
};


#endif //PROIECTLAB13_14_VALIDATORDESERT_H
