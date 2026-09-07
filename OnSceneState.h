#ifndef ONSCENESTATE_H
#define ONSCENESTATE_H
#include "UnitState.h"

class OnSceneState : public UnitState {
public:
    static OnSceneState* getInstance();
    virtual void completeTask(ResponseUnit* unit);
    virtual void goOutOfService(ResponseUnit* unit);
    virtual std::string getStateName() const { return "OnScene"; }
private:
    OnSceneState() {}
};
#endif
