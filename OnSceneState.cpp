#include "OnSceneState.h"
#include "ReturningState.h"
#include "OutOfServiceState.h"
#include "ResponseUnit.h"
#include <iostream>

OnSceneState* OnSceneState::getInstance() {
    static OnSceneState instance;
    return &instance;
}

void OnSceneState::completeTask(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " completed its task and is returning.\n";
    unit->setState(ReturningState::getInstance());
}

void OnSceneState::goOutOfService(ResponseUnit* unit) {
    std::cout << "  " << unit->getName() << " taken out of service on scene.\n";
    unit->setState(OutOfServiceState::getInstance());
}
