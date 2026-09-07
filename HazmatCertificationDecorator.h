#ifndef HAZMATCERTIFICATIONDECORATOR_H
#define HAZMATCERTIFICATIONDECORATOR_H
#include "UnitDecorator.h"

class HazmatCertificationDecorator : public UnitDecorator {
public:
    explicit HazmatCertificationDecorator(WorkElement* wrappedElement);
    virtual void performDuty();
    virtual std::string getName() const;
};
#endif
