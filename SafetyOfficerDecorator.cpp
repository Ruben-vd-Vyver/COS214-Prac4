#include "SafetyOfficerDecorator.h"
#include <iostream>

SafetyOfficerDecorator::SafetyOfficerDecorator(WorkElement* w) : UnitDecorator(w) {}

void SafetyOfficerDecorator::performDuty() {
    UnitDecorator::performDuty();
    std::cout << "  + safety officer: monitoring scene safety and PPE compliance.\n";
}

std::string SafetyOfficerDecorator::getName() const {
    return UnitDecorator::getName() + " [SAFETY]";
}
