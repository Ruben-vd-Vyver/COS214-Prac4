#ifndef AVAILABLEUNITITERATOR_H
#define AVAILABLEUNITITERATOR_H

#include "WorkIterator.h"
#include "WorkElement.h"
#include <vector>
#include <cstddef>

// ConcreteIterator: a different selection rule and purpose from
// DepthFirstIterator - visits only the units that are currently available
// for tasking (isAvailable() == true). Groups never satisfy this filter, so
// only leaf response units (or decorated units) are ever returned.
class AvailableUnitIterator : public WorkIterator {
private:
    std::vector<WorkElement*> snapshot;
    std::size_t position;

public:
    explicit AvailableUnitIterator(WorkElement* root);
    virtual bool hasNext() const;
    virtual WorkElement* next();
    virtual void first();
};

#endif
