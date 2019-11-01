#include "LinkedListStack.h"

// TODO
LinkedListStack::LinkedListStack() {}

// TODO
LinkedListStack::LinkedListStack(const LinkedListStack& linkedListStack) : LinkedListAbstractSequentialContainer(linkedListStack) {}

LinkedListStack& LinkedListStack::operator=(const LinkedListStack& rhs) {
	this->LinkedListAbstractSequentialContainer::operator=(rhs);
	return *this; // TODO
}

// TODO
LinkedListStack::~LinkedListStack() {}

// TODO
const UselessDataObject& LinkedListStack::peek() const {
	return getElementAtIndex(getNumElements()-1);
}

// TODO
void LinkedListStack::insertElement(const UselessDataObject& element) {
	insertAtIndex(element, getNumElements());
}

// TODO
UselessDataObject LinkedListStack::removeElement() {
	return removeAtIndex(getNumElements()-1);
}

// TODO
void LinkedListStack::removeAll(UselessDataObject data[]) {
	int idx = 0;
	while (getNumElements() != 0) {
		data[idx] = removeElement();
		idx++;
	}
}
