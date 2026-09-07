#ifndef ENROUTESTATE_H
#define ENROUTESTATE_H
#include "UnitState.h"

class EnRouteState : public UnitState {
public:
    static EnRouteState* getInstance();
    virtual void arrive(ResponseUnit* unit);
    virtual void goOutOfService(ResponseUnit* unit);
    virtual std::string getStateName() const { return "EnRoute"; }
private:
    EnRouteState() {}
};
#endif
