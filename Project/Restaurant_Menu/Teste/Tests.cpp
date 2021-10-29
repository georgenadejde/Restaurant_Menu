
#include <cassert>
#include <iostream>
#include <vector>
#include <fstream>
#include "Tests.h"
#include "../Domain/Preparat.h"
#include "../Domain/FelulPrincipal.h"
#include "../Domain/Desert.h"
#include "../Domain/FelulSecundar.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
#include "../Repository/RepoFile.h"
#include "../Domain/ValidatorFelulPrincipal.h"
#include "../Domain/ValidatorFelulSecundar.h"
#include "../Domain/ValidatorDesert.h"

void Tests::runAllTests() {
    domainTests();
    serviceTests();
    repoFileTests();
    repoTests();
    validatorDTests();
    validatorFPTests();
    validatorFSTests();
}

void Tests::domainTests() {
    PreparatTests();
    FPTests();
    FSTests();
    DTests();
}

void Tests::PreparatTests() {
    Preparat p;
    assert(p.getNume().empty());
    assert(p.getPret() == 0);
    assert(p.getGust().empty());
    assert(p.getCalorii() == 0);
    assert(p.getCerere().empty());

    Preparat p1("supa", 10, "sarat", 100, "ridicata");

    assert(p1.getNume() == "supa");
    assert(p1.getPret() == 10);
    assert(p1.getGust() == "sarat");
    assert(p1.getCalorii() == 100);
    assert(p1.getCerere() == "ridicata");

    Preparat p2(p1);

    assert(p1.getNume() == p2.getNume());
    assert(p1.getPret() == p2.getPret());
    assert(p1.getGust() == p2.getGust());
    assert(p1.getCalorii() == p2.getCalorii());
    assert(p1.getCerere() == p2.getCerere());

    p2.setNume("pireu");
    p2.setPret(20);
    p2.setGust("dulce");
    p2.setCalorii(50);
    p2.setCerere("scazuta");

    assert(p2.getNume() == "pireu");
    assert(p2.getPret() == 20);
    assert(p2.getGust() == "dulce");
    assert(p2.getCalorii() == 50);
    assert(p2.getCerere() == "scazuta");

    p1 = p2;

    assert(p1.getNume() == "pireu");
    assert(p1.getPret() == 20);
    assert(p1.getGust() == "dulce");
    assert(p1.getCalorii() == 50);
    assert(p1.getCerere() == "scazuta");

    p = p2;
    assert(p == p2);
    p.setNume("supa");
    assert(!(p == p2));

    assert(p2.toString() == "pireu 20 dulce 50 scazuta");
}

void Tests::FPTests() {
    FelulPrincipal p;
    assert(p.getNume().empty());
    assert(p.getPret() == 0);
    assert(p.getGust().empty());
    assert(p.getCalorii() == 0);
    assert(p.getCerere().empty());
    assert(p.getAutohtona() == true);

    FelulPrincipal p1("supa", 10, "sarat", 100, "ridicata", true);

    assert(p1.getNume() == "supa");
    assert(p1.getPret() == 10);
    assert(p1.getGust() == "sarat");
    assert(p1.getCalorii() == 100);
    assert(p1.getCerere() == "ridicata");
    assert(p1.getAutohtona() == true);

    FelulPrincipal p2(p1);

    assert(p1.getNume() == p2.getNume());
    assert(p1.getPret() == p2.getPret());
    assert(p1.getGust() == p2.getGust());
    assert(p1.getCalorii() == p2.getCalorii());
    assert(p1.getCerere() == p2.getCerere());
    assert(p1.getAutohtona() == p2.getAutohtona());

    p2.setNume("pireu");
    p2.setPret(20);
    p2.setGust("dulce");
    p2.setCalorii(50);
    p2.setCerere("scazuta");
    p2.setAutohtona(false);

    assert(p2.getNume() == "pireu");
    assert(p2.getPret() == 20);
    assert(p2.getGust() == "dulce");
    assert(p2.getCalorii() == 50);
    assert(p2.getCerere() == "scazuta");
    assert(p2.getAutohtona() == false);

    p1 = p2;

    assert(p1.getNume() == "pireu");
    assert(p1.getPret() == 20);
    assert(p1.getGust() == "dulce");
    assert(p1.getCalorii() == 50);
    assert(p1.getCerere() == "scazuta");
    assert(p1.getAutohtona() == false);

    p = p2;
    assert(p == p2);
    p.setAutohtona(true);
    assert(!(p == p2));
    assert(p2.toString() == "FP: pireu 20 dulce 50 scazuta false");
}

