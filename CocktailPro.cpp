//@(#) CocktailPro.cpp


#include "CocktailPro.h"
#include <string>

static const int TEN = 10;
static const int THOUSAND = 1000;


CocktailPro::CocktailPro(CocktailPro &copy) {
    theZutatenVerwalter = new VorhandeneZutaten(*copy.theZutatenVerwalter);
    theMischbaresRezeptbuch = new MischbaresRezeptbuch(theZutatenVerwalter);
    theDeviceVerwalter = new DeviceVerwalter(theZutatenVerwalter);
    theCocktailZubereiter = new CocktailZubereiter(new DeviceVerwalter(theZutatenVerwalter));

}

void CocktailPro::start() {
    while (true) {
        int CocktailNo = chooseCocktail();
        Recipe* rezeptptr;
        if (CocktailNo == -1)
            return;
        else
            rezeptptr = getCocktail(CocktailNo);

        if (rezeptptr != NULL) {
            std::cout << rezeptptr->getName() << std::endl;
            theCocktailZubereiter->cocktailZubereiten(rezeptptr);
        } else
            std::cout << "Falsche Cocktailnummer" << std::endl;

    }
}

CocktailPro::CocktailPro(int argc, char **param) {
    theZutatenVerwalter = new VorhandeneZutaten;
    theMischbaresRezeptbuch = new MischbaresRezeptbuch(theZutatenVerwalter);
    theDeviceVerwalter = new DeviceVerwalter(theZutatenVerwalter);
    theCocktailZubereiter = new CocktailZubereiter(theDeviceVerwalter);
    theZutatenVerwalter = new VorhandeneZutaten;

    Timer *theTimer = Timer::getInstance();
    theTimer->set_Turbo(1000);
    if (argc == 2) {// this has to be changed later
        if (param[1][1] == 'D') {
            theTimer->set_Turbo(THOUSAND);
            this->demo();
            //exit(0); //Delete because, rubbish
        } else { // Parameter => Turbo an
            theTimer->set_Turbo(TEN);
        }
    }
    // Mischen
}

void CocktailPro::demo() {
    int CocktailNo = 1;
    int max = theMischbaresRezeptbuch->getNumberOfRecipes();
    if (CocktailNo > 0 && CocktailNo <= max) {
        Recipe *rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
        std::cout << rezeptptr->getName() << std::endl;
        theCocktailZubereiter->cocktailZubereiten(rezeptptr);
        rezeptptr->setCounter();
    } else {
        std::cout << "Falsche Cocktailnummer!" << std::endl;
    }
}

int CocktailPro::chooseCocktail() {
    checkMischbar();
    std::cout << "********** Mischbare Rezepte **********" << std::endl;
    theMischbaresRezeptbuch->browse();
    std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;

    std::string eingabe = "";

    //cin.ignore();
    std::cin >> eingabe;

    int number = atoi(eingabe.c_str());
    return number;
}

Recipe* CocktailPro::getCocktail(int id) {
    int max = theMischbaresRezeptbuch->getNumberOfRecipes();
    for (int i=0; i < max; i++) {
        Recipe* tmp = theMischbaresRezeptbuch->getRecipe(i);
        if (id == tmp->getId())
            return tmp;
    }
    return NULL;
}

CocktailPro::~CocktailPro() {
    delete theZutatenVerwalter;
    delete theDeviceVerwalter;
    delete theMischbaresRezeptbuch;
    delete theCocktailZubereiter;
}

void CocktailPro::checkMischbar() {
    int max = theMischbaresRezeptbuch->getNumberOfRecipes();
    for (int i=0; i < max; i++) {
        Recipe* tmp = theMischbaresRezeptbuch->getRecipe(i);
        bool enoughQuantity;
        for (int j=0; j < tmp->getNoOfRecipeSteps(); j++) {
            RecipeStep *step = tmp->getRecipeStep(j);
            std::string ingredient = step->getZutat();
            float needed_amount = step->getMenge();
            enoughQuantity = theCocktailZubereiter->enoughInDosiererFor(ingredient, needed_amount);
            if (!enoughQuantity)
                break;
        }
        tmp->setMischbar(enoughQuantity);
    }
}