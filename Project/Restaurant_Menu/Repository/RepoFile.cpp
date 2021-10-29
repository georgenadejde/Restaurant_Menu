
#include "RepoFile.h"
#include "../ReadFromFileException.h"
#include "../Domain/FelulPrincipal.h"
#include "../Domain/FelulSecundar.h"
#include "../Domain/Desert.h"
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

RepoFile::RepoFile() : Repository() {
    inFile = nullptr;
    outFile = nullptr;
}

RepoFile::RepoFile(const char *infile, const char *outfile) : Repository() {
    this->inFile = new char[strlen(infile)];
    strcpy(this->inFile, infile);

    this->outFile = new char[strlen(outfile)];
    strcpy(this->outFile, outfile);

    loadFromFile();
}

bool RepoFile::isEmpty(std::ifstream &pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void RepoFile::loadFromFile() {
    ifstream file(inFile);
    if (isEmpty(file))
        return;
    if (file.is_open()) {
        string linie;
        string delim = " ";

        try {
            while (getline(file, linie)) {
                if (linie.substr(0, 2) == "FP") {
                    linie = linie.erase(0, 3);

                    int pos = linie.find(delim);
                    string nume = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int pret = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    string gust = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int calorii = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    string cerere = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int autInt = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);

                    bool aut = (autInt == 1);

                    FelulPrincipal *FP = new FelulPrincipal(nume, pret, gust, calorii, cerere, aut);
                    this->validatorFP.validate(FP);
                    add(FP);
                } else if (linie.substr(0, 2) == "FS") {
                    linie = linie.erase(0, 3);

                    int pos = linie.find(delim);
                    string nume = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int pret = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    string gust = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int calorii = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    string cerere = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int timp = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);


                    FelulSecundar *FS = new FelulSecundar(nume, pret, gust, calorii, cerere, timp);
                    this->validatorFS.validate(FS);
                    add(FS);
                } else if (linie.substr(0, 2) == "DE") {
                    linie = linie.erase(0, 3);

                    int pos = linie.find(delim);
                    string nume = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int pret = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    string gust = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int calorii = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    string cerere = linie.substr(0, pos);
                    linie = linie.erase(0, pos + 1);

                    pos = linie.find(delim);
                    int dePostInt = stoi(linie.substr(0, pos));
                    linie = linie.erase(0, pos + 1);

                    bool dePost = (dePostInt == 1);

                    Desert *DE = new Desert(nume, pret, gust, calorii, cerere, dePost);
                    this->validatorD.validate(DE);
                    add(DE);
                }
            }
        }
        catch (...) {
            throw ReadFromFileException("Formatul datelor din fisier este invalid!");
        }
        file.close();
    } else {
        throw ReadFromFileException("Fisierul nu exista!");
    }
}

void RepoFile::add(Preparat *p) {
    Repository::add(p);
    saveToFile();
}

void RepoFile::remove(Preparat *p) {
    Repository::remove(p);
    saveToFile();
}

void RepoFile::update(Preparat *p1, Preparat *p2) {
    Repository::update(p1, p2);
    saveToFile();
}

RepoFile::~RepoFile() {
//    if(inFile)
//        delete[] inFile;
//    if(outFile)
//        delete[] outFile;
};

void RepoFile::saveToFile() {
    ofstream o(outFile);
    for (int i = 0; i < getSize(); i++)
        o << elems[i]->toString() << '\n';
    // cout<<'\n';
    o.close();
}
