//@(#) Timer.cpp


#include "Timer.h"

void Timer::set_Turbo(int turbo) {
    this->booster = turbo;
}

Timer * Timer::getInstance() {
    if (!instanceFlag) {
        theTimer = new Timer();
        instanceFlag = true;
        return theTimer;
    } else {
        return theTimer;
    }
}

void Timer::sleep(long delay_in_ms){
    // if netbeans does not recognize system_clock you have to set the project properties to C++11:
    // Project-Properties->Code Assistance -> C++ (and C). Seit it to C++!
    long now_millis = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();      
    long limit = now_millis + (delay_in_ms / booster);
    
    while (limit > now_millis) {

        now_millis = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();;
    }
}

void Timer::sleep_in_one_second_intervals(long delay_in_ms) {
    // to improve compatibility between Linux and Windows this implementation
    // is using busy wait (and avoids threads)! On purpose...
    long delay=0;
    
    while (delay_in_ms >0) {
        std::cout << "*" << std::flush;
        if (delay_in_ms >=1000){
            delay = 1000;
            delay_in_ms = delay_in_ms-delay;
        } else {
            delay = delay_in_ms;
            delay_in_ms = 0;          
        }
        sleep(delay);
    }   
}


bool Timer::instanceFlag = false;

Timer * Timer::theTimer = 0;