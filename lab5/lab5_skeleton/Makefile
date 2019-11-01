# -*- MakeFile -*-

all: lab5

run: lab5_main
	./lab5_main

debug: lab5_main
	./lab5_main

lab5: AbstractSequentialContainer.o LinkedListAbstractSequentialContainer.o LinkedListQueue.o LinkedListStack.o UselessDataObject.o main.o
	g++ -std=c++11 AbstractSequentialContainer.o LinkedListAbstractSequentialContainer.o LinkedListQueue.o LinkedListStack.o UselessDataObject.o main.o -o lab5_main

AbstractSequentialContainer.o: AbstractSequentialContainer.cpp
	g++ -std=c++11 -c AbstractSequentialContainer.cpp

LinkedListAbstractSequentialContainer.o: LinkedListAbstractSequentialContainer.cpp
	g++ -std=c++11 -c LinkedListAbstractSequentialContainer.cpp

LinkedListQueue.o: LinkedListQueue.cpp
	g++ -std=c++11 -c LinkedListQueue.cpp

LinkedListStack.o: LinkedListStack.cpp
	g++ -std=c++11 -c LinkedListStack.cpp


UselessDataObject.o: UselessDataObject.cpp
	g++ -std=c++11 -c UselessDataObject.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

.PHONY: clean
clean:
	rm -f *.o lab5_main
