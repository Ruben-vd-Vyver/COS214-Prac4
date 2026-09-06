#include "MedicalSupportDecorator.h"
#include <iostream>

MedicalSupportDecorator::MedicalSupportDecorator(WorkElement* w) : UnitDecorator(w) {}

void MedicalSupportDecorator::performDuty() {
    UnitDecorator::performDuty();
    std::cout << "  + medical support: providing on-scene casualty care.\n";
}

std::string MedicalSupportDecorator::getName() const {
    return UnitDecorator::getName() + " [MEDIC]";
}

int MedicalSupportDecorator::getPersonnelCount() const {
    return UnitDecorator::getPersonnelCount() + 2; // attached medic pair
}
