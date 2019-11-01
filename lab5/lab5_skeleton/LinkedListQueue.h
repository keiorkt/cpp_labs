#ifndef LINKEDLISTQUEUE_H_
#define LINKEDLISTQUEUE_H_

#include "LinkedListAbstractSequentialContainer.h"

class LinkedListQueue : public LinkedListAbstractSequentialContainer {
public:
	LinkedListQueue();
	LinkedListQueue(const LinkedListQueue& linkedListQueue);
	LinkedListQueue& operator=(const LinkedListQueue& rhs);
	virtual ~LinkedListQueue();

	virtual const UselessDataObject& peek() const override;
	virtual void insertElement(const UselessDataObject& element) override;
	virtual UselessDataObject removeElement() override;
	virtual void removeAll(UselessDataObject data[]) override;
};

#endif /* LINKEDLISTQUEUE_H_ */
