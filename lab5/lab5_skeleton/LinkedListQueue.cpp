#include "LinkedListQueue.h"

LinkedListQueue::LinkedListQueue() {}

LinkedListQueue::LinkedListQueue(const LinkedListQueue& linkedListQueue) : LinkedListAbstractSequentialContainer(linkedListQueue) {}

LinkedListQueue& LinkedListQueue::operator=(const LinkedListQueue& rhs) {
	this->LinkedListAbstractSequentialContainer::operator=(rhs);
	return *this;
}

LinkedListQueue::~LinkedListQueue() {}

// TODO
const UselessDataObject& LinkedListQueue::peek() const {
	return getElementAtIndex(0);
}

// TODO
void LinkedListQueue::insertElement(const UselessDataObject& element) {
	insertAtIndex(element, getNumElements());
}

// TODO
UselessDataObject LinkedListQueue::removeElement() {
	return removeAtIndex(0);
}

// TODO
void LinkedListQueue::removeAll(UselessDataObject data[]) {
	int idx = 0;
	while (getNumElements() != 0) {
		data[idx] = removeElement();
		idx++;
	}
}
