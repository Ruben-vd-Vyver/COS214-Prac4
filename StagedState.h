#ifndef STAGEDSTATE_H
#define STAGEDSTATE_H
#include "UnitState.h"

class StagedState : public UnitState {
public:
    static StagedState* getInstance();
    virtual void dispatch(ResponseUnit* unit);
    virtual void goOutOfService(ResponseUnit* unit);
    virtual std::string getStateName() const { return "Staged"; }
    virtual bool isAvailableState() const { return true; }
private:
    StagedState() {}
};
#endif