void Tests::FSTests() {
    FelulSecundar p;
    assert(p.getNume().empty());
    assert(p.getPret() == 0);
    assert(p.getGust().empty());
    assert(p.getCalorii() == 0);
    assert(p.getCerere().empty());
    assert(p.getTimpAsteptare() == 0);

    FelulSecundar p1("supa", 10, "sarat", 100, "ridicata", 30);

    assert(p1.getNume() == "supa");
    assert(p1.getPret() == 10);
    assert(p1.getGust() == "sarat");
    assert(p1.getCalorii() == 100);
    assert(p1.getCerere() == "ridicata");
    assert(p1.getTimpAsteptare() == 30);

    FelulSecundar p2(p1);

    assert(p1.getNume() == p2.getNume());
    assert(p1.getPret() == p2.getPret());
    assert(p1.getGust() == p2.getGust());
    assert(p1.getCalorii() == p2.getCalorii());
    assert(p1.getCerere() == p2.getCerere());
    assert(p1.getTimpAsteptare() == p2.getTimpAsteptare());

    p2.setNume("pireu");
    p2.setPret(20);
    p2.setGust("dulce");
    p2.setCalorii(50);
    p2.setCerere("scazuta");
    p2.setTimpAsteptare(50);

    assert(p2.getNume() == "pireu");
    assert(p2.getPret() == 20);
    assert(p2.getGust() == "dulce");
    assert(p2.getCalorii() == 50);
    assert(p2.getCerere() == "scazuta");
    assert(p2.getTimpAsteptare() == 50);

    p1 = p2;

    assert(p1.getNume() == "pireu");
    assert(p1.getPret() == 20);
    assert(p1.getGust() == "dulce");
    assert(p1.getCalorii() == 50);
    assert(p1.getCerere() == "scazuta");
    assert(p1.getTimpAsteptare() == 50);

    p = p2;
    assert(p == p2);
    p.setTimpAsteptare(60);
    assert(!(p == p2));

    assert(p2.toString() == "FS: pireu 20 dulce 50 scazuta 50");
}

void Tests::DTests() {
    Desert p;
    assert(p.getNume().empty());
    assert(p.getPret() == 0);
    assert(p.getGust().empty());
    assert(p.getCalorii() == 0);
    assert(p.getCerere().empty());
    assert(p.getDePost() == true);

    Desert p1("supa", 10, "sarat", 100, "ridicata", true);

    assert(p1.getNume() == "supa");
    assert(p1.getPret() == 10);
    assert(p1.getGust() == "sarat");
    assert(p1.getCalorii() == 100);
    assert(p1.getCerere() == "ridicata");
    assert(p1.getDePost() == true);

    Desert p2(p1);

    assert(p1.getNume() == p2.getNume());
    assert(p1.getPret() == p2.getPret());
    assert(p1.getGust() == p2.getGust());
    assert(p1.getCalorii() == p2.getCalorii());
    assert(p1.getCerere() == p2.getCerere());
    assert(p1.getDePost() == p2.getDePost());

    p2.setNume("pireu");
    p2.setPret(20);
    p2.setGust("dulce");
    p2.setCalorii(50);
    p2.setCerere("scazuta");
    p2.setDePost(false);

    assert(p2.getNume() == "pireu");
    assert(p2.getPret() == 20);
    assert(p2.getGust() == "dulce");
    assert(p2.getCalorii() == 50);
    assert(p2.getCerere() == "scazuta");
    assert(p2.getDePost() == false);

    p1 = p2;

    assert(p1.getNume() == "pireu");
    assert(p1.getPret() == 20);
    assert(p1.getGust() == "dulce");
    assert(p1.getCalorii() == 50);
    assert(p1.getCerere() == "scazuta");
    assert(p1.getDePost() == false);

    p = p2;
    assert(p == p2);
    p.setDePost(true);
    assert(!(p == p2));

    assert(p2.toString() == "D: pireu 20 dulce 50 scazuta false");
}

