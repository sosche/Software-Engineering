//@(#) VorhandeneZutaten.cpp

#include "VorhandeneZutaten.h"
//

VorhandeneZutaten::VorhandeneZutaten(void) {
    this->zutaten = new std::vector<std::string>;
    zutatenEinlesen();
    this->anzahlDosierer = zutaten->size();

}

VorhandeneZutaten::~VorhandeneZutaten(void) {

}

VorhandeneZutaten::VorhandeneZutaten(VorhandeneZutaten &other)     {
    this->anzahlDosierer=other.anzahlDosierer;
    this->zutaten= new std::vector<std::string>;
    for(std::string string: *other.zutaten)
    {
        this->zutaten->push_back(string);
    }
    delete other.zutaten;
}



void VorhandeneZutaten::ZutatenDateiEinlesen(std::string myfile) {
    std::ifstream in;

    FileName = myfile;

    // Datei oeffnen
    in.open(FileName.c_str(), std::ios::in); // c_str wandelt den String in char[]
    // das braucht fstream

    if (!in) {// File konnte nicht geoeffnet werden
        std::string my_exception = "File not found: " + FileName;
        std::cout << my_exception << std::endl;
        throw my_exception;
    }

    std::cout << "Oeffne Zutatendatei " << FileName << std::endl;

    /* Daten lesen und in Liste eintragen */
    std::string zeile;
    while (getline(in, zeile)) {

        // Cut trailing \r - to make Linux or Windows Files equal
        if (zeile.size() && zeile[zeile.size() - 1] == '\r') {
            zeile = zeile.substr(0, zeile.size() - 1);
        }

        this->zutaten->push_back(zeile);
    }
    /* Datei wieder schliessen */
    in.close();
}


void VorhandeneZutaten::DummyZutatenEinfuegen() {
    zutaten->push_back("Limettenstuecke");
    zutaten->push_back("Zucker");
    zutaten->push_back("Cointreau");
    zutaten->push_back("Eis");
    zutaten->push_back("Wodka");
    zutaten->push_back("Rum weiss");
    zutaten->push_back("Zitronensaft");
    zutaten->push_back("Grenadine");
    //    zutaten->push_back("Limettensaft");
    //    zutaten->push_back("Tequilla");
    //    zutaten->push_back("Gin");
    //    zutaten->push_back("Noilly Prat");
}


void VorhandeneZutaten::zutatenEinlesen() {
    // int einlesen(list<string>* zutaten, std::string FileName)
    // Stream anlegen

        if (DEBUG) {
            DummyZutatenEinfuegen();
        } else {
            ZutatenDateiEinlesen("zutaten.txt");
        }

            this->browse(); // Eingelesene Zutaten ausgeben *********

        // Mischen und Stampfen, etc hinzufuegen
        spezielleFaehigkeitenHinzufuegen();

}

void VorhandeneZutaten::browse(void) {
    std::cout << "*********** Verfuegbare Einheiten bzw. Zutaten: ***********" << std::endl;
    for (unsigned int i = 0; i < zutaten->size(); i++/*std::string zutat : zutaten*/) {
        std::cout << zutaten->at(i) << std::endl;
    }
    std::cout << "**********************************************************" << std::endl;
}

void VorhandeneZutaten::spezielleFaehigkeitenHinzufuegen() {
    zutaten->push_back("Mischen");
    zutaten->push_back("Stampfen");
    zutaten->push_back("Schuetteln");
}

std::string VorhandeneZutaten::getZutat(int i) {
    return zutaten->at(i);
}

int VorhandeneZutaten::getAnzahlVorhandeneZutaten() {
    return zutaten->size();
}
