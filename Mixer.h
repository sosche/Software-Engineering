//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

#include <iostream>

#include "InternalDevice.h"
/**
 * @class Mixer
 * @brief is an internal device to mix the ingredients
 */
class Mixer : public InternalDevice {
public:
    Mixer();

    void doIt(float time);

private:

};

#endif
