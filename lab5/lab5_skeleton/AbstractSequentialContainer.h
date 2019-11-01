#ifndef ABSTRACTSEQUENTIALCONTAINER_H_
#define ABSTRACTSEQUENTIALCONTAINER_H_

#include <iostream>
using std::ostream;

#include "UselessDataObject.h"

class AbstractSequentialContainer {
public:
	virtual ~AbstractSequentialContainer();

	friend ostream& operator<<(ostream& out, const AbstractSequentialContainer& rhs);
	virtual void print(ostream& out) const = 0;
	virtual bool isEmpty() const = 0;
	virtual unsigned int getNumElements() const = 0;

	virtual const UselessDataObject& peek() const = 0;
	virtual void insertElement(const UselessDataObject& element) = 0;
	virtual UselessDataObject removeElement() = 0;
	virtual void removeAll(UselessDataObject data[]) = 0;
};

#endif /* ABSTRACTSEQUENTIALCONTAINER_H_ */
