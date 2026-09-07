#ifndef AMBULANCEUNIT_H
#define AMBULANCEUNIT_H
#include "ResponseUnit.h"

class AmbulanceUnit : public ResponseUnit {
public:
    AmbulanceUnit(const std::string& callSign, int personnelCount);
protected:
    virtual void executeTask();
};
#endif