void Tests::serviceTests() {
    listariTests();
    sortTests();
    filterTests();

    Desert *D = new Desert("tort", 90, "dulce", 300, "ridicata", true);
    FelulSecundar *FS = new FelulSecundar("pireu", 30, "sarat", 150, "medie", 30);
    FelulPrincipal *FP = new FelulPrincipal("supa", 15, "sarat", 100, "ridicata", true);


    Repository *repo = new Repository;

    Service s(repo);
    s.addD(D->getNume(), D->getPret(), D->getGust(), D->getCalorii(), D->getCerere(), D->getDePost());
    s.addFP(FP->getNume(), FP->getPret(), FP->getGust(), FP->getCalorii(), FP->getCerere(), FP->getAutohtona());
    s.addFS(FS->getNume(), FS->getPret(), FS->getGust(), FS->getCalorii(), FS->getCerere(), FS->getTimpAsteptare());

    vector<Preparat *> all = s.getAll();

    assert(all.size() == 3);
    assert(*all[0] == *D);
    assert(*all[1] == *FP);
    assert(*all[2] == *FS);

    FelulSecundar *FS2 = new FelulSecundar("friptura", 40, "sarat", 350, "medie", 50);
    s.addFS(FS2->getNume(), FS2->getPret(), FS2->getGust(), FS2->getCalorii(), FS2->getCerere(),
            FS2->getTimpAsteptare());


    vector<Preparat *> all1 = s.getAll();

    assert(all1.size() == 4);
    assert(*all1[0] == *D);
    assert(*all1[1] == *FP);
    assert(*all1[2] == *FS);
    assert(*all1[3] == *FS2);

    s.updatePreparat("tort", 0, "ridicata");

    vector<Preparat *> all2 = s.getAll();
    assert(all2[0]->getPret() == 90);
    assert(all2[0]->getCerere() == "ridicata");

    s.deletePreparat("tort");

    vector<Preparat *> all3 = s.getAll();
    assert(all3.size() == 3);
    assert(*all3[0] == *FP);
    assert(*all3[1] == *FS);
    assert(*all3[2] == *FS2);

//    delete repo;


}

void Tests::listariTests() {
    Repository *repo2 = new Repository;
    FelulPrincipal *FP1 = new FelulPrincipal("supa1", 10, "sarat", 100, "ridicata", true);
    FelulPrincipal *FP2 = new FelulPrincipal("supa2", 10, "sarat", 200, "medie", false);
    FelulPrincipal *FP3 = new FelulPrincipal("supa3", 10, "sarat", 300, "scazuta", true);
    FelulSecundar *FS = new FelulSecundar("pireu", 10, "sarat", 100, "ridicata", 30);
    Desert *D = new Desert("lava", 10, "dulce", 100, "ridicata", true);

    repo2->add(FP1);
    repo2->add(FP2);
    repo2->add(FP3);
    repo2->add(FS);
    repo2->add(D);
    Service ser(repo2);

    vector<Preparat *> rez = ser.listareFP(100, '>');

    assert(rez.size() == 2);
    assert(*rez[0] == *FP1);
    assert(*rez[1] == *FP3);

    ser.deletePreparat("supa2");
    ser.deletePreparat("supa3");

    ser.addD("tort", 120, "sarat", 100, "ridicata", true);
    ser.addD("tiramisu", 130, "dulce", 100, "ridicata", true);

    auto rez1 = ser.listareD();
    Desert *D2 = new Desert("tiramisu", 130, "dulce", 100, "ridicata", true);

    assert(rez1.size() == 2);
    assert(*rez1[0] == *D);
    assert(*rez1[1] == *D2);
}

void Tests::sortTests() {
    Repository *repo = new Repository;


    FelulSecundar *FS1 = new FelulSecundar("pireu1", 120, "sarat", 100, "ridicata", 30);
    FelulSecundar *FS2 = new FelulSecundar("pireu2", 10, "sarat", 100, "medie", 14);
    FelulSecundar *FS3 = new FelulSecundar("pireu3", 300, "sarat", 100, "ridicata", 20);
    FelulSecundar *FS4 = new FelulSecundar("pireu4", 300, "sarat", 100, "ridicata", 50);
    FelulPrincipal *FP1 = new FelulPrincipal("supa1", 10, "sarat", 100, "ridicata", true);

    repo->add(FS1);
    repo->add(FS2);
    repo->add(FP1);
    repo->add(FS3);
    repo->add(FS4);

    Service ser(repo);

    vector<Preparat *> rez = ser.sortare(40, '<');

    assert(rez.size() == 2);
    assert(*rez[0] == *FS3);
    assert(*rez[1] == *FS1);

}

