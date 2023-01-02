//@(#) Dosierer.h

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include <string>
#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
 * @class Dosierer
 * @brief Dosierer manages how much of an ingredient goes into the cocktail
 * it inherits form the InternalDevice and Observer class
 * it fills up the cocktail with the matching weight of the recipe
 */
class Dosierer : public InternalDevice, public Observer {
public:
    /**
     * @brief Constructor to set up a Dosierer with the weight, time, ingredient and Waage
     * @param g shows the weight for the ingredient
     * @param ze shows the time for the ingredient
     * @param m_inhalt shows the name of ingredient that is used
     * @param wg is a pointer to Waage
     * @param menge defines whats the limit of the Dosierer, also initializes dosierer to be filled up
     */
    Dosierer(float g, int ze, std::string m_inhalt, Waage * wg, float menge);

    /**
     * @brief update updates how much of the ingredient is in the Dosierer
     */
    virtual void update();

    /**
     * @brief doIt puts the ingredient onto the Waage and closes when the desired weight is reached
     * @param gramm shows the weight of the ingredient
     */
    void doIt(float gramm);


    /**
     * @brief refill sets the actual quantity in the Dosierer to maximum
     */
    void refill();

    /**
     * @brief the methods returns how much weight is added per specific time
     * @return a float of how much weight is added per time unit
     */
    int getStueckProZeit();
    /**
     * @brief getter
     * @return current menge of dosierer
     */
    int getMenge() const;
    /**
     * @brief getter
     * @return current zutat in dosierer
     */
    const std::string& getZutat() const;

private:
    /**
     * grammPro Zeit is a float
     * grammProZeit is used for showing how much weight is added per time unit
     */
    float grammProZeit;

    /**
     * is a pointer to Waage
     * it is used that the Dosierer knows how much weight it added
     */
    Waage * myWaage;

    /**
     * gewicht is a float
     * it is used for showing how much weight is needed of an ingredient
     */
    float gwicht;

    /**
     * inhalt is a string
     * it is used for showing the ingredient that is currently used
     */
    std::string inhalt;

    /**
     * m_menge shows the actual quantity in the Dosierer
     */
    float m_menge;

    /**
     * m_maxMenge saves the maximum filling quantity
     **/
    float m_maxMenge;

};

#endif
