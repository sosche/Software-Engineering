//@(#) Stampfer.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"

/**
 * @class Stampfer
 * @brief is an internal device to mash ingredients
 * inherits from InternalDevice
 */
class Stampfer : public InternalDevice {
public:
	/**
	 * @brief Constructor sets up Stampfer
	 * empty at the moment
	 */
    Stampfer();
	/**
	 * @brief supposed to perform the mashing task
	 * @param time
	 * sleeps in one second intervals depending on time
	 */
    void doIt(float time);

private:
};

#endif
