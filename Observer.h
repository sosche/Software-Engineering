//@(#) Observer.h

#ifndef OBSERVER_H_H
#define OBSERVER_H_H
/**
@class Observer

 @brief The Observer gives updates and it's a pattern
 */
class Observer {
public:
    /**
     * @brief virtual function which can be defined in another class
     */

    virtual void update() = 0;

};

#endif
