#ifndef PATTERN_OBSERVER_H
#define PATTERN_OBSERVER_H


class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};


#endif //PATTERN_OBSERVER_H
