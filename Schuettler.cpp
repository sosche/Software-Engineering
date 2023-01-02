//@(#) Schuettler.cpp


#include "Schuettler.h"

Schuettler::Schuettler() : InternalDevice() {
}

void Schuettler::doIt(float time) {
    myTimer->sleep_in_one_second_intervals(time * 1000);
    std::cout << std::endl;
}
