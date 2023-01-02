//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"

#include <vector>
#include <iostream>

/**
 * @class Subject
 * @brief maintains a list of observers
 * notifies observers maintained
 */
class Subject {
public:
	/**
	 * @brief adds observer pointer to observers vector
	 * @param observer pointer to Observer object
	 */
    void attach(Observer * observer);
	/**
	 * @brief deletes observer pointer from observers vector
	 * @param observer pointer to Observer object
	 */
    void detach(Observer * observer);
    /**
	 * @brief updates all items of observers
	 */
	void notify();

private:
	/**
	 * is a vector of observers
	 */
    std::vector<Observer *> observers;

};

#endif
