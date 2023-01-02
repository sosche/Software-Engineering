//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"

/**
 * @class Waage
 * @brief implements a Waage to measure
 *
 * realized as observer pattern subject
 */

class Waage : public Subject {
public:
    /**
     * @brief Constructor for Waage
     */
    Waage();
    /**
     * @brief changes the current weight
     * @param v new weight
     */
    void changeWeight(int v);
    /**
     *
     * @returns the tara/deltaweight
     */
    int tara();
    /**
     *
     * returns the current weight
     * @return
     */
    int getWeight();
    /**
     * returns the current delta weight
     * @return
     */
    int getDelta();
private:
    int weight;
    int deltaweight;
};

#endif
