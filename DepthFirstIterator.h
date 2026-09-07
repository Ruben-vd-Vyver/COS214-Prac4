#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "WorkIterator.h"
#include "WorkElement.h"
#include <vector>
#include <cstddef>

// ConcreteIterator: full "roll call" traversal - visits every element in the
// structure (groups and units) in pre-order. Takes an independent snapshot
// at construction time, so it is unaffected by later structural changes and
// is fully independent from any other iterator over the same root.
class DepthFirstIterator : public WorkIterator {
private:
    std::vector<WorkElement*> snapshot;
    std::size_t position;

public:
    explicit DepthFirstIterator(WorkElement* root);
    virtual bool hasNext() const;
    virtual WorkElement* next();
    virtual void first();
};

#endif
