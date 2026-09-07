#include "AmbulanceUnit.h"
#include <iostream>

AmbulanceUnit::AmbulanceUnit(const std::string& cs, int p) : ResponseUnit(cs, p) {}

void AmbulanceUnit::executeTask() {
    std::cout << "triaging and transporting patients.\n";
}
