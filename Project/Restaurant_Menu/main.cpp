#include <iostream>
#include "Teste/Tests.h"
#include "Repository/Repository.h"
#include "Service/Service.h"
#include "UI/UI.h"
#include "Repository/RepoFile.h"

using namespace std;

int main() {
    Tests T;
    T.runAllTests();

//    Repository *repo = new Repository;
//    FelulPrincipal *FP1 = new FelulPrincipal("supa1", 10, "sarat", 100, "ridicata", true);
//    FelulSecundar *FS1 = new FelulSecundar("pireu1", 120, "iute", 100, "ridicata", 30);
//    FelulSecundar *FS2 = new FelulSecundar("pireu2", 10, "sarat", 100, "medie", 14);
//    FelulSecundar *FS3 = new FelulSecundar("pireu3", 300, "iute", 100, "ridicata", 20);
//    FelulSecundar *FS4 = new FelulSecundar("pireu4", 300, "sarat", 100, "ridicata", 50);
//    repo->add(FS1);
//    repo->add(FS2);
//    repo->add(FP1);
//    repo->add(FS3);
//    repo->add(FS4);
    RepoFile *repo = new RepoFile(
            R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\PreparateIn.txt)",
            R"(C:\Users\SirBunger\Documents\Cursuri Babes\OOPLabs\ProiectLab13-14\PreparateOut.txt)");
    Service service(repo);
    UI ui(service);
    ui.runMenu();
    return 0;
}
