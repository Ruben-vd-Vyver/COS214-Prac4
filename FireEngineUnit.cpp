#include "FireEngineUnit.h"
#include <iostream>

FireEngineUnit::FireEngineUnit(const std::string& cs, int p) : ResponseUnit(cs, p) {}

void FireEngineUnit::executeTask() {
    std::cout << "laying hose lines and applying water.\n";
}
