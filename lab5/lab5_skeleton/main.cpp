#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <typeinfo>

#include "UselessDataObject.h"
#include "LinkedListQueue.h"
#include "LinkedListStack.h"

void constructorChecker() {
	stringstream ss;
	auto old_buf = cout.rdbuf(ss.rdbuf());
	cout.rdbuf(old_buf);

	cout << "Copy Constructor Test: " << endl;

	cout << "LinkedListQueue: ";
	LinkedListQueue linkedListQueue1;
	for (int i = 0; i < 100; ++i) {
		linkedListQueue1.insertElement(i);
	}
	LinkedListQueue linkedListQueue2{linkedListQueue1};
	old_buf = cout.rdbuf(ss.rdbuf());
	cout << linkedListQueue1;
	string linkedListQueue1_contents = ss.str();
	ss.str(string{});
	cout << linkedListQueue2;
	string linkedListQueue2_contents = ss.str();
	ss.str(string{});
	cout.rdbuf(old_buf);
	if (linkedListQueue1_contents == linkedListQueue2_contents) {
		cout << "Passed." << endl;
	}
	else {
		cout << "Failed." << endl;
	}

	cout << "LinkedListStack: ";
	LinkedListStack linkedListStack1;
	for (int i = 0; i < 100; ++i) {
		linkedListStack1.insertElement(i);
	}
	LinkedListStack linkedListStack2{linkedListStack1};
	old_buf = cout.rdbuf(ss.rdbuf());
	cout << linkedListStack1;
	string linkedListStack1_contents = ss.str();
	ss.str(string{});
	cout << linkedListStack2;
	string linkedListStack2_contents = ss.str();
	ss.str(string{});
	cout.rdbuf(old_buf);
	if (linkedListStack1_contents == linkedListStack2_contents) {
		cout << "Passed." << endl;
	}
	else {
		cout << "Failed." << endl;
	}

	/*
	cout << "ArrayQueue: ";
	ArrayQueue arrayQueue1;
	for (int i = 0; i < 100; ++i) {
		arrayQueue1.insertElement(i);
	}
	ArrayQueue arrayQueue2{arrayQueue1};
	old_buf = cout.rdbuf(ss.rdbuf());
	cout << arrayQueue1;
	string arrayQueue1_contents = ss.str();
	ss.str(string{});
	cout << arrayQueue2;
	string arrayQueue2_contents = ss.str();
	ss.str(string{});
	cout.rdbuf(old_buf);
	if (arrayQueue1_contents == arrayQueue2_contents) {
		cout << "Passed." << endl;
	}
	else {
		cout << "Failed." << endl;
	}

	cout << "ArrayStack: ";
	ArrayStack arrayStack1;
	for (int i = 0; i < 100; ++i) {
		arrayStack1.insertElement(i);
	}
	ArrayStack arrayStack2{arrayStack1};
	old_buf = cout.rdbuf(ss.rdbuf());
	cout << arrayStack1;
	string arrayStack1_contents = ss.str();
	ss.str(string{});
	cout << arrayStack2;
	string arrayStack2_contents = ss.str();
	ss.str(string{});
	cout.rdbuf(old_buf);
	if (arrayStack1_contents == arrayStack2_contents) {
		cout << "Passed." << endl;
	}
	else {
		cout << "Failed." << endl;
	}
	*/

	cout << endl;

	cout << "Copy Assignment Operator Test: " << endl;

	cout << "LinkedListQueue: ";
	LinkedListQueue linkedListQueue3;
	LinkedListQueue linkedListQueue4;
	for (int i = -100; i < 0; ++i) {
		linkedListQueue3.insertElement(i);
	}
	linkedListQueue3 = linkedListQueue4;
	old_buf = cout.rdbuf(ss.rdbuf());
	cout << linkedListQueue3;
	string linkedListQueue3_contents = ss.str();
	ss.str(string{});
	cout << linkedListQueue4;
	string linkedListQueue4_contents = ss.str();
	ss.str(string{});
	cout.rdbuf(old_buf);
	if (linkedListQueue3_contents == linkedListQueue4_contents) {
		cout << "Passed." << endl;
	}
	else {
		cout << "Failed." << endl;
	}

	cout << "LinkedListStack: ";
	LinkedListStack linkedListStack3;
	LinkedListStack linkedListStack4;
	for (int i = -100; i < 0; ++i) {
		linkedListStack3.insertElement(i);
	}
	linkedListStack3 = linkedListStack4;
	old_buf = cout.rdbuf(ss.rdbuf());
	cout << linkedListStack3;
	string linkedListStack3_contents = ss.str();
	ss.str(string{});
	cout << linkedListStack4;
	string linkedListStack4_contents = ss.str();
	ss.str(string{});
	cout.rdbuf(old_buf);
	if (linkedListStack3_contents == linkedListStack4_contents) {
		cout << "Passed." << endl;
	}
	else {
		cout << "Failed." << endl;
	}

	/*
	cout << "ArrayQueue: ";
	ArrayQueue arrayQueue3;
	ArrayQueue arrayQueue4;
	for (int i = -100; i < 0; ++i) {
		arrayQueue3.insertElement(i);
	}
	arrayQueue3 = arrayQueue4;
	old_buf = cout.rdbuf(ss.rdbuf());
	cout << arrayQueue3;
	string arrayQueue3_contents = ss.str();
	ss.str(string{});
	cout << arrayQueue4;
	string arrayQueue4_contents = ss.str();
	ss.str(string{});
	cout.rdbuf(old_buf);
	if (arrayQueue3_contents == arrayQueue4_contents) {
		cout << "Passed." << endl;
	}
	else {
		cout << "Failed." << endl;
	}

	cout << "ArrayStack: ";
	ArrayStack arrayStack3;
	ArrayStack arrayStack4;
	for (int i = -100; i < 0; ++i) {
		arrayStack3.insertElement(i);
	}
	arrayStack3 = arrayStack4;
	old_buf = cout.rdbuf(ss.rdbuf());
	cout << arrayStack3;
	string arrayStack3_contents = ss.str();
	ss.str(string{});
	cout << arrayStack4;
	string arrayStack4_contents = ss.str();
	ss.str(string{});
	cout.rdbuf(old_buf);
	if (arrayStack3_contents == arrayStack4_contents) {
		cout << "Passed." << endl;
	}
	else {
		cout << "Failed." << endl;
	}
	*/
}



