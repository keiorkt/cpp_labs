# -*- MakeFile -*-

all: lab3

run: lab3_main
	./lab3_main > result.txt

lab3: lab3_main.o Person.o Queue.o Ticket.o Queue_Linked_List.o
	g++ lab3_main.o Person.o Queue.o Ticket.o Queue_Linked_List.o -o lab3_main

lab3_main.o: lab3_main.cpp
	g++ -c lab3_main.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

Queue.o: Queue.cpp
	g++ -c Queue.cpp

Ticket.o: Ticket.cpp
	g++ -c Ticket.cpp

Queue_Linked_List.o: Queue_Linked_List.cpp
	g++ -c Queue_Linked_List.cpp

.PHONY: clean
clean:
	rm -f *.o lab3_main result.txt
