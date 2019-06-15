#ifndef PATTERN_OBSERVABLE_H
#define PATTERN_OBSERVABLE_H

#include <vector>
#include <algorithm>
#include "Observer.h"

class Observable
{
    std::vector<Observer *> observers;

public:

    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }

    void detach(Observer *observer)
    {
        auto iterator = std::find(observers.begin(), observers.end(), observer);
        observers.erase(iterator);
    }

    void notify()
    {
        for (auto observer : observers)
        {
            observer->update();
        }
    }

    virtual ~Observable() = default;
};

#endif //PATTERN_OBSERVABLE_H
