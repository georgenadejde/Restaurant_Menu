
#ifndef PROIECTLAB13_14_SERVICE_H
#define PROIECTLAB13_14_SERVICE_H


#include "../Repository/Repository.h"
#include "../Domain/Preparat.h"
class Service {
private:
    Repository *repo;
public:
    Service();

    ~Service();

    Service(Repository *Repo);

    vector<Preparat *> getAll();

    void addFP(string Nume, int Pret, string Gust, int Calorii, string Cerere, bool Aut);

    void addFS(string Nume, int Pret, string Gust, int Calorii, string Cerere, int timp);

    void addD(string Nume, int Pret, string Gust, int Calorii, string Cerere, bool dePost);

    void updatePreparat(string Nume, int pret = 0, string Cerere = "");

    void deletePreparat(string Nume);

    vector<Preparat*> listareFP(int calorii, char c);

    vector<Preparat*> listareD();
    
    vector<Preparat*> sortare(int timp, char c);

    void filtrare(string gust);
};

bool cmp(Preparat* p1, Preparat* p2);
#endif //PROIECTLAB13_14_SERVICE_H
