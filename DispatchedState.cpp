#include "DispatchedState.h"
#include "EnRouteState.h"
#include "OutOfServiceState.h"
#include "ResponseUnit.h"
#include <iostream>

DispatchedState* DispatchedState::getInstance() {
    static DispatchedState instance;
    return &instance;
}

void DispatchedState::enRoute(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " confirms en route.\n";
    unit->setState(EnRouteState::getInstance());
}

void DispatchedState::goOutOfService(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " taken out of service before rolling.\n";
    unit->setState(OutOfServiceState::getInstance());
}
