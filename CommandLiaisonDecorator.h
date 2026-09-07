#ifndef COMMANDLIAISONDECORATOR_H
#define COMMANDLIAISONDECORATOR_H
#include "UnitDecorator.h"

class CommandLiaisonDecorator : public UnitDecorator {
public:
    explicit CommandLiaisonDecorator(WorkElement* wrappedElement);
    virtual void performDuty();
    virtual std::string getName() const;
};
#endif
