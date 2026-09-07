#ifndef RETURNINGSTATE_H
#define RETURNINGSTATE_H
#include "UnitState.h"

class ReturningState : public UnitState {
public:
    static ReturningState* getInstance();
    virtual void returnToStation(ResponseUnit* unit);
    virtual void goOutOfService(ResponseUnit* unit);
    virtual std::string getStateName() const { return "Returning"; }
private:
    ReturningState() {}
};
#endif
