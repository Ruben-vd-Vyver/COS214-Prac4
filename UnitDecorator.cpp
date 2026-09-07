#include "UnitDecorator.h"

UnitDecorator::UnitDecorator(WorkElement* wrappedElement) : wrapped(wrappedElement) {}

UnitDecorator::~UnitDecorator() {
    delete wrapped;
}

void UnitDecorator::performDuty() { wrapped->performDuty(); }
std::string UnitDecorator::getName() const { return wrapped->getName(); }
int UnitDecorator::getPersonnelCount() const { return wrapped->getPersonnelCount(); }
bool UnitDecorator::isAvailable() const { return wrapped->isAvailable(); }
