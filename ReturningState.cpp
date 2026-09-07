#include "ReturningState.h"
#include "StagedState.h"
#include "OutOfServiceState.h"
#include "ResponseUnit.h"
#include <iostream>

ReturningState* ReturningState::getInstance() {
    static ReturningState instance;
    return &instance;
}

void ReturningState::returnToStation(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " back at station and available.\n";
    unit->setState(StagedState::getInstance());
}

void ReturningState::goOutOfService(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " taken out of service while returning.\n";
    unit->setState(OutOfServiceState::getInstance());
}
