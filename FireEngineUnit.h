#ifndef FIREENGINEUNIT_H
#define FIREENGINEUNIT_H
#include "ResponseUnit.h"

class FireEngineUnit : public ResponseUnit {
public:
    FireEngineUnit(const std::string& callSign, int personnelCount);
protected:
    virtual void executeTask();
};
#endif
