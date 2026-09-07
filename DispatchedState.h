#ifndef DISPATCHEDSTATE_H
#define DISPATCHEDSTATE_H
#include "UnitState.h"

class DispatchedState : public UnitState {
public:
    static DispatchedState* getInstance();
    virtual void enRoute(ResponseUnit* unit);
    virtual void goOutOfService(ResponseUnit* unit);
    virtual std::string getStateName() const { return "Dispatched"; }
private:
    DispatchedState() {}
};
#endif
