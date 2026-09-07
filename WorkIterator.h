#ifndef WORKITERATOR_H
#define WORKITERATOR_H

class WorkElement;

// Iterator role.
class WorkIterator {
public:
    virtual ~WorkIterator() {}
    virtual bool hasNext() const = 0;
    virtual WorkElement* next() = 0;
    virtual void first() = 0;
};

#endif
