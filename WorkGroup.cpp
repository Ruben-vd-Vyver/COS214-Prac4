#include "WorkGroup.h"
#include "WorkIterator.h"
#include "DepthFirstIterator.h"
#include "AvailableUnitIterator.h"

#include <algorithm>
#include <iostream>

WorkGroup::WorkGroup(const std::string& groupName) : name(groupName) {}

WorkGroup::~WorkGroup() {
	for (std::size_t i=0;i<children.size(); i++) {
		delete children[i];
	}
	children.clear();
}

void WorkGroup::add(WorkElement* element) {
	if(element) {
		children.push_back(element);
	}
}

WorkElement* WorkGroup::remove(WorkElement* element) {
	std::vector<WorkElement*>::iterator it = std::find(children.begin(),
			children.end(), element);
	if(it!= children.end()) {
		children.erase(it);
		return element;
	}
	return 0;
}

void WorkGroup::performDuty() {
	std::cout<<name<<std::endl;
	for (std::size_t i=0; i<children.size();i++) {
		children[i]->performDuty();
	}
}

std::string WorkGroup::getName() const {
	return name;
}

int WorkGroup::getPersonnelCount() const {
	int total=0;
	for(std::size_t i=0;i<children.size();i++) {
		total+=children[i]->getPersonnelCount();
	}
	return total;
}

bool WorkGroup::isAvailable() const {
	return false;
}

void WorkGroup::appendToTraversal(std::vector<WorkElement*>& out) {
	out.push_back(this);
	for (std::size_t i=0;i<children.size();i++) {
		children[i]->appendToTraversal(out);
	}
}

WorkIterator* WorkGroup::createDepthFirstIterator() {
	return new DepthFirstIterator(this);
}

WorkIterator* WorkGroup::createAvailableUnitIterator() {
	return new AvailableUnitIterator(this);
}