void Tests::filterTests() {
    Repository *repo = new Repository;
    FelulPrincipal *FP1 = new FelulPrincipal("supa1", 10, "sarat", 100, "ridicata", true);
    FelulSecundar *FS1 = new FelulSecundar("pireu1", 120, "iute", 100, "ridicata", 30);
    FelulSecundar *FS2 = new FelulSecundar("pireu2", 10, "sarat", 100, "medie", 14);
    FelulSecundar *FS3 = new FelulSecundar("pireu3", 300, "iute", 100, "ridicata", 20);
    FelulSecundar *FS4 = new FelulSecundar("pireu4", 300, "sarat", 100, "ridicata", 50);


    repo->add(FS1);
    repo->add(FS2);
    repo->add(FP1);
    repo->add(FS3);
    repo->add(FS4);
    Service service(repo);

    service.filtrare("sarat");

    auto all = service.getAll();
    assert(all.size() == 3);
    assert(*all[0] == *FS2);
    assert(*all[1] == *FP1);
    assert(*all[2] == *FS4);
}

void Tests::repoFileTests() {

    ifstream infile(R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\testIn.txt)");
    ofstream outfile(R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\testOut.txt)");

    RepoFile *repo = new RepoFile(R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\testIn.txt)",
                  R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\Lab11-12Exc&Val\testOut.txt)");
    Desert *D = new Desert("tort", 90, "dulce", 300, "ridicata", true);
    FelulSecundar *FS = new FelulSecundar("pireu", 30, "sarat", 150, "medie", 30);
    FelulPrincipal *FP = new FelulPrincipal("supa", 15, "sarat", 100, "ridicata", true);


    vector<Preparat *> all = repo->getAll();

    assert(repo->getSize() == 3);
    assert(*all[0] == *D);
    assert(*all[1] == *FS);
    assert(*all[2] == *FP);

    ifstream infile1(R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\testIn1.txt)");
    ofstream outfile1(R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\testOut1.txt)");

    RepoFile *repo1 = new RepoFile(R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\testIn1.txt)",
                                  R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\Lab11-12Exc&Val\testOut1.txt)");

    repo1->add(D);
    repo1->add(FS);
    repo1->add(FP);

    FelulSecundar *FS2 = new FelulSecundar("friptura", 40, "sarat", 350, "medie", 50);
    repo1->add(FS2);

    assert(repo1->getFrom(3) == FS2);

    vector<Preparat *> all1 = repo1->getAll();

    assert(repo1->getSize() == 4);
    assert(*all1[0] == *D);
    assert(*all1[1] == *FS);
    assert(*all1[2] == *FP);
    assert(*all1[3] == *FS2);

    Desert *D1 = new Desert("tort", 50, "dulce", 360, "medie", false);
    repo1->update(D, D1);

    assert(repo1->find(D) == -1);
    assert(repo1->find(D1) != -1);

    repo1->remove(D1);

    assert(repo1->getSize() == 3);
    assert(repo1->getFrom(0) == FS);
    assert(repo1->getFrom(1) == FP);
    assert(repo1->getFrom(2) == FS2);
    infile.close();
    infile1.close();
    outfile.close();
    outfile1.close();

    remove(R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\testOut.txt)");
    remove(R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\testOut1.txt)");

}

void Tests::repoTests() {
    Desert *D = new Desert("tort", 90, "dulce", 300, "ridicata", true);
    FelulSecundar *FS = new FelulSecundar("pireu", 30, "sarat", 150, "medie", 30);
    FelulPrincipal *FP = new FelulPrincipal("supa", 15, "sarat", 100, "ridicata", true);


    Repository repo;
    repo.add(D);
    repo.add(FS);
    repo.add(FP);

    vector<Preparat *> all = repo.getAll();

    assert(repo.getSize() == 3);
    assert(all[0] == D);
    assert(all[1] == FS);
    assert(all[2] == FP);

    FelulSecundar *FS2 = new FelulSecundar("friptura", 40, "sarat", 350, "medie", 50);
    repo.add(FS2);

    assert(repo.getFrom(3) == FS2);


    vector<Preparat *> all1 = repo.getAll();

    assert(repo.getSize() == 4);
    assert(all1[0] == D);
    assert(all1[1] == FS);
    assert(all1[2] == FP);
    assert(all1[3] == FS2);

    Desert *D1 = new Desert("tort", 50, "dulce", 360, "medie", true);
    repo.update(D, D1);

    assert(repo.getAll()[0]->getPret() == 50);
    assert(repo.find(D) == -1);
    assert(repo.find(D1) != -1);

    repo.remove(D1);

    assert(repo.getSize() == 3);
    assert(repo.getFrom(0) == FS);
    assert(repo.getFrom(1) == FP);
    assert(repo.getFrom(2) == FS2);
}

