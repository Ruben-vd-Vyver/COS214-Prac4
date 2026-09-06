#ifndef SAFETYOFFICERDECORATOR_H
#define SAFETYOFFICERDECORATOR_H
#include "UnitDecorator.h"

class SafetyOfficerDecorator : public UnitDecorator {
public:
    explicit SafetyOfficerDecorator(WorkElement* wrappedElement);
    virtual void performDuty();
    virtual std::string getName() const;
};
#endif
