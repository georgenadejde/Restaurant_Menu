
#ifndef PROIECTLAB13_14_UI_H
#define PROIECTLAB13_14_UI_H


//#include "../Service/Service.h"

#include "../Service/Service.h"

class UI {
private:
    Service service;
    void displayMenu();
    void printAll();
    void uiAddFP();
    void uiAddFS();
    void uiAddD();
    void uiDeletePreparat();
    void uiUpdatePreparat();
    void uiListareFP();
    void uiListareD();
    void uiSortare();
    void uiFiltrare();

public:
    UI();
    UI(Service& service);
    ~UI();
    void runMenu();
};


#endif //PROIECTLAB13_14_UI_H
