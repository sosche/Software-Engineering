//@(#) CocktailZubereiter.cpp


#include "CocktailZubereiter.h"
#include <set>

CocktailZubereiter::CocktailZubereiter(DeviceVerwalter *dv) {
    myDeviceVerwalter = dv;
}

void
CocktailZubereiter::checkZutatenStatus(int &needToRefill, std::vector<std::string> &zutatenNeedToRefill, Recipe *rzpt) {
    //std::cout << "==Checking Process of Zutaten==" << std::endl;

    for (int i = 0; i < rzpt->getNoOfRecipeSteps(); i++) {
        RecipeStep *schritt = rzpt->getRecipeStep(i);
        std::string zutat = schritt->getZutat();
        float benoetigteMenge = schritt->getMenge();

        bool enoughQuantity = enoughInDosiererFor(zutat, benoetigteMenge);


        std::set<std::string> specialFaehigkeit;
        specialFaehigkeit.insert("Stampfen");
        specialFaehigkeit.insert("Mischen");
        specialFaehigkeit.insert("Schuetteln");

        if (specialFaehigkeit.find(zutat) == specialFaehigkeit.end() && !enoughQuantity) {
            //std::cout << zutat << " - NACHFÜLLEN" << std::endl;
            needToRefill = 0;
            zutatenNeedToRefill.push_back(zutat);
        }
    }

    //std::cout << "==Checking Process done==" << std::endl << std::endl;
}

bool CocktailZubereiter::enoughInDosiererFor(const std::string &zutat, float &benoetigteMenge) const {

    float vorhandeneMenge = 0;
    for (InternalDevice *iDevice : myDeviceVerwalter->getDevices(zutat)) {
        Dosierer *dosierer = static_cast<Dosierer *> (iDevice);
        if (zutat == "Limettenstuecke") {
            vorhandeneMenge += dosierer->getMenge() / dosierer->getStueckProZeit();
            //enoughQuantity = dosierer->checkQuantity(benoetigteMenge * dosierer->getStueckProZeit());
        } else
            vorhandeneMenge += dosierer->getMenge();
        //enoughQuantity = static_cast<Dosierer *> (iDevice)->checkQuantity(benoetigteMenge);
    }

    return vorhandeneMenge >= benoetigteMenge;
}

void CocktailZubereiter::cocktailZubereiten(Recipe *rzpt) {
    //std::system("clear");
    std::cout << "Gruess Gott, ich bin der CocktailZubereiter!" << std::endl
              << "Ich habe Ihre Bestellung: " << rzpt->getName() << " erhalten." << std::endl
              << "Bitte gedulden Sie sich einen Moment, waehrend ich den Cocktail zubereite!\n" << std::endl;

    if (!rzpt->isMischbar()) {
        int needToRefill = 0;
        std::vector<std::string> zutatenNeedToRefill;

        checkZutatenStatus(needToRefill, zutatenNeedToRefill, rzpt);

        if (needToRefill == 0) {
            std::cout << "COCKTAIL KONNTE NICHT ZUBEREITET WERDEN" << std::endl;
            refillModus(zutatenNeedToRefill);
            checkZutatenStatus(needToRefill, zutatenNeedToRefill, rzpt);
        }
    } else {
        executeRecipe(rzpt);
        myDeviceVerwalter->entleeren(0);
        myDeviceVerwalter->putzen();
    }
    //else {
    //    refillModus(zutatenNeedToRefill);
    //}
}

std::vector<InternalDevice *> CocktailZubereiter::executeRecipe(Recipe *rzpt) const {
    std::vector<InternalDevice *> usedDevices;
    for (int i = 0; i < rzpt->getNoOfRecipeSteps(); i++) {
        RecipeStep *schritt = rzpt->getRecipeStep(i);
        std::string zutat = schritt->getZutat();
        float menge = schritt->getMenge();
        std::cout << "Rezeptschritt: " << zutat << ", " << menge << std::endl;
        for (InternalDevice *dev: myDeviceVerwalter->rezeptSchrittZubereiten(zutat, menge))
            usedDevices.push_back(dev);
    }
    return usedDevices;
}

void CocktailZubereiter::refillModus(std::vector<std::string> &zutatenNeedToRefill) {
    std::cout << "Sie müssen folgende Zutaten nachfüllen: " << std::endl;
    for (unsigned int i = 0; i < zutatenNeedToRefill.size(); i++) {
        std::cout << zutatenNeedToRefill[i] << std::endl;
    }

    std::cout << std::endl;

    std::string eingabe = "-1";
    std::cout << "Haben Sie die fehlenden Zutaten nachgefüllt?\n 0 = NEIN, 1 = JA" << std::endl;
    std::cin >> eingabe;

    if (eingabe == "1" || eingabe == "JA" || eingabe == "Ja") {
        for (unsigned int i = 0; i < zutatenNeedToRefill.size();) {
            for (InternalDevice *iDevice : myDeviceVerwalter->getDevices(zutatenNeedToRefill[i])) {
                static_cast<Dosierer *> (iDevice)->refill();
            }
            zutatenNeedToRefill.erase(zutatenNeedToRefill.begin());
        }
        std::cout << "INFO: Der Cocktail ist wieder verfügbar\n -> Bitte Cocktail nochmal auswählen"
                  << std::endl;
    } else {
        std::cout << "Cocktail kann nicht zubereitet werden -> Zutaten Fehlen!!" << std::endl;
    }
    std::cout << std::endl;
}

