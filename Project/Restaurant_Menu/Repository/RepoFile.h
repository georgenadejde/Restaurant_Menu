
#ifndef LAB10_REPOFILE_H
#define LAB10_REPOFILE_H


#include "Repository.h"

class RepoFile: public Repository {
private:
    char* inFile;
    char* outFile;
    void saveToFile();
    void loadFromFile();

public:
    RepoFile();

    RepoFile(const char* infile,const char* outfile);

    ~RepoFile();

    void add(Preparat *p);

    void remove(Preparat *p);

    void update(Preparat *p1, Preparat *p2);

    bool isEmpty(ifstream &pFile);

};


#endif //LAB10_REPOFILE_H
