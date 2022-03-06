
#include <iostream>
#include "UI.h"

void UI::displayMenu() {
    cout << "1. Adaugare fel principal\n";
    cout << "2. Adaugare fel secundar\n";
    cout << "3. Adaugare desert\n";
    cout << "4. Stergere preparat\n";
    cout << "5. Modificare preparat (pret sau/si cerere)\n";
    cout << "6. Listarea felurilor principale autohtone cu un numar de calorii mai mare/mai mic/egal cu unul dat.\n";
    cout << "7. Listarea deserturilor dulci si de post.\n";
    cout << "8. Sortarea felurilor doi cu un timp de asteptare mare/mai mic/egal cu unul dat si cu cerere ridicata in ordine descrescatoare a pretului.\n";
    cout << "9. Filtrarea preparatelor sarate/dulci/iuti (se pastreaza doar acestea)\n";
    cout << "a. Afisare preparate\n";
    cout << "x. Iesire\n";
}

void UI::runMenu() {
    string option;
    while (true) {
        displayMenu();
        cin >> option;
        cin.ignore();

        if (option == "1") {
            uiAddFP();
        } else if (option == "2") {
            uiAddFS();
        } else if (option == "3") {
            uiAddD();
        } else if (option == "4") {
            uiDeletePreparat();
        } else if (option == "5") {
            uiUpdatePreparat();
        } else if (option == "6") {
            uiListareFP();
        }else if (option == "7") {
            uiListareD();
        }else if (option == "8") {
            uiSortare();
        }else if (option == "9") {
            uiFiltrare();
        }else if (option == "a") {
            printAll();
        } else if (option == "x") {
            break;
        } else {
            cout << "Optiune gresita! Reincercati: ";
        }

    }
}

void UI::uiFiltrare()
{
    string gust;
    cout<<"Gustul preparatelor care se pastreaza (sarat/dulce/iute): \n";
    getline(cin,gust);

    service.filtrare(gust);
};

void UI::uiSortare()
{
    cout<<"Timpul de asteptare: \n";
    int timp;
    cin>>timp;
    char c;
    cout<<"Afisarea FS cu timpul de asteptare mai mic(<), mare(>) sau egal (=) cu cel dat? \n";
    cin>>c;
    auto rez = service.sortare(timp,c);

    for(int i=0;i<rez.size();i++)
        cout<<rez[i]->toString()<<'\n';
}

void UI::uiListareD()
{
    auto rez = service.listareD();

    for(int i=0;i<rez.size();i++)
        cout<<rez[i]->toString()<<'\n';
}

void UI::uiListareFP(){
    cout<<"Numarul de calorii: \n";
    int calorii;
    cin>>calorii;
    char c;
    cout<<"Afisarea FP cu nr de cal mai mic(<), mare(>) sau egal(=) cu cel dat? \n";
    cin>>c;
    auto rez = service.listareFP(calorii,c);

    for(int i=0;i<rez.size();i++)
        cout<<rez[i]->toString()<<'\n';
}

void UI::printAll() {
    auto all = service.getAll();
    for (int i = 0; i < all.size(); ++i) {
        cout << all[i]->toString() << '\n';
    }
    cout<<'\n';
}

void UI::uiAddFP() {
    string nume, gust, cerere;
    int pret, calorii;
    int autohtonaInt;
    bool autohtona;

    cout << "Numele felului principal: ";
    getline(cin, nume);

    cout << "Pretul: ";
    cin >> pret;
    cin.ignore();

    cout << "Gustul felului principal(sarat/iute): ";
    getline(cin, gust);

    cout << "Numarul de calorii: ";
    cin >> calorii;
    cin.ignore();

    cout << "Cerere (scazuta/medie/ridicata): ";
    getline(cin, cerere);

    do {
        cout << "Este o reteta autohtona (1. true/0. false)?: ";
        cin >> autohtonaInt;
    } while (!(autohtonaInt == 1 || autohtonaInt == 0));

    autohtona = (autohtonaInt == 1);
    try
    {
    this->service.addFP(nume, pret, gust, calorii, cerere, autohtona);
    }
    catch (RepoException& e)
    {
        cout << e.what() << endl;
    }
    catch (ValidationException& e) {
        cout << e.toString() << endl;
    }

}

void UI::uiAddFS() {
    string nume, gust, cerere;
    int pret, calorii;
    int timp;

    cout << "Numele felului secundar: ";
    getline(cin, nume);

    cout << "Pretul: ";
    cin >> pret;
    cin.ignore();

    cout << "Gustul felului secundar(sarat/dulce/iute): ";
    getline(cin, gust);

    cout << "Numarul de calorii: ";
    cin >> calorii;
    cin.ignore();

    cout << "Cerere (scazuta/medie/ridicata): ";
    getline(cin, cerere);

    cout << "Timpul de preparare: ";
    cin >> timp;

    try
    {
    this->service.addFS(nume, pret, gust, calorii, cerere, timp);
    }
    catch (RepoException& e)
    {
        cout << e.what() << endl;
    }
    catch (ValidationException& e) {
        cout << e.toString() << endl;
    }
}

void UI::uiAddD() {
    string nume, gust, cerere;
    int pret, calorii;
    int dePostInt;
    bool dePost;

    cout << "Numele desertului: ";
    getline(cin, nume);

    cout << "Pretul: ";
    cin >> pret;
    cin.ignore();

    cout << "Gustul desertului(sarat/dulce): ";
    getline(cin, gust);

    cout << "Numarul de calorii: ";
    cin >> calorii;
    cin.ignore();

    cout << "Cerere (scazuta/medie/ridicata): ";
    getline(cin, cerere);

    do {
        cout << "Este de post (1. true/ 0. false)?: ";
        cin >> dePostInt;
    } while (!(dePostInt == 1 || dePostInt == 0));

    dePost = (dePostInt == 1);


    try
    {
    this->service.addD(nume, pret, gust, calorii, cerere, dePost);
    }
    catch (RepoException& e)
    {
        cout << e.what() << endl;
    }
    catch (ValidationException& e) {
        cout << e.toString() << endl;
    }
}

void UI::uiDeletePreparat() {
    string nume;
    cout << "Numele preparatului de sters: ";
    getline(cin, nume);

    try {
    this->service.deletePreparat(nume);
    }
    catch (RepoException& e) {
        cout << e.what() << endl;
    }
}

void UI::uiUpdatePreparat() {
    string nume;
    cout << "Numele preparatului de modificat: ";
    getline(cin, nume);
    int opt;
    do {
        cout << "Doriti sa modificati pretul acestui preparat? \n 1. Da\n2. Nu \n";
        cin >> opt;
    } while (opt < 1 || opt > 2);
    cin.ignore();
    int pret = 0;
    if (opt == 1) {
        cout << "Pretul nou: ";
        cin >> pret;
    } else
        pret = 0;

    do {
        cout << "Doriti sa modificati cererea acestui preparat? \n 1. Da\n2. Nu \n";
        cin >> opt;
    } while (opt < 1 || opt > 2);
    cin.ignore();
    string cerere = "";
    if (opt == 1) {
        cout << "Cerere (scazuta/medie/ridicata): ";
        getline(cin, cerere);
    }
    service.updatePreparat(nume, pret, cerere);
}

UI::UI() {

}

UI::UI(Service &service) {
    this->service = service;
}

UI::~UI() {

}

