/*
 * Person.cpp
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */


#include "Person.h"

void print_person(const Person& person) {
	cout << "Name: " << person.name << endl
		<< "Age: " << person.age << endl
		<< "Gender: " << (person.gender == MALE ? "Male" : "Female") << endl;
	if (person.ticket != nullptr) {
		cout << "Ticket: " << endl;
		print_ticket(*person.ticket);
	}
}

/*
 * Task 2 (Part II) - Dynamic allocation and deallocation of Person objects
 *
 * You are required to implement the following functions:
 *
 *   Person* create_person(string, int, Gender)
 * Dynamically create a Person who does not own a ticket based on the arguments provided.
 *
 *   Person* create_person_with_ticket(string, int, Gender, string, TicketClass)
 * Dynamically create a Person owning a ticket with the specified movie name and ticket class based on the arguments provided.
 *
 *   void destroy_person(Person*)
 * Deallocate the argument provided and should do nothing on nullptr.
 */

void initialize_person_by_pointer(Person* person, string name, int age, Gender gender) {
	person->name = name;
	person->age = age;
	person->gender = gender;
}

void initialize_person_with_ticket_by_pointer(Person* person, string name, int age, Gender gender, Ticket* ticket) {
	person->name = name;
	person->age = age;
	person->gender = gender;
	person->ticket = ticket;
}

Person* create_person(string name, int age, Gender gender) {
	Person* person = new Person;
	initialize_person_by_pointer(person, name, age, gender);
	return person;
}

Person* create_person_with_ticket(string name, int age, Gender gender, string movie, TicketClass ticket_class) {
	Ticket* ticket = new Ticket;
	initialize_ticket_by_pointer(ticket, movie, ticket_class);

	Person* person = new Person;
	initialize_person_with_ticket_by_pointer(person, name, age, gender, ticket);
	return person;
}

void destroy_person(Person* person) {
	if (person == nullptr) return;
	destroy_ticket(person->ticket);
	delete person;
	person = nullptr;
}
