#include "AvailableUnitIterator.h"

AvailableUnitIterator::AvailableUnitIterator(WorkElement* root) : position(0) {
    std::vector<WorkElement*> all;
    if (root) {
        root->appendToTraversal(all);
    }
    for (std::size_t i = 0; i < all.size(); ++i) {
        if (all[i]->isAvailable()) {
            snapshot.push_back(all[i]);
        }
    }
}

bool AvailableUnitIterator::hasNext() const {
    return position < snapshot.size();
}

WorkElement* AvailableUnitIterator::next() {
    if (!hasNext()) return 0;
    return snapshot[position++];
}

void AvailableUnitIterator::first() {
    position = 0;
}
