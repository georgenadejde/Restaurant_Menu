
#include "ValidatorPreparat.h"

ValidatorPreparat::ValidatorPreparat() {

}

ValidatorPreparat::~ValidatorPreparat() {

}

void ValidatorPreparat::validate(Preparat *p) throw(ValidationException) {
    string errorMessage = "";

    if (p->getNume().empty())
    {
        errorMessage += "Numele preparatului nu poate fi gol!\n";
    }
    if (p->getPret() <= 0)
    {
        errorMessage += "Pretul preparatului trebuie sa fie strict pozitiv! \n";
    }
    if (p->getCalorii() <= 0)
    {
        errorMessage += "Caloriile preparatului trebuie sa fie un numar strict pozitiv! \n";
    }
    if (p->getCerere() != "scazuta" && p->getCerere() != "medie" && p->getCerere() != "ridicata" )
    {
        errorMessage += "Cererea poate fi doar \"scazuta\", \"medie\" sau \"ridicata\"! \n";
    }
    if (errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
