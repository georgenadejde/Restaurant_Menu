
#ifndef LAB9_REPOSITORY_H
#define LAB9_REPOSITORY_H


#include <vector>
#include "../Domain/Preparat.h"
#include "../Domain/ValidatorFelulPrincipal.h"
#include "../Domain/ValidatorFelulSecundar.h"
#include "../Domain/ValidatorDesert.h"
#include "../RepoException.h"

class Repository {
protected:
    vector<Preparat *> elems;
    ValidatorFelulPrincipal validatorFP;
    ValidatorFelulSecundar validatorFS;
    ValidatorDesert validatorD;

public:
    Repository();

//    Repository(const Repository &);

//    Repository &operator=(const Repository &repository);

     void add(Preparat *p) throw(RepoException, ValidationException);

     void remove(Preparat *p)throw(RepoException, ValidationException);

     void update(Preparat *oldP,Preparat *newP)throw(RepoException, ValidationException);

    vector<Preparat*> getAll();

    int getSize();

    Preparat* getFrom(int index)throw(RepoException); //throw(RepoException);

    int find(Preparat *c);


    ~Repository();
};


#endif //LAB9_REPOSITORY_H
