//@(#) Dosierer.cpp


#include "Dosierer.h"

Dosierer::Dosierer(float g, int ze, std::string m_inhalt, Waage * wg, float menge)
: InternalDevice() , inhalt(m_inhalt), m_menge(menge), m_maxMenge(menge)
{
    this->grammProZeit = g;
    this->zeiteinheit = ze;
    this->myWaage = wg;
    this->myWaage->attach(this);
    this->gwicht=0;
}

void Dosierer::update() {
    if (!this->doinIt) return;
    if (myWaage->getDelta() >= gwicht) {
        doinIt = false;
    }

}

void Dosierer::doIt(float gramm) {
    this->gwicht = gramm;
    myWaage->tara();
    doinIt = true;

        std::cout << inhalt << " Ventil wurde geoeffnet" << std::endl;
        while (doinIt) {
            myTimer->sleep_in_one_second_intervals(zeiteinheit);
            myWaage->changeWeight(grammProZeit);
            if(myWaage->getDelta()>=m_menge)
                doinIt=false;
        }
        std::cout << std::endl << inhalt << " Ventil wurde geschlossen" << std::endl;
        std::cout << "Es wurden " << myWaage->getDelta() << "g " << inhalt << " abgefuellt" << std::endl;
        m_menge = m_menge - myWaage->getDelta();
        std::cout << "Es verbleiben " << m_menge << "g " << std::endl;

        std::cout << std::endl;
}


void Dosierer::refill()
{
    m_menge = m_maxMenge;
}

int Dosierer::getStueckProZeit() {
    return this->grammProZeit;
}

int Dosierer::getMenge() const {
    return m_menge;
}

const std::string& Dosierer::getZutat() const{
    return inhalt;

}