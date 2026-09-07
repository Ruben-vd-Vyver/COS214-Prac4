#include "ResponseUnit.h"
#include "UnitState.h"
#include "StagedState.h"
#include <iostream>

ResponseUnit::ResponseUnit(const std::string& cs, int personnel)
    : callSign(cs), personnelCount(personnel), currentState(StagedState::getInstance()) {}

ResponseUnit::~ResponseUnit() {
    // currentState is a shared singleton owned by no one; nothing to delete.
}

void ResponseUnit::dispatch() { currentState->dispatch(this); }
void ResponseUnit::enRoute() { currentState->enRoute(this); }
void ResponseUnit::arrive() { currentState->arrive(this); }
void ResponseUnit::completeTask() { currentState->completeTask(this); }
void ResponseUnit::returnToStation() { currentState->returnToStation(this); }
void ResponseUnit::goOutOfService() { currentState->goOutOfService(this); }
void ResponseUnit::returnToService() { currentState->returnToService(this); }

void ResponseUnit::setState(UnitState* state) {
    currentState = state;
}

std::string ResponseUnit::getStateName() const {
    return currentState->getStateName();
}

void ResponseUnit::performDuty() {
    std::cout << callSign << " [" << getStateName() << "]: ";
    executeTask();
}

std::string ResponseUnit::getName() const { return callSign; }
int ResponseUnit::getPersonnelCount() const { return personnelCount; }
bool ResponseUnit::isAvailable() const { return currentState->isAvailableState(); }
