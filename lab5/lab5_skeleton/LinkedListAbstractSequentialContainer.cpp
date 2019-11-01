#include "LinkedListAbstractSequentialContainer.h"

/*******************************************************
 * Constructors, Destructors, and Assignment Operators *
 *******************************************************/

// TODO
LinkedListAbstractSequentialContainer::LinkedListAbstractSequentialContainer() /* : */ {
	sentinel = new LinkedListNode;
	sentinel->prev = sentinel->next = sentinel;
}

// TODO
LinkedListAbstractSequentialContainer::LinkedListAbstractSequentialContainer(const LinkedListAbstractSequentialContainer& linkedListAbstractContainer) /* : */ {
	this->numElements = linkedListAbstractContainer.numElements;
	this->sentinel = linkedListAbstractContainer.sentinel;
}

LinkedListAbstractSequentialContainer& LinkedListAbstractSequentialContainer::operator=(const LinkedListAbstractSequentialContainer& rhs) {
	if (this == &rhs) { return *this; }
	// TODO

	this->numElements = rhs.numElements;
	this->sentinel = rhs.sentinel;
	return *this;
}

LinkedListAbstractSequentialContainer::~LinkedListAbstractSequentialContainer() {
	// TODO
	for (LinkedListNode* current = sentinel->next;
			 current != sentinel;
		 	 current = current->next,
		 	 delete current->prev) {}
	delete sentinel;
	sentinel = nullptr;
}



/*******************************************
 * Abstract Sequential Container Overrides *
 *******************************************/

void LinkedListAbstractSequentialContainer::print(ostream& out) const {
	for (LinkedListNode* current{sentinel->next}; current != sentinel; current = current->next) {
		out << current->data << " ";
	}
}

bool LinkedListAbstractSequentialContainer::isEmpty() const {
	return (sentinel->next == sentinel); // TODO
}

// TODO
unsigned int LinkedListAbstractSequentialContainer::getNumElements() const {
	return numElements;
}



/***********************************
 * Linked List Protected Functions *
 ***********************************/

// Return sentinel garbage data if index out-of-range.
const UselessDataObject& LinkedListAbstractSequentialContainer::getElementAtIndex(unsigned int index) const {
	// TODO
	if (index < 0 || index > getNumElements()) {
		return sentinel->data;
	}

	return getNodeAtIndex(index)->data;
}

// Do nothing if index out-of-range.
// TODO
void LinkedListAbstractSequentialContainer::insertAtIndex(const UselessDataObject& element, unsigned int index) {
	if (index < 0 || index > getNumElements()) { return; }

	LinkedListNode* current = getNodeAtIndex(index);
	LinkedListNode* insert_node = new LinkedListNode{element, current->prev, current};
	insert_node->prev->next = insert_node;
	insert_node->next->prev = insert_node;
	++numElements;
}

// Don't remove any node, and return sentinel garbage data, if index out-of-range.
UselessDataObject LinkedListAbstractSequentialContainer::removeAtIndex(unsigned int index) {
	if (index < 0 || index > getNumElements()) {
		return sentinel->data;
	}

	LinkedListNode* current = getNodeAtIndex(index);

	if (current == sentinel) {
		return sentinel->data;
	}

	UselessDataObject obj{current->data};
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
	current = nullptr;
	--numElements;
	return obj;
}



/*********************************
 * Linked List Private Functions *
 *********************************/

// Return sentinel if index out-of-range.
// TODO
LinkedListAbstractSequentialContainer::LinkedListNode* LinkedListAbstractSequentialContainer::getNodeAtIndex(unsigned int index) const {
	if (index < 0 || index > getNumElements()) {
		return sentinel;
	}

	unsigned int idx = 0;
	for (LinkedListNode* current = sentinel->next; current != sentinel; current = current->next) {
		if (index == idx) {
			return current;
		}
		++idx;
	}

	return sentinel;
}
