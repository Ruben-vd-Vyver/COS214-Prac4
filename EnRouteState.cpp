#include "EnRouteState.h"
#include "OnSceneState.h"
#include "OutOfServiceState.h"
#include "ResponseUnit.h"
#include <iostream>

EnRouteState* EnRouteState::getInstance() {
    static EnRouteState instance;
    return &instance;
}

void EnRouteState::arrive(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " arrived on scene.\n";
    unit->setState(OnSceneState::getInstance());
}

void EnRouteState::goOutOfService(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " broke down en route, taken out of service.\n";
    unit->setState(OutOfServiceState::getInstance());
}
