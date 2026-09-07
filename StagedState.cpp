#include "StagedState.h"
#include "DispatchedState.h"
#include "OutOfServiceState.h"
#include "ResponseUnit.h"
#include <iostream>

StagedState* StagedState::getInstance() {
    static StagedState instance;
    return &instance;
}

void StagedState::dispatch(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " dispatched.\n";
    unit->setState(DispatchedState::getInstance());
}

void StagedState::goOutOfService(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " taken out of service.\n";
    unit->setState(OutOfServiceState::getInstance());
}
