#ifndef MEDICALSUPPORTDECORATOR_H
#define MEDICALSUPPORTDECORATOR_H
#include "UnitDecorator.h"

class MedicalSupportDecorator : public UnitDecorator {
public:
    explicit MedicalSupportDecorator(WorkElement* wrappedElement);
    virtual void performDuty();
    virtual std::string getName() const;
    virtual int getPersonnelCount() const;
};
#endif
