#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include "WorkElement.h"
#include <string>

class UnitState;

// Leaf (Composite) and Context (State). A genuine individual resource in the
// hierarchy whose behaviour changes as it moves through its deployment
// lifecycle. Concrete subclasses only need to supply executeTask() - the
// domain-specific action performed once on scene.
class ResponseUnit : public WorkElement {
protected:
    std::string callSign;
    int personnelCount;
    UnitState* currentState; // non-owning: states are shared singletons

    virtual void executeTask() = 0;

public:
    ResponseUnit(const std::string& callSign, int personnelCount);
    virtual ~ResponseUnit();

    void dispatch();
    void enRoute();
    void arrive();
    void completeTask();
    void returnToStation();
    void goOutOfService();
    void returnToService();

    void setState(UnitState* state);
    std::string getStateName() const;

    virtual void performDuty();
    virtual std::string getName() const;
    virtual int getPersonnelCount() const;
    virtual bool isAvailable() const;
};

#endif
