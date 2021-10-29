
#include "Service.h"
#include "../Domain/FelulPrincipal.h"
#include "../Domain/FelulSecundar.h"
#include "../Domain/Desert.h"


#include <cstring>
#include <algorithm>

Service::Service() {

}

Service::~Service() {

}

Service::Service(Repository *Repo) {
    repo = Repo;
}

vector<Preparat *> Service::getAll() {
    return repo->getAll();
}

void Service::addFP(string Nume, int Pret, string Gust, int Calorii, string Cerere, bool Aut) {
    FelulPrincipal *FP = new FelulPrincipal(Nume, Pret, Gust, Calorii, Cerere, Aut);
    repo->add(FP);
}

void Service::addFS(string Nume, int Pret, string Gust, int Calorii, string Cerere, int timp) {
    FelulSecundar *FS = new FelulSecundar(Nume, Pret, Gust, Calorii, Cerere, timp);
    repo->add(FS);
}

void Service::addD(string Nume, int Pret, string Gust, int Calorii, string Cerere, bool dePost) {
    Desert *D = new Desert(Nume, Pret, Gust, Calorii, Cerere, dePost);
    repo->add(D);
}

void Service::updatePreparat(string Nume, int pret, string Cerere) {
    vector<Preparat *> all = repo->getAll();

    for (int i = 0; i < all.size(); i++)
        if (all[i]->getNume() == Nume) {
            if (pret != 0)
                all[i]->setPret(pret);
            if (Cerere != "")
                all[i]->setCerere(Cerere);
        }
}

void Service::deletePreparat(string Nume) {
    auto all = repo->getAll();

    for (int i = 0; i < all.size(); i++)
        if (all[i]->getNume() == Nume) {
            repo->remove(all[i]);
            return;
        }
}

vector<Preparat *> Service::listareFP(int calorii, char c) {

    auto all = getAll();
    vector<Preparat *> rez;

    for (int i = 0; i < all.size(); i++) {
        if (FelulPrincipal *FP = dynamic_cast<FelulPrincipal *>(all[i]))
            if (FP->getAutohtona()) {
                if (c == '<' && all[i]->getCalorii() < calorii)
                    rez.push_back(all[i]);
                else if (c == '>' && all[i]->getCalorii() > calorii)
                    rez.push_back(all[i]);
                else if (all[i]->getCalorii() == calorii)
                    rez.push_back(all[i]);

            }
    }
    return rez;
}

vector<Preparat *> Service::listareD() {
    auto all = getAll();
    vector<Preparat *> rez;

    for (int i = 0; i < all.size(); i++) {
        if (Desert *D = dynamic_cast<Desert *>(all[i]))
            if (D->getDePost() && D->getGust() == "dulce") {
                rez.push_back(all[i]);
            }
    }
    return rez;
}

bool cmp(Preparat *FS1, Preparat *FS2) {
    return FS1->getPret() > FS2->getPret();;
}

vector<Preparat *> Service::sortare(int timp,  char c) {
    auto all = getAll();
    vector<Preparat *> rez;

    for (int i = 0; i < all.size(); i++) {
        if (FelulSecundar *FS = dynamic_cast<FelulSecundar *>(all[i]))
            if (FS->getCerere() == "ridicata") {
                if (c == '<' && FS->getTimpAsteptare() < timp)
                    rez.push_back(all[i]);
                else if (c == '>' && FS->getTimpAsteptare() > timp)
                    rez.push_back(all[i]);
                else if (FS->getTimpAsteptare() == timp)
                    rez.push_back(all[i]);

            }
    }

    sort(rez.begin(),rez.end(),cmp);
    return rez;
}

void Service::filtrare(string gust) {
    auto all = getAll();
    vector<Preparat *> rez;
    for (int i = 0; i < all.size(); i++) {
        if (all[i]->getGust() != gust)
            rez.push_back(all[i]);
    }

    for(int i=0;i<rez.size();i++)
    {
        deletePreparat(rez[i]->getNume());
    }
}


