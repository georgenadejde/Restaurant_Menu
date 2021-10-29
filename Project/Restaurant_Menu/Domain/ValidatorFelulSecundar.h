
#ifndef PROIECTLAB13_14_VALIDATORFELULSECUNDAR_H
#define PROIECTLAB13_14_VALIDATORFELULSECUNDAR_H


#include "Preparat.h"
#include "ValidatorPreparat.h"

class ValidatorFelulSecundar: public ValidatorPreparat{
public:
    ValidatorFelulSecundar();
    ~ValidatorFelulSecundar();
    void validate(Preparat* p) throw(ValidationException);
};


#endif //PROIECTLAB13_14_VALIDATORFELULSECUNDAR_H
