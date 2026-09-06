#include "RescueTeamUnit.h"
#include <iostream>

RescueTeamUnit::RescueTeamUnit(const std::string& cs, int p) : ResponseUnit(cs, p) {}

void RescueTeamUnit::executeTask() {
    std::cout << "conducting search and technical rescue.\n";
}
