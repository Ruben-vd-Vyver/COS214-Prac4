#include "DepthFirstIterator.h"

DepthFirstIterator::DepthFirstIterator(WorkElement* root) : position(0) {
    if (root) {
        root->appendToTraversal(snapshot);
    }
}

bool DepthFirstIterator::hasNext() const {
    return position < snapshot.size();
}

WorkElement* DepthFirstIterator::next() {
    if (!hasNext()) return 0;
    return snapshot[position++];
}

void DepthFirstIterator::first() {
    position = 0;
}
