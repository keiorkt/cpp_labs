# -*- MakeFile -*-

all: lab3

run: lab3_main
	./lab3_main

lab3: lab3_main.o Person.o Queue.o Ticket.o
	g++ lab3_main.o Person.o Queue.o Ticket.o -o lab3_main

lab3_main.o: lab3_main.cpp
	g++ -c lab3_main.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

Queue.o: Queue.cpp
	g++ -c Queue.cpp

Ticket.o: Ticket.cpp
	g++ -c Ticket.cpp

.PHONY: clean
clean:
	rm -f *.o lab3_main