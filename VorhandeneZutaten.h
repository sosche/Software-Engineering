//@(#) VorhandeneZutaten.h

#ifndef VorhandeneZutaten_H_H
#define VorhandeneZutaten_H_H

#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>
#include <cstdlib> // fuer exit() unter Linux
#include <iostream>

/**
 *  @class VorhandeneZutaten
 *  @brief manages all ingredients
 *
 *  loads all ingredients from zutaten.txt file and manages them
 *
 */
class VorhandeneZutaten {
public:

    /**
     * @brief copy constructor
     * @param other object that needs to be copied
     */
    VorhandeneZutaten(VorhandeneZutaten& other);

    VorhandeneZutaten(void);
    virtual ~VorhandeneZutaten();

    /**
     * @brief prints all ingredients on console
     */
    void browse(void);

    /**
     * returns the ingredient based on the index
     * @return string
     */
    std::string getZutat(int);

    /**
     *
     * returns the amount of existing ingredients
     * @return int
     */
    int getAnzahlVorhandeneZutaten();

    /**
     * @brief loads some dummy values in memory if VorhandeneZutaten::DEBUG is true
     */

    //cppcheck-suppress unusedFunction
    void DummyZutatenEinfuegen(); //FIXME: commented out because of cppcheck; not used yet
private:
    std::vector<std::string> * zutaten;

    static const bool DEBUG = false;

    void zutatenEinlesen();


    /**
     * @brief reads from file
     * @param [in] path filepath as String
     *
     *
     */
    virtual void ZutatenDateiEinlesen(std::string path);


    /**
     * @brief adds actions like "mischen" or "stampfen" to 'zutaten' collection
     */
    void spezielleFaehigkeitenHinzufuegen();

    /**
     * counts how many Dosierer are available based on the size of 'zutaten' collection
     */
    int anzahlDosierer;

};
static std::string FileName;
#endif
