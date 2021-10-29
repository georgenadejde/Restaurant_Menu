#include "Repository.h"
#include "../Domain/FelulPrincipal.h"
#include "../Domain/FelulSecundar.h"
#include "../Domain/Desert.h"

Repository::Repository() {

}

void Repository::add(Preparat *p) throw(RepoException, ValidationException) {
    if (typeid(*p) == typeid(FelulPrincipal)) {
        this->validatorFP.validate(p);
    }
    if (typeid(*p) == typeid(FelulSecundar)) {
        this->validatorFS.validate(p);
    }
    if (typeid(*p) == typeid(Desert)) {
        this->validatorD.validate(p);
    }
    auto all = getAll();
    for (int i = 0; i < all.size(); i++)
        if (all[i]->getNume() == p->getNume())
            throw RepoException("Preparatul nu poate fi adaugat deoarece exista deja!");

    elems.push_back(p);
}

void Repository::remove(Preparat *p) throw(RepoException, ValidationException) {
    for (int i = 0; i < this->elems.size(); i++) {
        if (elems[i] == p) {
            elems.erase(elems.begin() + i);
            return;
        }
    }
    throw RepoException("Preparatul nu poate fi sters deoarece nu exista!");
}

void Repository::update(Preparat *oldP, Preparat *newP) throw(RepoException, ValidationException) {
    if (typeid(*oldP) == typeid(FelulPrincipal)) {
        this->validatorFP.validate(oldP);
    }
    if (typeid(*oldP) == typeid(FelulSecundar)) {
        this->validatorFS.validate(oldP);
    }
    if (typeid(*oldP) == typeid(Desert)) {
        this->validatorD.validate(oldP);
    }
    for (int i = 0; i < this->elems.size(); i++) {
        if (elems[i] == oldP) {
            elems.erase(elems.begin() + i);
            elems.insert(elems.begin() + i, newP);
//            delete elems[i];
//            elems[i] = p;
            return;
        }
    }
    throw RepoException("Preparatul nu poate fi modificat deoarece nu exista!");
}

vector<Preparat *> Repository::getAll() {
    return elems;
}

int Repository::getSize() {
    return elems.size();
}

Preparat *Repository::getFrom(int index) throw(RepoException) {
    if (index < 0 || index >= elems.size()) {
        throw RepoException("Index invalid!\n");
    }
    return elems[index];
}

int Repository::find(Preparat *c) {
    for (int i = 0; i < this->elems.size(); i++) {
        if (elems[i] == c) {
            return i;
        }
    }
    return -1;
}

Repository::~Repository() {
    for (int i = 0; i < elems.size(); i++) {
        if (elems[i] != NULL) {
            delete elems[i];
            elems[i] = NULL;
        }
    }
    elems.clear();
}