// Polymorphism. selectedContainer points to either LinkedListQueue or LinkedListStack.
void innerMenu(AbstractSequentialContainer& selectedContainer) {
	char operation;
	int value;
	UselessDataObject element;
	UselessDataObject* data;
	unsigned int numData;
	int N;

	do {
		cout << "\n"
			 << "1. Print numElements\n"
			 << "2. Print All\n"
			 << "3. Peek\n"
			 << "4. Insert\n"
			 << "5. Remove\n"
			 << "6. Remove All\n"
			 << "7. Quick Insert sequentially, [0, N). Duplicates allowed.\n"
			 << "B: Back to Container Type Selection (All data saved)\n"
			 << "\n"
			 << "Please select an operation: ";
		cin >> operation;

		switch (operation) {
		case '1':
			cout << (typeid(selectedContainer)).name() << " numElements == " << selectedContainer.getNumElements() << endl;
			break;

		case '2':
			if (selectedContainer.getNumElements() == 0) {
				cout << (typeid(selectedContainer)).name() << " is empty!" << endl;
			}
			else {
				cout << (typeid(selectedContainer)).name() << "\n"
					 << selectedContainer
					 << endl;
			}
			break;

		case '3':
			if (selectedContainer.getNumElements() == 0) {
				cout << (typeid(selectedContainer)).name() << " is empty!" << endl;
			}
			else {
				cout << "Peek: " << selectedContainer.peek() << endl;
			}
			break;

		case '4':
			cout << "Element: ";
			cin >> value;
			element = UselessDataObject{value};
			selectedContainer.insertElement(element);
			break;

		case '5':
			if (selectedContainer.getNumElements() == 0) {
				cout << (typeid(selectedContainer)).name() << " is empty!" << endl;
			}
			else {
				cout << "Remove: " << selectedContainer.removeElement() << endl;
			}
			break;

		case '6':
			if (selectedContainer.getNumElements() == 0) {
				cout << (typeid(selectedContainer)).name() << " is empty!" << endl;
			}
			else {
				numData = selectedContainer.getNumElements();
				data = new UselessDataObject[numData];
				selectedContainer.removeAll(data);
				cout << "Remove All: ";
				for (unsigned int i{0}; i < numData; ++i) {
					cout << data[i] << " ";
				}
				cout << endl;
				delete[] data;
			}
			break;

		case '7':
			cout << "N: ";
			cin >> N;
			for (int i{0}; i < N; ++i) {
				element = UselessDataObject{i};
				selectedContainer.insertElement(element);
			}
			break;

		case 'b':
		case 'B':
			return;

		default:
			cout << "Invalid input." << endl;
			break;
		}
	} while ((operation != 'b') && (operation != 'B'));
}

int main() {
	LinkedListQueue linkedListQueue;
	LinkedListStack linkedListStack;
	//ArrayQueue arrayQueue;
	//ArrayStack arrayStack;
	cout << "One empty LinkedListQueue and one empty LinkedListStack have been created for you to test." << endl;

	char selection;
	do {
		cout << "\n"
			 << "1. LinkedListQueue\n"
			 << "2. LinkedListStack\n"
			 //<< "3. ArrayQueue\n"
			 //<< "4. ArrayStack\n"
			 << "Q: Quit\n"
			 << "\n"
			 << "Please select the Container Type: ";
		cin >> selection;

		switch (selection) {
		case '1':
			innerMenu(linkedListQueue);
			break;

		case '2':
			innerMenu(linkedListStack);
			break;

		case '3':
			//innerMenu(arrayQueue);
			break;

		case '4':
			//innerMenu(arrayStack);
			break;

		case 'q':
		case 'Q':
			break;

		default:
			cout << "Invalid input." << endl;
			break;
		}
	} while ((selection != 'q') && (selection != 'Q'));

	cout << "\n\n\n";
	constructorChecker();

	return 0;
}
