#ifndef LINKEDLISTSTACK_H_
#define LINKEDLISTSTACK_H_

#include "LinkedListAbstractSequentialContainer.h"

class LinkedListStack : public LinkedListAbstractSequentialContainer {
public:
	LinkedListStack();
	LinkedListStack(const LinkedListStack& linkedListStack);
	LinkedListStack& operator=(const LinkedListStack& rhs);
	virtual ~LinkedListStack();

	virtual const UselessDataObject& peek() const override;
	virtual void insertElement(const UselessDataObject& element) override;
	virtual UselessDataObject removeElement() override;
	virtual void removeAll(UselessDataObject data[]) override;
};

#endif /* LINKEDLISTSTACK_H_ */
