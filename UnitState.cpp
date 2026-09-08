#include "UnitState.h"
#include "ResponseUnit.h"
#include <iostream>

void UnitState::dispatch(ResponseUnit* unit) { 
	rejectTransition(unit, "dispatch"); }
void UnitState::enRoute(ResponseUnit* unit) { 
	rejectTransition(unit, "confirm en route"); }
void UnitState::arrive(ResponseUnit* unit) { 
	rejectTransition(unit, "arrive on scene"); }
void UnitState::completeTask(ResponseUnit* unit) { 
	rejectTransition(unit, "complete task"); }
void UnitState::returnToStation(ResponseUnit* unit) { 
	rejectTransition(unit, "return to station"); }
void UnitState::goOutOfService(ResponseUnit* unit) { 
	rejectTransition(unit, "go out of service"); }
void UnitState::returnToService(ResponseUnit* unit) { 
	rejectTransition(unit, "return to service"); }

void UnitState::rejectTransition(ResponseUnit* unit, const std::string& action) const {
    std::cout << "  [INVALID] " << unit->getName() << " cannot " << action
              << " while " << getStateName() << ".\n";
}
