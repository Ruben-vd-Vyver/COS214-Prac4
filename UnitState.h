#ifndef UNITSTATE_H
#define UNITSTATE_H

#include <string>

class ResponseUnit;

// State. Every action defaults to "reject and log" in the base class; each
// ConcreteState only overrides the actions that are actually valid from
// that point in the lifecycle. This is what lets invalid transitions be
// handled sensibly without any switch/if-chain over a state enum.
class UnitState {
public:
    virtual ~UnitState() {}

    virtual void dispatch(ResponseUnit* unit);
    virtual void enRoute(ResponseUnit* unit);
    virtual void arrive(ResponseUnit* unit);
    virtual void completeTask(ResponseUnit* unit);
    virtual void returnToStation(ResponseUnit* unit);
    virtual void goOutOfService(ResponseUnit* unit);
    virtual void returnToService(ResponseUnit* unit);

    virtual std::string getStateName() const = 0;
    virtual bool isAvailableState() const { return false; }

protected:
    void rejectTransition(ResponseUnit* unit, const std::string& action) const;
};

#endif