void Tests::validatorFPTests() {
    ValidatorFelulPrincipal val;
    FelulPrincipal *FP1 = new FelulPrincipal("supa1", 10, "sarat", 100, "ridicata", true);
    try {
        val.validate(FP1);
    }
    catch (...) {
        assert (false);
    }
    FelulPrincipal *FP2 = new FelulPrincipal("", 10, "sarat", 100, "ridicata", true);
    try
    {
        val.validate(FP2);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulPrincipal *FP3 = new FelulPrincipal("supa1", -10, "sarat", 100, "ridicata", true);
    try
    {
        val.validate(FP3);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulPrincipal *FP4 = new FelulPrincipal("supa1", 10, "dulce", 100, "ridicata", true);
    try
    {
        val.validate(FP4);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulPrincipal *FP5 = new FelulPrincipal("supa1", 10, "sarat", -100, "ridicata", true);
    try
    {
        val.validate(FP5);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulPrincipal *FP6 = new FelulPrincipal("supa1", 10, "sarat", 100, "aproape medie", true);
    try
    {
        val.validate(FP6);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    delete FP1;
    delete FP2;
    delete FP3;
    delete FP4;
    delete FP5;
    delete FP6;
}

void Tests::validatorFSTests() {
    ValidatorFelulSecundar val;
    FelulSecundar *FS1 = new FelulSecundar("supa1", 10, "sarat", 100, "ridicata", 10);
    try {
        val.validate(FS1);
    }
    catch (...) {
        assert (false);
    }
    FelulSecundar *FS2 = new FelulSecundar("", 10, "sarat", 100, "ridicata", 10);
    try
    {
        val.validate(FS2);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulSecundar *FS3 = new FelulSecundar("supa1", -10, "sarat", 100, "ridicata", 10);
    try
    {
        val.validate(FS3);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulSecundar *FS4 = new FelulSecundar("supa1", 10, "amar", 100, "ridicata", 10);
    try
    {
        val.validate(FS4);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulSecundar *FS5 = new FelulSecundar("supa1", 10, "sarat", -100, "ridicata", 10);
    try
    {
        val.validate(FS5);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulSecundar *FS6 = new FelulSecundar("supa1", 10, "sarat", 100, "aproape medie", 10);
    try
    {
        val.validate(FS6);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    FelulSecundar *FS7 = new FelulSecundar("supa1", 10, "sarat", 100, "medie", -10);
    try
    {
        val.validate(FS7);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    delete FS1;
    delete FS2;
    delete FS3;
    delete FS4;
    delete FS5;
    delete FS6;
    delete FS7;
}

void Tests::validatorDTests() {
    ValidatorDesert val;
    Desert *D1 = new Desert("supa1", 10, "sarat", 100, "ridicata", true);
    try {
        val.validate(D1);
    }
    catch (...) {
        assert (false);
    }
    Desert *D2 = new Desert("", 10, "sarat", 100, "ridicata", true);
    try
    {
        val.validate(D2);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    Desert *D3 = new Desert("supa1", -10, "sarat", 100, "ridicata", true);
    try
    {
        val.validate(D3);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    Desert *D4 = new Desert("supa1", 10, "iute", 100, "ridicata", true);
    try
    {
        val.validate(D4);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    Desert *D5 = new Desert("supa1", 10, "sarat", -100, "ridicata", true);
    try
    {
        val.validate(D5);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    Desert *D6 = new Desert("supa1", 10, "sarat", 100, "aproape medie", true);
    try
    {
        val.validate(D6);
        assert(false);
    }
    catch (ValidationException& e) {}
    catch (...) {
        assert(false);
    }
    delete D1;
    delete D2;
    delete D3;
    delete D4;
    delete D5;
    delete D6;
}


