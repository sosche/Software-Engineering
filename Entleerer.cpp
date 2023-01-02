//@(#) Entleerer.cpp


#include "Entleerer.h"

Entleerer::Entleerer(float g, int zeiteinheiten, Waage * wg) : InternalDevice() {
    this->grammProZeit = g;
    this->zeiteinheit = zeiteinheiten;
    this->myWaage = wg;
    this->myWaage->attach(this);
    this->value = 0;
}

Entleerer::~Entleerer(){

}

//

void Entleerer::update() {
    if (!this->doinIt) return;
    if (myWaage->getWeight() <= this->value)
        doinIt = 0;
}

void Entleerer::doIt(float valueB) {
    std::cout << "Ihr Cocktail hat ein Gesamtgewicht von " << myWaage->getWeight() << "g" << std::endl;
    std::cout << "Entleervorgang wird begonnen..." << std::endl;
    this->value = valueB;
    doinIt = 1;
    while (doinIt) {
        myTimer->sleep_in_one_second_intervals(zeiteinheit);
        myWaage->changeWeight(-grammProZeit);
    }
    std::cout << std::endl;
    std::cout << "Entleervorgang wurde beendet, bitte entnehmen Sie ihren Cocktail!" << std::endl;
    std::cout << std::endl;
}
