//@(#) Schuettler.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

#include "InternalDevice.h"
/**
 * @class Schuettler
 *
 * @brief Schuttler shakes the selected ingredients in a time
 * interval and it does inherit the functions and attributs
 * from the class InternalDevice
 */
class Schuettler : public InternalDevice {
public:
    /**
     * @brief Construct that creates a Schuettler
     *
     * This Construct creates via a parameter-list a Object
     * from the class InternalDevice
     */
    Schuettler();
     /**
      *
      * @param time a float number
      *
      * This function calls the function
      * "sleep_in_one_second_intervals" from the class Timer
      * which gives the paramter time and multyplies it with the factor 1000
      */
    void doIt(float time);

private:
};

#endif
