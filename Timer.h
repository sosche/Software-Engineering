//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

#include <chrono>
using namespace std::chrono;
#include <iostream>

/**
 * @class Timer
 * @brief a timer to measure the time
 */

class Timer {
public:
    /**
     * sets the multiplier to boost the timer
     * @param turbo
     */
    void set_Turbo(int turbo);

    /**
     * @brief Singleton Timer
     *  @return Instance of Timer
     */
    static Timer * getInstance();

    /**
     * 	~Timer( )
     *     {
     *         instanceFlag = false;
     *     };
     */

    /**
     *
     * @param milliseconds time in milliseconds
     */
    void sleep_in_one_second_intervals(long milliseconds);

    /**
     * let the timer sleep for given time
     * @param delay_in_ms
     */
    void sleep(long delay_in_ms);


private:
    /**
     * flags whether an instance is already created
     */
    static bool instanceFlag;

    static Timer * theTimer;

    /**
     * boosts the timer base on value
     */
    int booster;

    Timer() : booster(1) {
    };

};

#endif
