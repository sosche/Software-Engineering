//@(#) Subject.cpp


#include "Subject.h"

void Subject::attach(Observer * observer) {
    this->observers.push_back(observer);
}

//cppcheck-suppress unusedFunction
void Subject::detach(Observer * observer) {
    for (int i = observers.size() - 1; i >= 0; i--) {
        if (observers.at(i) == observer) {
            observers.erase(observers.begin() + i);
        }
    }
}

void Subject::notify() {
    for (int i = observers.size() - 1; i >= 0; i--) {
        observers.at(i)->update();
    }
}
