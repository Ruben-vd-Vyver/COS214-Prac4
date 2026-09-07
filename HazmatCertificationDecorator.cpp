#include "HazmatCertificationDecorator.h"
#include <iostream>

HazmatCertificationDecorator::HazmatCertificationDecorator(WorkElement* w) : UnitDecorator(w) {}

void HazmatCertificationDecorator::performDuty() {
    UnitDecorator::performDuty();
    std::cout << "  + hazmat certification: monitoring air quality and decontamination.\n";
}

std::string HazmatCertificationDecorator::getName() const {
    return UnitDecorator::getName() + " [HAZMAT]";
}
