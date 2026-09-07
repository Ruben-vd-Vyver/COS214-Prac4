#include "CommandLiaisonDecorator.h"
#include <iostream>

CommandLiaisonDecorator::CommandLiaisonDecorator(WorkElement* w) : UnitDecorator(w) {}

void CommandLiaisonDecorator::performDuty() {
    UnitDecorator::performDuty();
    std::cout << "  + command liaison: relaying status to Incident Command.\n";
}

std::string CommandLiaisonDecorator::getName() const {
    return UnitDecorator::getName() + " [LIAISON]";
}
