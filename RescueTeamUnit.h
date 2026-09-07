#ifndef RESCUETEAMUNIT_H
#define RESCUETEAMUNIT_H
#include "ResponseUnit.h"

class RescueTeamUnit : public ResponseUnit {
public:
    RescueTeamUnit(const std::string& callSign, int personnelCount);
protected:
    virtual void executeTask();
};
#endif
