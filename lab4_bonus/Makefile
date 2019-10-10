# -*- MakeFile -*-

all: lab4

run: lab4_main
	./lab4_main > result.txt

debug: lab4_main
	./lab4_main

lab4: course.o grader.o linked_list.o
	g++ -std=c++14 course.o grader.o linked_list.o -o lab4_main

course.o: course.cpp
	g++ -std=c++14 -c course.cpp

grader.o: grader.cpp
	g++ -std=c++14 -c grader.cpp

linked_list.o: linked_list.cpp
	g++ -std=c++14 -c linked_list.cpp

.PHONY: clean
clean:
	rm -f *.o lab4_main result.txt
