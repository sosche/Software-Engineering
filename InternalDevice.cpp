//@(#) InternalDevice.cpp


#include "InternalDevice.h"

// cppcheck-suppress unusedFunction
void InternalDevice::setTimer() {

}

InternalDevice::InternalDevice() {
    myTimer = Timer::getInstance();
    this->doinIt = 0;
    this->zeiteinheit = 0;
}

void InternalDevice::putzen() {
    //std::cout << "Ich putze mich..." << std::endl;
    //myTimer->sleep(500);
    //std::cout << "Ich bin fertig mit putzen!" << std::endl;
}
