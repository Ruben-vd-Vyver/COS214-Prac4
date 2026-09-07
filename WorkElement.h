#ifndef WORKELEMENT_H
#define WORKELEMENT_H

#include <string>
#include <vector>

// Component (Composite) / Component (Decorator).
// Every node in the hierarchy - a group, a plain unit, or a decorated unit -
// is used through this single abstraction.
class WorkElement {
public:
    virtual ~WorkElement() {}

    virtual void performDuty() = 0;
    virtual std::string getName() const = 0;
    virtual int getPersonnelCount() const = 0;
    virtual bool isAvailable() const = 0;

    // Traversal support hook. Concrete Iterators call this on the root to
    // build their own private snapshot vector, so client code and Iterators
    // never touch WorkGroup's internal container directly (rule: no exposing
    // internals merely to traverse). Leaves and decorators use the default
    // (push themselves); WorkGroup overrides it to recurse into children.
    virtual void appendToTraversal(std::vector<WorkElement*>& out) {
        out.push_back(this);
    }
};

#endif
