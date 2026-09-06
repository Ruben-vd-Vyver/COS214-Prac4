#ifndef WORKGROUP_H
#define WORKGROUP_H

#include "WorkElement.h"
#include <string>
#include <vector>

class WorkIterator;

// Composite. Represents any named group in the incident hierarchy - a
// Branch, a Division, a Strike Team, or the Incident itself - by nesting
// WorkGroup instances rather than adding a subclass per hierarchy level.
// Owns every child it holds: destroying a WorkGroup recursively destroys the
// entire subtree beneath it through the WorkElement virtual destructor.
class WorkGroup : public WorkElement {
private:
    std::string name;
    std::vector<WorkElement*> children;

public:
    explicit WorkGroup(const std::string& groupName);
    virtual ~WorkGroup();

    void add(WorkElement* element);
    // Detaches and returns the element without deleting it, transferring
    // ownership to the caller (used to move units between groups or to
    // re-wrap a unit in a decorator).
    WorkElement* remove(WorkElement* element);

    virtual void performDuty();
    virtual std::string getName() const;
    virtual int getPersonnelCount() const;
    virtual bool isAvailable() const;
    virtual void appendToTraversal(std::vector<WorkElement*>& out);

    WorkIterator* createDepthFirstIterator();
    WorkIterator* createAvailableUnitIterator();
};

#endif
