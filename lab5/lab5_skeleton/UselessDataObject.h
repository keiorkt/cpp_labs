#ifndef USELESSDATAOBJECT_H_
#define USELESSDATAOBJECT_H_

#include <iostream>
using std::ostream;

class UselessDataObject {
public:
	UselessDataObject();
	UselessDataObject(int value);
	int getValue() const;
	void setValue(int newValue);
	friend ostream& operator<<(ostream& out, const UselessDataObject& rhs);

private:
	int value;
};

#endif /* USELESSDATAOBJECT_H_ */
