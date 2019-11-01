#ifndef LINKEDLISTABSTRACTSEQUENTIALCONTAINER_H_
#define LINKEDLISTABSTRACTSEQUENTIALCONTAINER_H_

#include "AbstractSequentialContainer.h"
#include "UselessDataObject.h"

class LinkedListAbstractSequentialContainer : public AbstractSequentialContainer {
public:
	virtual ~LinkedListAbstractSequentialContainer();

	virtual void print(ostream& out) const override;
	virtual bool isEmpty() const override;
	virtual unsigned int getNumElements() const override;

protected:
	LinkedListAbstractSequentialContainer();
	LinkedListAbstractSequentialContainer(const LinkedListAbstractSequentialContainer& linkedListAbstractSequentialContainer);
	LinkedListAbstractSequentialContainer& operator=(const LinkedListAbstractSequentialContainer& rhs);

	const UselessDataObject& getElementAtIndex(unsigned int index) const;
	void insertAtIndex(const UselessDataObject& element, unsigned int index);
	UselessDataObject removeAtIndex(unsigned int index);

private:
	unsigned int numElements{0};

	class LinkedListNode {
		friend LinkedListAbstractSequentialContainer;
	private:
		LinkedListNode() {}
		LinkedListNode(UselessDataObject data, LinkedListNode* prev, LinkedListNode* next) : data{data}, prev{prev}, next{next} {}
		UselessDataObject data{0};
		LinkedListNode* prev{nullptr};
		LinkedListNode* next{nullptr};
	} *sentinel{nullptr};

	LinkedListNode* getNodeAtIndex(unsigned int index) const;
};

#endif /* LINKEDLISTABSTRACTSEQUENTIALCONTAINER_H_ */
