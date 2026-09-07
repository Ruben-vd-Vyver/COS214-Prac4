#ifndef OUTOFSERVICESTATE_H
#define OUTOFSERVICESTATE_H
#include "UnitState.h"

class OutOfServiceState : public UnitState {
public:
    static OutOfServiceState* getInstance();
    virtual void returnToService(ResponseUnit* unit);
    virtual std::string getStateName() const { return "OutOfService"; }
private:
    OutOfServiceState() {}
};
#endif
