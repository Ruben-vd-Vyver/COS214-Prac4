#ifndef UNITDECORATOR_H
#define UNITDECORATOR_H

#include "WorkElement.h"

// Decorator. Wraps any WorkElement - a plain unit or another decorator - and
// owns what it wraps, so a whole decorator chain is destroyed cleanly from
// the outermost decorator inward. By extending WorkElement, a decorated unit
// remains usable anywhere a WorkElement is expected: inside a WorkGroup,
// through an iterator, or via performDuty().
class UnitDecorator : public WorkElement {
protected:
    WorkElement* wrapped;

public:
    explicit UnitDecorator(WorkElement* wrappedElement);
    virtual ~UnitDecorator();

    virtual void performDuty();
    virtual std::string getName() const;
    virtual int getPersonnelCount() const;
    virtual bool isAvailable() const;
};

#endif
