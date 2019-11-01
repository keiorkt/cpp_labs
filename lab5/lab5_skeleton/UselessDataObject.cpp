#include "UselessDataObject.h"

UselessDataObject::UselessDataObject() : value{0} {}

UselessDataObject::UselessDataObject(int value) : value{value} {}

int UselessDataObject::getValue() const { return value; }

void UselessDataObject::setValue(int newValue) { value = newValue; }

ostream& operator<<(ostream& out, const UselessDataObject& rhs) { return (out << rhs.value); }
