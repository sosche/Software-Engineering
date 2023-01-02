//@(#) InternalDevice.h

#ifndef INTERNALDEVICE_H_H
#define INTERNALDEVICE_H_H

#include "Timer.h"

/**
 * @class InternalDevice
 * @brief abstraction of device units
 *
 *
 *  
 */
class InternalDevice {
public:

    /**
     *
     * @param [in] value amount of the ingredient
     *
     * needs to be overridden
     */
    virtual void doIt(float value) = 0;
/**
 * @brief cleans the device
 *
 * not working for the moment
 */
    void putzen();

private:
    void setTimer();


public:
    InternalDevice();
protected:
    /**
     * memorizes the time unit
     */
    int zeiteinheit;

    /**
     * switch to show if device is active
     */
    bool doinIt;


    /**
     * pointer to a timer
     */
    Timer * myTimer;

};

#endif
