//@(#) MischbaresRezeptbuch.cpp


#include "MischbaresRezeptbuch.h"
#include <iostream>
//
void MischbaresRezeptbuch::browse() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "Es gibt " << this->getNumberOfRecipes() << " Cocktails" << std::endl;

    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        Recipe* r = this->getRecipe(i);
        r->browse();
        std::cout << std::endl;
    }
    std::cout << "*********************************************" << std::endl;

}
MischbaresRezeptbuch::MischbaresRezeptbuch() {
}

MischbaresRezeptbuch::MischbaresRezeptbuch(VorhandeneZutaten * zv) {

    // Debug *********
    std::cout << "********** Rezepte vor dem Filtern **********" << std::endl;
    this->browse();
    // ******************

    setZutatenVerwalter(zv);
    seitenRausreissen();
}

void MischbaresRezeptbuch::setZutatenVerwalter(VorhandeneZutaten * zv) {
    myZutatenVerwalter = zv;
}

void MischbaresRezeptbuch::seitenRausreissen() {
    for (int i = 0; i < getNumberOfRecipes(); ++i) {
        Recipe * r = getRecipe(i);
        for (int j = 0; j < r->getNoOfRecipeSteps(); j++) {
            std::string gesuchteZutat = r->getRecipeStep(j)->getZutat();
            if(!zutatExists(gesuchteZutat)){
                deleteRecipe(i);
                i--;
                break;
            }
        }
    }
}

bool MischbaresRezeptbuch::zutatExists(const std::string &gesuchteZutat) const {
    for (int k = 0; k < myZutatenVerwalter->getAnzahlVorhandeneZutaten(); k++) {
        if (myZutatenVerwalter->getZutat(k) == gesuchteZutat) {
            return true;
        }
    }
    return false;
}

