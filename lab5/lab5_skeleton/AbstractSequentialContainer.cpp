#include "AbstractSequentialContainer.h"

AbstractSequentialContainer::~AbstractSequentialContainer() {}

ostream& operator<< (ostream& out, const AbstractSequentialContainer& rhs) {
	rhs.print(out);
	return out;
}
