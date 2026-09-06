#include "OutOfServiceState.h"
#include "StagedState.h"
#include "ResponseUnit.h"
#include <iostream>

OutOfServiceState* OutOfServiceState::getInstance() {
    static OutOfServiceState instance;
    return &instance;
}

void OutOfServiceState::returnToService(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " returned to service and available.\n";
    unit->setState(StagedState::getInstance());
}
