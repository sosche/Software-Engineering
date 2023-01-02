//@(#) DeviceVerwalter.cpp


#include "DeviceVerwalter.h"
#include <algorithm>

static const int timeweight = 1000;

DeviceVerwalter::DeviceVerwalter(VorhandeneZutaten *zv) {
    setZutatenVerwalter(zv);
    this->createDevices();
}

void DeviceVerwalter::createDevices() {
    myDevices = new std::multimap<std::string, InternalDevice *>;
    theWaage = new Waage();

    myEntleerer = new Entleerer(25, timeweight, theWaage);
    myDevices->insert(std::make_pair("Entleeren", myEntleerer));

    myStampfer = new Stampfer();
    myDevices->insert(std::make_pair("Stampfen", myStampfer));

    mySchuettler = new Schuettler();
    myDevices->insert(std::make_pair("Schuetteln", mySchuettler));

    myMixer = new Mixer();
    myDevices->insert(std::make_pair("Mischen", myMixer));

    std::string myZutat;
    for (int i = myZutatenVerwalter->getAnzahlVorhandeneZutaten() - 1; i >= 0; i--) {
        myZutat = myZutatenVerwalter->getZutat(i);
        if (myZutat == "Eis")
            myDevices->insert(std::make_pair(myZutat, new Dosierer(20, timeweight, myZutat, theWaage, 1000)));
        else if (myZutat == "Limettenstuecke")
            myDevices->insert(std::make_pair(myZutat, new Dosierer(10, timeweight, myZutat, theWaage, 100)));
        else
            myDevices->insert(std::make_pair(myZutat, new Dosierer(4, timeweight, myZutat, theWaage, 1000)));
    }
}

void DeviceVerwalter::setZutatenVerwalter(VorhandeneZutaten *zv) {
    myZutatenVerwalter = zv;
}

std::vector<InternalDevice *> DeviceVerwalter::rezeptSchrittZubereiten(std::string zutat, float menge) {

    std::vector<InternalDevice *> devices = getDevices(zutat);
    std::vector<InternalDevice *> devicesToUse;
    std::vector<float> mengen;
    int amount = 0;

        for (InternalDevice *dev: devices) {
            Dosierer *dosierer = dynamic_cast<Dosierer *>(dev);

            if (dosierer != nullptr && dosierer->getMenge() > 0 && amount <= menge) {

                if (zutat == "Limettenstuecke") {
                    // Der Kunde will Limetten ja unbedingt nach Stueck und nicht nach Gewicht abmessen...
                    amount += dosierer->getMenge() / dosierer->getStueckProZeit();
                } else {
                    amount += dosierer->getMenge();
                }
                mengen.push_back(menge < amount ? menge : amount);
                menge -= mengen.back();
                devicesToUse.push_back(dev);
            }
        }


    for (unsigned int i = 0; i < devicesToUse.size(); i++) {
        InternalDevice *device = devicesToUse[i];
        if (zutat == "Limettenstuecke") {
            // Der Kunde will Limetten ja unbedingt nach Stueck und nicht nach Gewicht abmessen...
            int stckProZeit = static_cast<Dosierer *> (device)->getStueckProZeit();
            device->doIt(mengen[i] * stckProZeit);
        } else {
            device->doIt(mengen[i]);
        }


    }
    return devicesToUse;
}

std::vector<InternalDevice *> DeviceVerwalter::getDevices(std::string zutat) {

    std::vector<InternalDevice *> devices;

    for (auto it = myDevices->find(zutat); it != myDevices->end(); it++) {
        if (it->first != zutat)
            return devices;
        devices.push_back(it->second);
    }

    if (devices.empty())
        throw std::out_of_range("No Device found");

    return devices;
}

void DeviceVerwalter::entleeren(float menge) {
    myEntleerer->doIt(menge);
}

void DeviceVerwalter::putzen() {
    for (std::map<std::string, InternalDevice *>::iterator i = myDevices->begin(); i != myDevices->end(); ++i) {
        //std::cout << "Device mit der Aktion: " << i->first << " wird jetzt geputzt: " << std::endl;
        i->second->putzen();
    }
}
