//@(#) Entleerer.h

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
 * @class Entleerer
 * @brief is prompts who heavy the Cocktail is and empties it. Then prompts that the Cocktail is finished
 * it inherits form the InternalDevice and Observer class to get information about the weight
 */
class Entleerer : public InternalDevice, public Observer {
public:
    /**
     * @brief Constructor sets up an Entleerer
     * @param g is the weight of everything in the Entleerer
     * @param zeiteinheiten is the time how much weight is removed per time unit
     * @param wg is the Waage to know how much weight is in the Entleerer
     */
    Entleerer(float g, int zeiteinheiten, Waage * wg);
    /**
     * @brief Destructor for Entleerer
     */
    ~Entleerer();

    /**
     * @brief the method updates how much weight is still in the Entleerer
     */
    void update();

    /**
     * @brief doIt prompts how much the Cocktail weights and then removes it form the Entleerer
     * it removes weight from the Entleerer specific per time unit til it is empty and prompts that the Cocktail
     * is ready to be taken
     * @param value is the value of the ingredient
     */

    void doIt(float value);

private:
    /**
     * grammPro Zeit is a float
     * grammProZeit is used for showing how much weight is removed per time unit
     */
    float grammProZeit;
     /**
     * is a pointer to Waage
     * it is used that the Dosierer knows how much weight it removed
     */
    Waage * myWaage;

    /**
     * float value
     * it is used for showing how much weight the Entleerer has
     */
    float value;

};

#endif
